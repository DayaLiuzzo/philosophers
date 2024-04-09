/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:08:08 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/09 20:22:10 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int     create_thread(t_program *program, pthread_mutex_t *forks)
{
	pthread_t supervisor;
	int i;

	if (pthread_create(&supervisor, NULL, &supervise, program->philos) != 0)
		destroy_all("Thread creation error", program, forks);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
			&program->philos[i]) != 0)
			destroy_all("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(supervisor, NULL) != 0)
		destroy_all("Thread creation error", program, forks);
	while (i < program->philos[0].num_of_philos)
	{
		if(pthread_join(program->philos[i].thread, NULL) != 0)
			destroy_all("Thread creation error", program, forks);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:08:08 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/03 18:16:55 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    create_thread(t_program *program, pthread_mutex_t *forks)
{
	int i = 0;
	pthread_t supervisor;

	if (pthread_create(&supervisor, NULL, &supervise, program->philos) != 0)
		destroy_all("Thread creation error");
	while (i != program->philos->num_of_philos)
	{
		pthread_create(program->philos[i].thread, NULL, philo_routine,
			(void *)&program->philos[i]);
		i++;
	}
	if (pthread_join(supervisor, NULL) != 0)
		destroy_all("Thread join error", program, forks);
	i = 0;
	while (i != program->philos->num_of_philos)
	{
		pthread_join(program->philos[i].thread, NULL);
		i++;
	}
	return (NULL);
}
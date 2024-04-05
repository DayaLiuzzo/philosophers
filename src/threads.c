/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:08:08 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/05 17:45:51 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// destroy_all(char *msg, pthread_mutex_t *forks, t_program *program)
// {
// 	printf("%s\n", msg);
// 	int i;
// 	i = 0;
	
// 	while( )
// 	{
		
// 	}
// 	pthread_mutex_destroy()
// }

int     create_thread(t_program *program, pthread_mutex_t *forks)
{
	int i = 0;
	pthread_t supervisor;
	(void)forks;
	if (pthread_create(&supervisor, NULL, &supervise, program->philos) != 0)
		printf("ERREUR\n");
		// destroy_all("Thread creation error", forks, program);
	while (i < program->philos[0].num_of_philos)
	{
		pthread_create(&program->philos[i].thread, NULL, &philo_routine,
			&program->philos[i]);
		i++;
	}
	if (pthread_join(supervisor, NULL) != 0)
		printf("ERREUR\n");
		// destroy_all("Thread join error", forks, program);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		pthread_join(program->philos[i].thread, NULL);
		i++;
	}
	return (0);
}

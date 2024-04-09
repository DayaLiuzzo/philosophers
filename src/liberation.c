/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:45:36 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/09 20:10:02 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	liberation(char *msg)
{
	if (msg)
		printf("%s\n", msg);
	exit(1);
}

void destroy_all(char *msg, t_program *program, pthread_mutex_t *forks)
{
	int i;
	i = 0;

	if(msg)
	{
		write(2, msg, strlen(msg));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	while(i < program->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:15:09 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/24 14:16:25 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_msg(char *msg, int id, t_philosophers *philosopher)
{
	size_t	time;

	pthread_mutex_lock(philosopher->write_lock);
	time = current_time() - philosopher->start_time;
	if (!dead_check(philosopher))
		printf("%zu %i %s\n", time, id, msg);
	pthread_mutex_unlock(philosopher->write_lock);
}

void	print_dead(char *msg, int id, t_philosophers *philosopher)
{
	size_t	time;

	pthread_mutex_lock(philosopher->write_lock);
	time = current_time() - philosopher->start_time;
	printf("%zu %i %s\n", time, id, msg);
	pthread_mutex_unlock(philosopher->write_lock);
}

void	print_msg_eat(int id, t_philosophers *philosopher)
{
	size_t	time;

	pthread_mutex_lock(philosopher->write_lock);
	time = current_time() - philosopher->start_time;
	if (!dead_check(philosopher))
	{
		printf("%zu %i has taken a fork\n", time, id);
		printf("%zu %i is eating\n", time, id);
	}
	pthread_mutex_unlock(philosopher->write_lock);
}

void	think(t_philosophers *philosopher)
{
	print_msg("is thinking", philosopher->id, philosopher);
}

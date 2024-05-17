/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:15:09 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/05/17 15:21:39 by dliuzzo          ###   ########.fr       */
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

void	think(t_philosophers *philosopher)
{
	print_msg("is thinking", philosopher->id, philosopher);
	if (philosopher->num_of_philos % 2 != 0)
	{
		if (!((philosopher->time_to_eat * 2) < philosopher->time_to_sleep))
			ft_usleep2(philosopher->time_to_eat, philosopher);
	}
}

void	pick_fork(t_philosophers *philosopher)
{
	if (philosopher->id % 2 == 0)
	{
		pthread_mutex_lock(philosopher->l_fork);
		print_msg("has taken a fork", philosopher->id, philosopher);
		pthread_mutex_lock(philosopher->r_fork);
		print_msg("has taken a fork", philosopher->id, philosopher);
	}
	else
	{
		pthread_mutex_lock(philosopher->r_fork);
		print_msg("has taken a fork", philosopher->id, philosopher);
		pthread_mutex_lock(philosopher->l_fork);
		print_msg("has taken a fork", philosopher->id, philosopher);
	}
}

void	drop_fork(t_philosophers *philosopher)
{
	if (philosopher->id % 2 == 0)
	{
		pthread_mutex_unlock(philosopher->r_fork);
		pthread_mutex_unlock(philosopher->l_fork);
	}
	else
	{
		pthread_mutex_unlock(philosopher->l_fork);
		pthread_mutex_unlock(philosopher->r_fork);
	}
}

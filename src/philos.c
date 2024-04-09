/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:09:21 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/09 20:08:17 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void	think(t_philosophers *philosopher)
{
	print_msg("Thinks", philosopher->id, philosopher);
}

void	ft_sleep(t_philosophers *philosopher)
{
	print_msg("Sleeps", philosopher->id, philosopher);
	ft_usleep(philosopher->time_to_sleep);
}
int ft_usleep(size_t time)
{
	size_t start;

	start = current_time();
	while((current_time() - start) < time)
		usleep(500);
	return(0);
}
void	*philo_routine(void *arg)
{
	t_philosophers *philosopher;

	philosopher = (t_philosophers *)arg;
	if(philosopher->id % 2 == 0)
		ft_usleep(1);
	while (!dead_check(philosopher))
	{
		eat(philosopher);
		ft_sleep(philosopher);
		think(philosopher);
		
	}
	return (arg);
}

void eat(t_philosophers *philosopher)
{
	pthread_mutex_lock(philosopher->r_fork);
	print_msg("has taken a right fork", philosopher->id, philosopher);
	if(philosopher->num_of_philos == 1)
	{
		ft_usleep(philosopher->time_to_die);
		pthread_mutex_unlock(philosopher->r_fork);
		return;
	}
	pthread_mutex_lock(philosopher->l_fork);
	print_msg("has taken a left fork", philosopher->id, philosopher);
	philosopher->eating = 1;
	print_msg("is eating", philosopher->id, philosopher);
	pthread_mutex_lock(philosopher->meal_lock);
	philosopher->last_meal = current_time();
	philosopher->meals_eaten++;
	pthread_mutex_unlock(philosopher->meal_lock);
	ft_usleep(philosopher->time_to_eat);
	philosopher->eating = 0;
	pthread_mutex_unlock(philosopher->l_fork);
	pthread_mutex_unlock(philosopher->r_fork);
}
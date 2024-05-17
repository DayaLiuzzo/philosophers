/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:09:21 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/05/17 15:21:22 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(t_philosophers *philosopher)
{
	print_msg("is sleeping", philosopher->id, philosopher);
	ft_usleep2(philosopher->time_to_sleep, philosopher);
}

int	ft_usleep(size_t time)
{
	size_t	start;

	start = current_time();
	while ((current_time() - start) < time)
		usleep(50);
	return (0);
}

int	ft_usleep2(size_t time, t_philosophers *philo)
{
	size_t	start;

	start = current_time();
	while ((current_time() - start) < time && dead_check(philo) == 0)
		usleep(75);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philosophers	*philosopher;

	philosopher = (t_philosophers *)arg;
	if (philosopher->id % 2 == 0)
		ft_usleep2(1, philosopher);
	while (!dead_check(philosopher))
	{
		eat(philosopher);
		ft_sleep(philosopher);
		think(philosopher);
	}
	return (arg);
}

void	eat(t_philosophers *philosopher)
{
	if (philosopher->num_of_philos == 1)
	{
		pthread_mutex_lock(philosopher->r_fork);
		print_msg("has taken a fork", philosopher->id, philosopher);
		ft_usleep(philosopher->time_to_die);
		pthread_mutex_unlock(philosopher->r_fork);
		return ;
	}
	pick_fork(philosopher);
	pthread_mutex_lock(philosopher->meal_lock);
	philosopher->last_meal = current_time();
	print_msg("is eating", philosopher->id, philosopher);
	philosopher->eating = 1;
	pthread_mutex_unlock(philosopher->meal_lock);
	ft_usleep2(philosopher->time_to_eat, philosopher);
	pthread_mutex_lock(philosopher->meal_lock);
	philosopher->meals_eaten++;
	philosopher->eating = 0;
	pthread_mutex_unlock(philosopher->meal_lock);
	drop_fork(philosopher);
}

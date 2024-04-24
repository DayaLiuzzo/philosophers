/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:09:21 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/24 14:16:14 by dliuzzo          ###   ########.fr       */
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
		usleep(50);
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
	pthread_mutex_lock(philosopher->r_fork);
	print_msg("has taken a fork", philosopher->id, philosopher);
	if (philosopher->num_of_philos == 1)
	{
		ft_usleep(philosopher->time_to_die);
		pthread_mutex_unlock(philosopher->r_fork);
		return ;
	}
	pthread_mutex_lock(philosopher->l_fork);
	print_msg_eat(philosopher->id, philosopher);
	philosopher->eating = 1;
	pthread_mutex_lock(philosopher->meal_lock);
	philosopher->last_meal = current_time();
	philosopher->meals_eaten++;
	pthread_mutex_unlock(philosopher->meal_lock);
	ft_usleep2(philosopher->time_to_eat, philosopher);
	philosopher->eating = 0;
	pthread_mutex_unlock(philosopher->r_fork);
	pthread_mutex_unlock(philosopher->l_fork);
}

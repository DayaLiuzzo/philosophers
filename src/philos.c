/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:09:21 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/05 19:08:04 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void	think(t_philosophers *philosopher)
{
	print_msg("Thinks hard but doesnt think long", philosopher->id, philosopher);
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
	int i;

	i = 0;
	philosopher = (t_philosophers *)arg;
	if(philosopher->id % 2 == 0)
		ft_usleep(1);
	while (!dead_check(philosopher))
	{
		eat(philosopher);
		think(philosopher);
		ft_sleep(philosopher);
		
	}
	return (NULL);
}

void eat(t_philosophers *philosopher)
{

	pthread_mutex_lock(philosopher->r_fork);
	pthread_mutex_lock(philosopher->l_fork);
	philosopher->eating = 1;
	print_msg("is eating", philosopher->id, philosopher);
	pthread_mutex_lock(philosopher->meal_lock);
	philosopher->last_meal = current_time();
	philosopher->meals_eaten += 1;
	pthread_mutex_unlock(philosopher->meal_lock);	
	ft_usleep(philosopher->time_to_eat);
	pthread_mutex_unlock(philosopher->l_fork);
	pthread_mutex_unlock(philosopher->r_fork);
}
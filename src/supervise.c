/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:06:57 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/22 12:59:04 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_if_all_ate(t_philosophers *philosophers)
{
	int	i;
	int	full;

	i = 0;
	full = 0;
	if (philosophers[0].num_times_to_eat == -1)
		return (0);
	while (i < philosophers[0].num_of_philos)
	{
		pthread_mutex_lock(philosophers[i].meal_lock);
		if (philosophers[i].meals_eaten >= philosophers[i].num_times_to_eat)
			full++;
		pthread_mutex_unlock(philosophers[i].meal_lock);
		i++;
	}
	if (full == philosophers[0].num_of_philos)
	{
		pthread_mutex_lock(philosophers[0].dead_lock);
		*philosophers->dead = 1;
		pthread_mutex_unlock(philosophers[0].dead_lock);
		return (1);
	}
	return (0);
}

int	is_dead(t_philosophers *philosopher, size_t time_to_die)
{
	pthread_mutex_lock(philosopher->meal_lock);
	if (current_time() - philosopher->last_meal >= time_to_die
		&& philosopher->eating == 0)
		return (pthread_mutex_unlock(philosopher->meal_lock), 1);
	pthread_mutex_unlock(philosopher->meal_lock);
	return (0);
}

int	check_if_dead(t_philosophers *philosophers)
{
	int	i;

	i = 0;
	while (i < philosophers[0].num_of_philos)
	{
		if (is_dead(&philosophers[i], philosophers[i].time_to_die))
		{
			pthread_mutex_lock(philosophers[0].dead_lock);
			*philosophers->dead = 1;
			pthread_mutex_unlock(philosophers[0].dead_lock);
			print_dead("died", philosophers[i].id, &philosophers[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*supervise(void	*arg)
{
	t_philosophers	*philosophers;

	philosophers = (t_philosophers *)arg;
	while (1)
	{
		if ((check_if_dead(philosophers)) == 1
			|| (check_if_all_ate(philosophers) == 1))
			break ;
	}
	return (arg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:06:57 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/05 16:59:53 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_if_all_ate(t_philosophers *philosophers)
{
	int i;
	int full;

	i = 0;
	full = 0;
	pthread_mutex_lock(philosophers->meal_lock);
	while(i <= philosophers[0].num_of_philos)
	{
		if(philosophers[i].meals_eaten >= philosophers[0].num_times_to_eat)
			full++;
		i++;
	}
	pthread_mutex_unlock(philosophers->meal_lock);
	if(full == philosophers[0].num_of_philos)
	{
		pthread_mutex_lock(philosophers->dead_lock);
		*philosophers->dead = 1;
		pthread_mutex_unlock(philosophers->dead_lock);
		return(1);
	}
    return(0);   
}

int is_dead(t_philosophers *philosopher)
{
	pthread_mutex_lock(philosopher->meal_lock);
	if(current_time() - philosopher->last_meal >= philosopher->time_to_die && philosopher->eating == 0) 
    {
		pthread_mutex_unlock(philosopher->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philosopher->meal_lock);
    return(0);   
}
int check_if_dead(t_philosophers *philosophers)
{
    int i;

    i = 0;
    while(i < philosophers->num_of_philos)
    {
        if(is_dead(&philosophers[i]))
		{
			pthread_mutex_lock(philosophers->dead_lock);
			*philosophers->dead = 1;
			pthread_mutex_unlock(philosophers->dead_lock);
			print_msg("DIED", philosophers[i].id, &philosophers[i]);
			return (1);
		}
		i++;
    }
	return (0);
}

void	*supervise(void *arg)
{
	t_philosophers *philosophers;

	philosophers = (t_philosophers *)arg;
	while (1)
	{
		printf("LOL");
		if ((check_if_dead(philosophers)) || (check_if_all_ate(philosophers)))
			break ;
	}
	return (philosophers);
}
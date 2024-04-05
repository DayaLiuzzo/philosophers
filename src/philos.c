/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:09:21 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/05 17:16:01 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	while (dead_check(philosopher))
	{
		print_msg("lol", philosopher->id, philosopher);
		// eat(philosopher);
		// think(philosopher);
		// usleep(philosopher.time_to_sleep);
		
	}
	return (NULL);
}
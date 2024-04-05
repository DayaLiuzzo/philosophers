/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:09:21 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/05 15:35:27 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *arg)
{
	t_philosophers philosopher;
	int i;

	i = 0;
	philosopher = *(t_philosophers *)arg;
	while (dead_check(philosopher))
	{
		eat(philosopher);
		think(philosopher);
		usleep(philosopher.time_to_sleep);
		
	}
	return (NULL);
}
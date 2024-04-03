/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:09:21 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/03 18:15:14 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *arg)
{
	t_philosophers philosopher;
	int i;

	i = 0;
	philosopher = *(t_philosophers *)arg;
	while (*philosopher.dead != 1)
	{
		sleep(1);
		if (i == 0)
		{
			printf("%i is thinking\n", philosopher.id);
			i = 1;
		}
	}
	return (NULL);
}
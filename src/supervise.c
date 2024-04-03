/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:06:57 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/03 18:34:10 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int is_dead(t_philosophers)
{
    
    return(0);   
}
int check_if_dead(t_philosophers *philosopher)
{
    int i;

    i = 0;
    while(i < philosopher->num_of_philos)
    {
        if(is_dead(philsopher[i]))
    }
    
}

void	*supervise(void *arg)
{
	t_philosophers *philosophers;

	philosophers = (t_philosophers *)arg;
	while (1)
	{
		if ((check_if_dead(philosophers)) || (check_if_all_ate(philosophers)))
			break ;
	}
	return (philosophers);
}
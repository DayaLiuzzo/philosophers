/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:51:03 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/23 15:40:25 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void *new_thread(void *arg)
{
	t_program	program;
	program = *(t_program *)arg;
	printf("time ----> %ld\n",program.philos[1].start_time);
	printf("id ----> %i\n",program.philos[5].id);
	return NULL;
	
}

int	main(int ac, char **av)
{
	t_program program;
	t_philosophers philos[200];
	pthread_mutex_t	forks[200];

	check_args(ac, av);
	init_program(&program, philos);
	init_fork(forks, ft_checkifint(av[1]));
	init_philos(&program, philos, forks, av);
	pthread_create(&philos[0].thread, NULL, new_thread, (void *)&program);
	pthread_join(philos[0].thread, NULL);
	return (0);
}

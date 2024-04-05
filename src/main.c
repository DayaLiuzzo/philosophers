/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:51:03 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/05 17:21:45 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_program		program;
	t_philosophers	philos[200];
	pthread_mutex_t	forks[200];

	check_args(ac, av);
	init_program(&program, philos);
	init_fork(forks, ft_checkifint(av[1]));
	init_philos(&program, philos, forks, av);
	create_thread(&program, forks);
	return (0);
}

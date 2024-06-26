/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:51:03 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/05/17 14:54:52 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_program		program;
	t_philosophers	philos[300];
	pthread_mutex_t	forks[300];

	if (check_args(ac, av) != 0)
		return (1);
	init_program(&program, philos);
	init_fork(forks, ft_checkifint(av[1]));
	init_philos(&program, philos, forks, av);
	create_thread(&program, forks);
	destroy_all("", &program, forks);
	return (0);
}

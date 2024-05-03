/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:10:52 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/05/03 17:09:44 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_program(t_program *program, t_philosophers *philos)
{
	program->isdead = 0;
	program->philos = philos;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}

void	init_fork(pthread_mutex_t *forks, int philo_nb)
{
	int	i;

	i = 0;
	while (i < philo_nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_philos_data(t_philosophers *philos, char **av)
{
	philos->time_to_die = ft_checkifint(av[2]);
	philos->time_to_eat = ft_checkifint(av[3]);
	philos->time_to_sleep = ft_checkifint(av[4]);
	philos->num_of_philos = ft_checkifint(av[1]);
	if (av[5])
		philos->num_times_to_eat = ft_checkifint(av[5]);
	else
		philos->num_times_to_eat = -1;
}

void	init_philos(t_program *program, t_philosophers *philos,
		pthread_mutex_t *forks, char **av)
{
	int		i;
	size_t	time;

	time = current_time();
	i = 0;
	while (i < ft_checkifint(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_philos_data(&philos[i], av);
		philos[i].start_time = time;
		philos[i].last_meal = time;
		philos[i].launched = 0;
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead = &program->isdead;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

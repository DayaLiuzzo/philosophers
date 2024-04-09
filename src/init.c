/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:10:52 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/09 19:36:54 by dliuzzo          ###   ########.fr       */
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
	// program->philos->num_of_philos = ft_checkifint(av[1]);
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
	philos->time_to_die = atoi(av[2]);
	philos->time_to_eat = atoi(av[3]);
	philos->time_to_sleep = atoi(av[4]);
	philos->num_of_philos = atoi(av[1]);
	if (av[5])
		philos->num_times_to_eat = atoi(av[5]);
	else
		philos->num_times_to_eat = -1;
}
void	init_philos(t_program *program, t_philosophers *philos,
		pthread_mutex_t *forks, char **av)
{
	int i;

	i = 0;
	while (i < atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_philos_data(&philos[i], av);
		philos[i].start_time = current_time();
		philos[i].last_meal = current_time();
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
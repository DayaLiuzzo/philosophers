/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:11:45 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/23 15:39:42 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_checkifint(char *nptr)
{
	int					i;
	unsigned long long	r;
	int					m;

	i = 0;
	r = 0;
	m = 1;
	while (nptr[i] && ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			m = -1;
		i++;
	}
	while (nptr[i] - '0' >= 0 && nptr[i] - '0' <= 9)
	{
		r = 10 * r + (nptr[i] - '0');
		i++;
		if ((r > 2147483647 && m == 1) || (r > 2147483648 && m == -1))
			return (liberation("Invalid characters"), -1);
	}
	if (i == 0 || i != (int)strlen(nptr))
		return (liberation("Invalid characters"), -1);
	return ((int)r * m);
}
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
	int i;

	i = 0;
	while(i < philo_nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5)
		liberation("Few Args");
	if (ac > 6)
		liberation("Too many Args");
	while (av[i] && i < 5)
	{
		if (ft_checkifint(av[i]) <= 0)
			liberation("Invalid characters");
		i++;
	}
	if (ac == 6 && av[i])
		if(ft_checkifint(av[i]) < 0)
			liberation("A girl gotta eat??");
	if (atoi(av[1]) > 200)
		liberation("Too many mouth to feed");
}

void	init_philos_data(t_philosophers *philos, char **av)
{
		philos->num_of_philos = atoi(av[1]);
		philos->time_to_die = atoi(av[2]);
		philos->time_to_eat = atoi(av[3]);
		philos->time_to_sleep = atoi(av[4]);
		if (av[5])
			philos->num_times_to_eat = atoi(av[5]);
		else 
			philos->num_times_to_eat = -1;
}

size_t		current_time(void)
{
	struct timeval current_time;
	if(gettimeofday(&current_time, NULL) == -1)
	liberation("Current Time Error\n");;
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
		
	
}
void	init_philos(t_program *program, t_philosophers *philos, pthread_mutex_t *forks, char **av)
{
	int i;

	i = 0;
	while (i < atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].r_fork = &forks[i];
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].start_time = current_time();
		philos[i].last_meal = current_time();
		init_philos_data(&philos[i], av);
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

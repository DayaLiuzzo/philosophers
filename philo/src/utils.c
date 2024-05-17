/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:11:45 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/05/17 14:56:13 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dead_check(t_philosophers *philosopher)
{
	pthread_mutex_lock(philosopher->dead_lock);
	if (*philosopher->dead == 1)
		return (pthread_mutex_unlock(philosopher->dead_lock), 1);
	pthread_mutex_unlock(philosopher->dead_lock);
	return (0);
}

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
			return (-1);
	}
	if (i == 0 || i != (int)ft_strlen(nptr))
		return (-1);
	return ((int)r * m);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (write(1, "Wrong Argument Count\n", 22));
	while (av[i] && i < 5)
	{
		if (ft_checkifint(av[i]) <= 0)
			return (write(1, "Invalid Characters\n", 20));
		i++;
	}
	if (ac == 6 && av[i])
		if (ft_checkifint(av[i]) < 0)
			return (write(1, "A girl gotta eat?\n", 19));
	if (ft_checkifint(av[1]) > 300)
		return (write(1, "Too Many mouth to feed\n", 24));
	return (0);
}

size_t	current_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		write(1, "Current Time Error\n", 20);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

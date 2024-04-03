/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:11:45 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/03 18:11:11 by dliuzzo          ###   ########.fr       */
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

size_t		current_time(void)
{
	struct timeval current_time;
	if(gettimeofday(&current_time, NULL) == -1)
		liberation("Current Time Error\n");;
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
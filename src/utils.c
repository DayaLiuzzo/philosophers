/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:11:45 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/22 12:59:20 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strncmpp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (s1 || s2)
	{
		while (s1 && s1[i] && s2 && s2[i] && i < n)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	init_struct(t_philosophers *philosophers)
{
	philosophers->thread = 1;
}

void	check_args(int ac, char **av, t_philosophers *philosophers)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if(ac < 5)
		liberation("Few Args", philosophers);
	if(ac > 6)
		liberation("Too many Args", philosophers);
	while(av[i])
	{
		while(av[i][j])
		{
			if (isdigit(av[i][j]) == 0)
				liberation("Invalid Character", philosophers);
			j++;
		}
		j = 0;
		i++;
	}
	if (atoi(av[1]) > 200)
		liberation("Too many mouth to feed", philosophers); 
	printf("av[0]----> %s\n", av[0]);
}
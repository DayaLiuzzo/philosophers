/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:51:03 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/21 16:52:52 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void *myTest(void *vargp)
{
	printf("blabla\n");
	sleep(5);
	printf("bwbwbwb\n");
	vargp++;
	vargp--;
	return NULL;
}

int	main(int ac, char **av)
{
	t_philosophers philosophers;

	init_struct(&philosophers);
	check_args(ac, av, &philosophers);
	printf("AC ---> %i\nAV-----> %s", ac, av[0]);
	
	pthread_t thread_id;
	pthread_t thread_idd;
	printf("AVANT\n");
	pthread_create(&thread_id, NULL, myTest, NULL);
	pthread_join(thread_id, NULL);
	pthread_create(&thread_idd, NULL, myTest, NULL);
	pthread_join(thread_id, NULL);
	printf("APRES\n");
	return (0);
}

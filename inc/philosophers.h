/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:43:00 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/04/03 18:17:08 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

typedef struct s_philosophers
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philosophers;

typedef struct s_program
{
	int				isdead;
	t_philosophers	*philos;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;

}					t_program;

// INIT
void				init_program(t_program *program, t_philosophers *philos);
void				init_philos_data(t_philosophers *philos, char **av);
void				init_fork(pthread_mutex_t *forks, int philo_num);
void				init_philos(t_program *program, t_philosophers *philos,
						pthread_mutex_t *forks, char **av);
// UTILS
void				check_args(int ac, char **av);
int					ft_checkifint(char *nptr);
size_t				current_time(void);

// PHILOS
void				*philo_routine(void *arg);

// SUPERVISE
void				*supervise(void *arg);

// THREADS
void				create_thread(t_program *program, pthread_mutex_t *forks);

// FREE
void				liberation(char *msg);
int					main(int ac, char **av);

#endif

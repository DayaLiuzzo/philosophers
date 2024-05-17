/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:43:00 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/05/17 15:21:00 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <ctype.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

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
	int				launched;
	int				*all_launched;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*started;
}					t_philosophers;

typedef struct s_program
{
	int				isdead;
	int				all_launched;
	t_philosophers	*philos;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	started;

}					t_program;
// INIT
void				print_dead(char *msg, int id, t_philosophers *philosopher);
void				init_program(t_program *program, t_philosophers *philos);
void				init_philos_data(t_philosophers *philos, char **av);
void				init_fork(pthread_mutex_t *forks, int philo_num);
void				init_philos(t_program *program, t_philosophers *philos,
						pthread_mutex_t *forks, char **av);
int					ft_usleep2(size_t time, t_philosophers *philo);
// UTILS
int					ft_strlen(char *str);
int					check_args(int ac, char **av);
void				print_msg(char *msg, int id, t_philosophers *philosopher);
size_t				current_time(void);
int					ft_checkifint(char *nptr);
int					dead_check(t_philosophers *philosopher);

// PHILOS
void				drop_fork(t_philosophers *philosopher);
void				pick_fork(t_philosophers *philosopher);
int					ft_usleep(size_t time);
void				*philo_routine(void *arg);
void				think(t_philosophers *philosopher);
void				ft_sleep(t_philosophers *philosopher);
void				eat(t_philosophers *philosopher);

// SUPERVISE
void				*supervise(void *arg);
int					is_dead(t_philosophers *philosopher, size_t time_to_die);
int					check_if_dead(t_philosophers *philosophers);
int					check_if_all_ate(t_philosophers *philosophers);

// THREADS
int					create_thread(t_program *program, pthread_mutex_t *forks);

// FREE
void				liberation(char *msg);
void				destroy_all(char *msg, t_program *program,
						pthread_mutex_t *forks);
int					main(int ac, char **av);

#endif

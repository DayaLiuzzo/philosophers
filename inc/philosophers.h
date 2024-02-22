/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:43:00 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/22 12:59:47 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <errno.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <ctype.h>

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef NUMBER_OF_PHILOSOPHERS
#  define NUMBER_OF_PHILOSOPHERS 6
# endif

# ifndef TIME_TO_DIE
#  define TIME_TO_DIE 60
# endif

# ifndef TIME_TO_EAT
#  define TIME_TO_EAT 60
# endif

# ifndef TIME_TO_SLEEP
#  define TIME_TO_SLEEP 60
# endif

# ifndef NUMBER_OF_TIMES_EACH_PHILOSOPHER_MUST_EAT
#  define NUMBER_OF_TIMES_EACH_PHILOSOPHER_MUST_EAT 1
# endif


typedef struct s_philosophers
{
    pthread_t		thread;
}			t_philosophers;

int			main(int ac, char **av);
void init_struct(t_philosophers *philosophers);
void	check_args(int ac, char **av, t_philosophers *philosophers);

//free
void    liberation(char *msg, t_philosophers *philosophers);

#endif

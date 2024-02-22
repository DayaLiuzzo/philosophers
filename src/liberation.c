/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:45:36 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/21 17:45:04 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void    liberation(char *msg, t_philosophers *philosophers)
{
    if(msg)
        printf("%s\n",msg);
    printf("%lu",philosophers->thread);
    //free future
    exit(1);
}
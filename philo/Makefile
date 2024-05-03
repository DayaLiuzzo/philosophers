# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:41:57 by dliuzzo           #+#    #+#              #
#    Updated: 2024/04/24 14:15:24 by dliuzzo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

ifeq ($(MAKECMDGOALS), bonus)
NAME = philosophers_bonus
endif

S = src/

ifeq ($(MAKECMDGOALS), bonus)
S = bonus/
endif

I = inc/

O = obj/

D = dep/

CC = cc

CFLAGS = -Wall -Wextra -Werror

ifeq ($(MAKECMDGOALS), debug)
CFLAGS += -g3
#CFLAGS += -fsanitize=address
endif

CFLAGS += -I$I

SRCS =	$Smain.c \
		$Sliberation.c \
		$Sutils.c \
		$Sinit.c \
		$Sphilos.c \
		$Ssupervise.c \
		$Sthreads.c \
		$Sutils2.c
#		$(addprefix $S, examplefolder/)

#ifeq ($(MAKECMDGOALS), bonus)
#SRCS = 	
#endif

RM	=	rm -rf

OBJS =	$(SRCS:$S%=$O%.o)

DEP =	$(SRCS:$S%=$D%.d)

all : $(NAME)

$O:
	mkdir -p $@

$(OBJS): | $O

$(OBJS): $O%.o: $S%
#	mkdir -p $@
	$(CC) $(CFLAGS) -c $< -o $@

$D:
	mkdir -p $@

$(DEP): | $D

$(DEP): $D%.d: $S%
#	mkdir -p $@
	$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME) : $(OBJS) $(DEP)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
debug: all

cleanobjs:
	$(RM) $(OBJS) $(O)

cleandep: 
	$(RM) $(DEP) $(D)

clean: cleanobjs cleandep

fclean : clean
	$(RM) $(NAME)
#	$(RM) $(NAME)_bonus

re: fclean all

.PHONY: all clean fclean re debug
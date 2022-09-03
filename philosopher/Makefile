# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 16:49:38 by hyujang           #+#    #+#              #
#    Updated: 2022/07/20 16:49:39 by hyujang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ./src/main.c \
		  ./src/philo_utils1.c \
		  ./src/philo_utils2.c \
		  ./src/thread_init.c \
		  ./src/forks_init.c \
		  ./src/thread_function.c \
		  ./src/philo_time.c \
		  ./src/philo_monitor.c
		  
OBJS	= $(SRCS:.c=.o)
INCS	= ./includes/philo.h

NAME	= philo

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^ -include $(INCS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all 
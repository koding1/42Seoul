# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 20:07:50 by hyujang           #+#    #+#              #
#    Updated: 2022/03/23 17:13:53 by hyujang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= get_next_line.c get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)
INCS		= get_next_line.h
NAME		= libgnl.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcus $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -include $(INCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

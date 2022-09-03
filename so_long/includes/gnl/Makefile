# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 13:12:57 by hyujang           #+#    #+#              #
#    Updated: 2022/06/25 15:09:37 by hyujang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= CC
CFLAG	= -Wall -Wextra -Werror
SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)
INCS	= get_next_line.h
NAME	= libgnl.a

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
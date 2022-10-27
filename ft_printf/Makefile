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
SRCS		= ft_printf.c ft_utils1.c ft_utils2.c
OBJS		= $(SRCS:.c=.o)
LIBFT_SRCS	= libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c \
				libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c libft/ft_tolower.c \
				libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c \
				libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
				libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_convert_base.c libft/ft_convert_base2.c libft/ft_itoa_ui.c libft/ft_write_hex_address.c libft/ft_lstnew.c \
				libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c
LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)
INCS		= ft_printf.h
NAME		= libftprintf.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(OBJS)
	ar -rcus $@ $^

LIBFT_OBJS:
	make -C libft/ all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -include $(INCS)

clean:
	rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

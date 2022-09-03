# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 16:46:40 by hyujang           #+#    #+#              #
#    Updated: 2022/07/08 16:38:06 by hyujang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

MAIN_SRC	= ./src/push_swap.c
MAIN_OBJ	= $(MAIN_SRC:.c=.o)
SRCS		= ./src/arr_check.c ./src/error_check.c ./src/push_swap_utils1.c ./src/push_swap_utils2.c ./src/push_swap_utils3.c ./src/linked_list_utils1.c ./src/linked_list_utils2.c ./src/linked_list_utils3.c ./src/linked_list_utils4.c ./src/quick_sort.c ./src/quick_sort_stack.c ./src/mapping_funtions.c ./src/sorting_rules1.c ./src/sorting_a_stack.c ./src/sorting_b_stack.c ./src/pre_def_funtions.c ./src/malloc_custom.c
OBJS		= $(SRCS:.c=.o)
INCS		= ./includes/push_swap.h

BONUS_SRCS	= ./checker_src/checker_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
BONUS_INCS	= ./includes/checker_bonus.h

PRINTF_DIR	= ./includes/ft_printf
PRINTF_LIB	= -L $(PRINTF_DIR) -lftprintf

GNL_DIR	= ./includes/gnl
GNL_LIB	= -L $(GNL_DIR) -lgnl

NAME		= push_swap
BONUS_NAME	= checker

.PHONY: all clean fclean re bonus

all : $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS) $(OBJS)
	make -C $(GNL_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $^ -include $(BONUS_INCS) $(PRINTF_LIB) $(GNL_LIB)

$(NAME) : $(OBJS) $(MAIN_OBJ)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $^ -include $(INCS) $(PRINTF_LIB)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(GNL_DIR)
	rm -f $(OBJS)
	rm -f $(MAIN_OBJ)
	rm -f $(BONUS_OBJS)
	
fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re : fclean all

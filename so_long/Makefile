# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 13:12:57 by hyujang           #+#    #+#              #
#    Updated: 2022/06/26 21:12:58 by hyujang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAG		= -Wall -Wextra -Werror
SRCS		= src/main.c src/image_init.c src/game_init.c src/read_map_file.c src/move_cat.c src/error_checks.c src/map_draw.c src/move_cnt_draw.c src/draw_cat.c
OBJS		= $(SRCS:.c=.o)
INCS		= ./includes/so_long.h
BONUS_SRCS	= src_bonus/main_bonus.c src_bonus/image_init_bonus.c src_bonus/game_init_bonus.c src_bonus/read_map_file_bonus.c src_bonus/move_cat_bonus.c src_bonus/error_checks_bonus.c src_bonus/map_draw_bonus.c src_bonus/move_cnt_draw_bonus.c src_bonus/draw_cat_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
BONUS_INCS	= ./includes/so_long_bonus.h
FRAMEWORKS	= -framework OpenGL -framework AppKit
LIBMLX_DIR	= ./mlx_opengl
LIBS		= -L $(LIBMLX_DIR) -lmlx
GNL_DIR		= ./includes/gnl
GNL_OBJS	= -L $(GNL_DIR) -lgnl
NAME		= so_long
NAME_BONUS	= so_long_bonus

.PHONY: all clean fclean re bonus

all: $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	make -C $(LIBMLX_DIR)
	make -C $(GNL_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $^ -include $(INCS) $(LIBS) $(GNL_OBJS) $(FRAMEWORKS)

$(NAME_BONUS) : $(BONUS_OBJS)
	make -C $(LIBMLX_DIR)
	make -C $(GNL_DIR)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $^ -include $(BONUS_INCS) $(LIBS) $(GNL_OBJS) $(FRAMEWORKS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	make clean -C $(LIBMLX_DIR)
	make fclean -C $(GNL_DIR)
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

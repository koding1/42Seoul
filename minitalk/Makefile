# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 13:07:52 by hyujang           #+#    #+#              #
#    Updated: 2022/07/04 19:47:21 by hyujang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAG		= -g -Wall -Wextra -Werror

SERVER_SRCS	= src/server.c
SERVER_OBJS	= $(SERVER_SRCS:.c=.o)
SERVER		= server
CLIENT_SRCS	= src/client.c
CLIENT_OBJS	= $(CLIENT_SRCS:.c=.o)
CLIENT		= client
INCS		= ./includes/minitalk.h

SERVER_BONUS_SRCS	= src_bonus/server_bonus.c
SERVER_BONUS_OBJS	= $(SERVER_BONUS_SRCS:.c=.o)
SERVER_BONUS		= server_bonus
CLIENT_BONUS_SRCS	= src_bonus/client_bonus.c
CLIENT_BONUS_OBJS	= $(CLIENT_BONUS_SRCS:.c=.o)
CLIENT_BONUS		= client_bonus
INCS_BONUS		= ./includes/minitalk_bonus.h

PRINTF_DIR	= ./includes/ft_printf
PRINTF_LIB	= -L $(PRINTF_DIR) -lftprintf

MINITALK	= MINITALK
MINITALK_BONUS	=MINITALK_BONUS

.PHONY: all clean fclean re bonus

all: $(MINITALK)

bonus : $(MINITALK_BONUS)

$(MINITALK) : $(SERVER) $(CLIENT)

$(MINITALK_BONUS) : $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER) : $(SERVER_OBJS)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(SERVER) $^ -include $(INCS) $(PRINTF_LIB)

$(CLIENT) : $(CLIENT_OBJS)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(CLIENT) $^ -include $(INCS) $(PRINTF_LIB)

$(SERVER_BONUS) : $(SERVER_BONUS_OBJS)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $^ -include $(INCS_BONUS) $(PRINTF_LIB)

$(CLIENT_BONUS) : $(CLIENT_BONUS_OBJS)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $^ -include $(INCS_BONUS) $(PRINTF_LIB)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make fclean -C $(PRINTF_DIR)
	rm -f $(SERVER_OBJS)
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_BONUS_OBJS)
	rm -f $(CLIENT_BONUS_OBJS)

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)
	rm -f $(SERVER_BONUS)
	rm -f $(CLIENT_BONUS)

re: fclean all

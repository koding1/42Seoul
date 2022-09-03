/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:30:33 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/04 19:25:16 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_status;

void	convert_and_send(int pid, unsigned int num, int cnt)
{
	if (cnt < 7)
		convert_and_send(pid, num / 2, cnt + 1);
	if (num % 2 == 1)
	{
		g_status = IDLE;
		while (g_status != FINISH)
		{
			if (g_status == IDLE)
				kill(pid, SIGUSR1);
			usleep(EPSILON);
		}
	}
	else
	{
		g_status = IDLE;
		while (g_status != FINISH)
		{
			if (g_status == IDLE)
				kill(pid, SIGUSR2);
			usleep(EPSILON);
		}
	}
}

void	data_sender(int pid, char *str)
{
	int	i;
	int	ascii_num;

	i = 0;
	ft_printf("str len : %d\n", ft_strlen(str));
	while (str[i])
	{
		ascii_num = (unsigned int)str[i++];
		convert_and_send(pid, ascii_num, 0);
	}
}

void	handler1(int signo, struct __siginfo *siginfo, void *content)
{
	write(1, "RECEIVE    ACK\n", 15);
	if (g_status == IDLE)
		g_status = BUSY;
}

void	handler2(int signo, struct __siginfo *siginfo, void *content)
{
	write(1, "RECEIVE FINISH\n", 15);
	g_status = FINISH;
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;
	struct sigaction	act2;

	if (argc < 3)
	{
		write(1, "need more data.\n", 16);
		return (1);
	}
	g_status = IDLE;
	ft_printf("CLIENT PID : %d\n", getpid());
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	act2.sa_flags = SA_SIGINFO | SA_RESTART;
	act.sa_sigaction = &handler1;
	act2.sa_sigaction = &handler2;
	sigemptyset(&act.sa_mask);
	sigemptyset(&act2.sa_mask);
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act2, 0);
	data_sender(ft_atoi(argv[1]), argv[2]);
	return (0);
}

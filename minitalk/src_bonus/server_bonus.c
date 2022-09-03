/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:30:24 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/04 19:31:51 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

t_buffer	g_buf;

void	usr1_handler(int signo, struct __siginfo *siginfo, void *content)
{
	if (kill(siginfo->si_pid, SIGUSR1) == -1)
		exit(-1);
	g_buf.data = g_buf.data << 1;
	g_buf.data++;
	++g_buf.cnt;
	if (g_buf.cnt == 8)
	{
		write(1, &g_buf.data, 1);
		g_buf.cnt = 0;
		g_buf.data = 0;
	}
	usleep(EPSILON);
	if (kill(siginfo->si_pid, SIGUSR2) == -1)
		exit(-1);
}

void	usr2_handler(int signo, struct __siginfo *siginfo, void *content)
{
	if (kill(siginfo->si_pid, SIGUSR1) == -1)
		exit(-1);
	g_buf.data = g_buf.data << 1;
	++g_buf.cnt;
	if (g_buf.cnt == 8)
	{
		write(1, &g_buf.data, 1);
		g_buf.cnt = 0;
		g_buf.data = 0;
	}
	usleep(EPSILON);
	if (kill(siginfo->si_pid, SIGUSR2) == -1)
		exit(-1);
}

int	main(void)
{
	struct sigaction	act;
	struct sigaction	act2;

	g_buf.cnt = 0;
	g_buf.data = 0;
	ft_printf("SERVER PID : %d\n", getpid());
	act.sa_flags = SA_SIGINFO | SA_NODEFER | SA_RESTART;
	act.sa_sigaction = &usr1_handler;
	act2.sa_flags = SA_SIGINFO | SA_NODEFER | SA_RESTART;
	act2.sa_sigaction = &usr2_handler;
	sigemptyset(&act.sa_mask);
	sigemptyset(&act2.sa_mask);
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act2, 0);
	while (1)
		pause();
	return (0);
}

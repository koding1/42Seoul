/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:13:40 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/29 15:30:43 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isdigit(int ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					flag;
	unsigned long long	num;

	num = 0;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || (str[i] == 32))
		i++;
	flag = 1;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			flag *= (-1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		if (num > LLONG_MAX && flag == 1)
			return (-1);
		if (num > LLONG_MAX && flag == -1)
			return (0);
		i++;
	}
	return ((int)(num * flag));
}

int	stop_checker(t_thread_args *args)
{
	pthread_mutex_lock(args->stop_lock);
	if (args->stop != 0)
	{
		if (args->l_fork)
			pthread_mutex_unlock(&args->forks[args->id]);
		if (args->r_fork)
			pthread_mutex_unlock(&args->forks[(args->id + 1) \
								% args->input.philo_num]);
		pthread_mutex_unlock(args->stop_lock);
		return (1);
	}
	pthread_mutex_unlock(args->stop_lock);
	return (0);
}

void	take_forks_print(t_thread_args *args)
{
	pthread_mutex_lock(args->print_lock);
	printf("%ld %d has taken a fork\n", get_time() - args->s_time, args->id);
	printf("%ld %d has taken a fork\n", get_time() - args->s_time, args->id);
	pthread_mutex_unlock(args->print_lock);
}

void	fork_lock_and_set_flag(t_thread_args *args, int left_right)
{
	if (left_right == 0)
		pthread_mutex_lock(&args->forks[args->id]);
	else
	{
		pthread_mutex_lock(&args->forks[(args->id + 1) \
							% args->input.philo_num]);
	}
}

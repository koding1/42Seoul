/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:29:30 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/29 14:56:26 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	set_stop_all_philo_died(t_thread_args *args, int died_philo)
{
	int	i;

	i = 0;
	while (i < args->input.philo_num)
	{
		pthread_mutex_lock(args->stop_lock);
		args[i].stop = 1;
		pthread_mutex_unlock(args->stop_lock);
		i++;
	}
	pthread_mutex_lock(args->print_lock);
	printf("%ld %d died\n", get_time() - args->s_time, died_philo);
	pthread_mutex_unlock(args->print_lock);
}

static void	set_stop_all_philo_eat(t_thread_args *args)
{
	int	i;

	i = 0;
	while (i < args->input.philo_num)
	{
		pthread_mutex_lock(args->stop_lock);
		args[i].stop = 1;
		pthread_mutex_unlock(args->stop_lock);
		i++;
	}
}

static int	all_philo_eat_cnt_check(t_thread_args *args)
{
	int	i;

	i = 0;
	if (!args[i].input.least_eat_flag)
		return (0);
	while (i < args[0].input.philo_num)
	{
		pthread_mutex_lock(args->stop_lock);
		if (args[i].eat_cnt < args[i].input.least_eat)
		{
			pthread_mutex_unlock(args->stop_lock);
			return (0);
		}
		i++;
		pthread_mutex_unlock(args->stop_lock);
	}
	return (1);
}

static int	philo_die_check(t_thread_args *args)
{
	pthread_mutex_lock(args->stop_lock);
	if (get_time() - args->last_eat > args->input.die_time \
		&& args->last_eat != -999)
	{
		pthread_mutex_unlock(args->stop_lock);
		return (1);
	}
	pthread_mutex_unlock(args->stop_lock);
	return (0);
}

void	*monitor_thread(void	*args_void)
{
	int				i;
	t_thread_args	*args;

	args = (t_thread_args *)args_void;
	while (1)
	{
		i = 0;
		while (i < args[0].input.philo_num)
		{
			if (philo_die_check(args + i))
			{
				set_stop_all_philo_died(args, i);
				return (0);
			}
			if (all_philo_eat_cnt_check(args))
			{
				set_stop_all_philo_eat(args);
				return (0);
			}
			i++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:29:30 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/29 15:31:06 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_forks(t_thread_args *args)
{
	if (philo_one_case(args))
		return (1);
	if (args->id % 2 == 0)
	{
		fork_lock_and_set_flag(args, 0);
		fork_lock_and_set_flag(args, 1);
	}
	else
	{
		fork_lock_and_set_flag(args, 1);
		fork_lock_and_set_flag(args, 0);
	}
	if (!stop_checker(args))
	{
		take_forks_print(args);
		usleep(DELAY);
	}
	return (0);
}

int	eating(t_thread_args *args)
{
	if (!stop_checker(args))
	{
		pthread_mutex_lock(args->print_lock);
		printf("%ld %d is eating\n", get_time() - args->s_time, args->id);
		pthread_mutex_unlock(args->print_lock);
		pthread_mutex_lock(args->stop_lock);
		args->last_eat = get_time();
		args->eat_cnt++;
		pthread_mutex_unlock(args->stop_lock);
		ft_usleep(args->input.eat_time);
	}
	pthread_mutex_unlock(&args->forks[args->id]);
	pthread_mutex_unlock(&args->forks[(args->id + 1) % args->input.philo_num]);
	usleep(DELAY);
	return (0);
}

int	sleeping(t_thread_args *args)
{
	if (!stop_checker(args))
	{
		pthread_mutex_lock(args->print_lock);
		printf("%ld %d is sleeping\n", get_time() - args->s_time, args->id);
		pthread_mutex_unlock(args->print_lock);
		ft_usleep(args->input.sleep_time);
	}
	usleep(DELAY);
	return (0);
}

int	thinking(t_thread_args *args)
{
	if (!stop_checker(args))
	{
		pthread_mutex_lock(args->print_lock);
		printf("%ld %d is thinking\n", get_time() - args->s_time, args->id);
		pthread_mutex_unlock(args->print_lock);
	}
	usleep(DELAY);
	return (0);
}

void	*t_function(void	*args_void)
{
	t_thread_args	*args;

	args = (t_thread_args *)args_void;
	pthread_mutex_lock(args->stop_lock);
	args->s_time = get_time();
	args->last_eat = get_time();
	pthread_mutex_unlock(args->stop_lock);
	if (args->id % 2 == 0)
		usleep(DELAY);
	while (1)
	{
		if (take_forks(args))
			return (0);
		if (eating(args))
			return (0);
		if (sleeping(args))
			return (0);
		if (thinking(args))
			return (0);
		if (stop_checker(args))
			return (0);
	}
	return (0);
}

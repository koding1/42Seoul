/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:57:01 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/20 16:57:02 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	malloc_for_init(t_thread_args **args, pthread_mutex_t **print_lock, \
							pthread_mutex_t	**stop_lock, int philo_num)
{
	*args = (t_thread_args *)malloc(philo_num * sizeof(t_thread_args));
	if (*args == 0)
		return (1);
	*print_lock = (pthread_mutex_t *)malloc(1 * sizeof(pthread_mutex_t));
	pthread_mutex_init(*print_lock, 0);
	if (print_lock == 0)
	{
		free(args);
		return (1);
	}
	*stop_lock = (pthread_mutex_t *)malloc(1 * sizeof(pthread_mutex_t));
	pthread_mutex_init(*stop_lock, 0);
	if (stop_lock == 0)
	{
		free(args);
		free(print_lock);
		return (1);
	}
	return (0);
}

static void	set_least_eat(t_thread_args *args_point, int argc, char *argv[])
{
	if (argc == 6)
	{
		args_point->input.least_eat_flag = 1;
		args_point->input.least_eat = ft_atoi(argv[5]);
	}
	else
	{
		args_point->input.least_eat_flag = 0;
		args_point->input.least_eat = 0;
	}
}

static int	init_args(t_thread_args **args, int argc, char *argv[])
{
	int				i;
	int				philo_num;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*stop_lock;

	philo_num = ft_atoi(argv[1]);
	if (malloc_for_init(args, &print_lock, &stop_lock, philo_num))
		return (1);
	i = 0;
	while (i < philo_num)
	{
		(*args)[i].input.philo_num = philo_num;
		(*args)[i].input.die_time = ft_atoi(argv[2]);
		(*args)[i].input.eat_time = ft_atoi(argv[3]);
		(*args)[i].input.sleep_time = ft_atoi(argv[4]);
		(*args)[i].stop = 0;
		(*args)[i].last_eat = -999;
		(*args)[i].print_lock = print_lock;
		(*args)[i].stop_lock = stop_lock;
		set_least_eat((*args) + i, argc, argv);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	t_thread_args	*args;

	if (!(argc == 5 || argc == 6))
		return (1);
	if (init_args(&args, argc, argv))
		return (1);
	philos = (pthread_t *)malloc(args[0].input.philo_num * sizeof(pthread_t));
	if (philos == 0)
		return (1);
	forks = (pthread_mutex_t *) \
			malloc(args[0].input.philo_num * sizeof(pthread_mutex_t));
	if (forks == 0)
		return (1);
	if (init_forks(forks, args))
		return (1);
	if (make_thread(philos, args))
		return (1);
	return (0);
}

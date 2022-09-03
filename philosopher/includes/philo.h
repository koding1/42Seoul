/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:57:08 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/29 15:09:22 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

# define DELAY 50

typedef struct s_arguments {
	int	philo_num;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	least_eat;
	int	least_eat_flag;
}	t_arguments;

typedef struct s_thread_args
{
	int				id;
	int				stop;
	int				eat_cnt;
	int				l_fork;
	int				r_fork;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*stop_lock;
	pthread_mutex_t	*forks;
	long			s_time;
	long			last_eat;
	t_arguments		input;
}	t_thread_args;

// philo_utils1.c
int		ft_atoi(const char *str);
int		stop_checker(t_thread_args *args);
void	take_forks_print(t_thread_args *args);
void	fork_lock_and_set_flag(t_thread_args *args, int left_right);

//philo_utils2.c
int		philo_one_case(t_thread_args *args);

// thread_init.c
int		make_thread(pthread_t *philos, t_thread_args *args);

// forks_init.c
int		init_forks(pthread_mutex_t *forks, t_thread_args *args);

// thread_function.c
void	*t_function(void *a);

// philo_time.c
void	ft_usleep(long sleep_time);
long	get_time(void);

// philo_monitor.c
void	*monitor_thread(void	*args_void);
#endif
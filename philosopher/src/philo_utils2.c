/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:13:40 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/29 15:30:43 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_one_case(t_thread_args *args)
{
	if (args->input.philo_num == 1)
	{
		fork_lock_and_set_flag(args, 0);
		pthread_mutex_lock(args->print_lock);
		printf("%ld %d has taken a fork\n", \
				get_time() - args->s_time, args->id);
		pthread_mutex_unlock(args->print_lock);
		pthread_mutex_unlock(&args->forks[args->id]);
		return (1);
	}
	return (0);
}

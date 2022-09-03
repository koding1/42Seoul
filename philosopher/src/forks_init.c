/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:58:26 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/20 19:58:27 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_forks(pthread_mutex_t *forks, t_thread_args *args)
{
	int	i;

	i = 0;
	while (i < args[0].input.philo_num)
	{
		args[i].forks = forks;
		if (pthread_mutex_init(&forks[i], 0))
			return (1);
		i++;
	}
	return (0);
}

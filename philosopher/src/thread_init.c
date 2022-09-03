/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:21:52 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/20 19:21:53 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	make_thread(pthread_t *philos, t_thread_args *args)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	while (i < args[0].input.philo_num)
	{
		args[i].id = i;
		if (pthread_create(&philos[i], 0, t_function, (void *)&args[i]))
			return (1);
		i++;
	}
	if (pthread_create(&monitor, 0, monitor_thread, (void *)args))
		return (0);
	i = 0;
	pthread_join(monitor, 0);
	while (i < args[0].input.philo_num)
	{
		if (pthread_join(philos[i], 0))
			return (1);
		i++;
	}
	return (0);
}

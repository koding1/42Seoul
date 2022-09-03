/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:29:30 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/20 19:29:31 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(long sleep_time)
{
	long	start;

	start = get_time();
	while (start + (sleep_time * 1) > get_time())
		usleep(100);
}

long	get_time(void)
{
	struct timeval	time;
	long			result;

	gettimeofday(&time, NULL);
	result = ((size_t)time.tv_sec * 1000) + ((size_t)time.tv_usec / 1000);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:29:18 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/13 17:48:14 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

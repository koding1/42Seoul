/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:28:16 by hyujang           #+#    #+#             */
/*   Updated: 2022/04/01 15:10:34 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digit(long long num)
{
	if (num / 10)
		return (num_digit(num / 10) + 1);
	return (1);
}

static void	set_str(long long num, char *p, int idx)
{
	p[idx] = (num % 10) + '0';
	if (num / 10)
		set_str(num / 10, p, idx - 1);
}

char	*ft_itoa_ui(unsigned int n)
{
	int			flag;
	long long	num;
	int			digit;
	char		*p;

	flag = 0;
	num = (long long)n;
	if (num < 0)
		num *= -1;
	digit = num_digit(num);
	p = (char *)malloc((digit + 1 + flag) * sizeof(char));
	if (p == 0)
		return (0);
	set_str(num, p, digit - 1 + flag);
	p[digit + flag] = 0;
	if (flag)
		p[0] = '-';
	return (p);
}

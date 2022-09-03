/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:20:50 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/23 18:34:40 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_and_get_len(const char *s)
{
	int	len;

	len = 0;
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s++, 1);
		len++;
	}
	return (len);
}

int	print_c(va_list values)
{
	unsigned char	c;

	c = (unsigned char)va_arg(values, int);
	write(1, &c, 1);
	return (1);
}

int	print_s(va_list values)
{
	int		len;
	char	*str;

	str = (char *)va_arg(values, char *);
	len = write_and_get_len(str);
	return (len);
}

int	print_p(va_list values)
{
	return (ft_write_hex_address((void *)va_arg(values, void *)));
}

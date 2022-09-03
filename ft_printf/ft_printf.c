/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:03:15 by hyujang           #+#    #+#             */
/*   Updated: 2022/04/01 15:47:02 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_match_print(const char *s, va_list values, int *flag)
{
	char	c;

	if (s[0] == '%')
	{
		c = s[1];
		*flag = 1;
		if (c == 'c')
			return (print_c(values));
		if (c == 's')
			return (print_s(values));
		if (c == 'p')
			return (print_p(values));
		if (c == 'd' || c == 'i')
			return (print_d(values));
		if (c == 'u')
			return (print_u(values));
		if (c == 'x' || c == 'X')
			return (print_x(values, c == 'X'));
		if (c != 0)
			return (write(1, &c, 1));
	}
	return (0);
}

static int	format_write(const char *format, va_list values)
{
	int	i;
	int	flag;
	int	cnt;
	int	print_cnt;

	i = 0;
	print_cnt = 0;
	while (format[i])
	{
		flag = 0;
		cnt = format_match_print(format + i, values, &flag);
		if (cnt == -1)
			return (-1);
		if (flag != 1)
		{
			write(1, format + i, 1);
			++cnt;
		}
		print_cnt += cnt;
		i += (1 + flag);
	}
	return (print_cnt);
}

int	ft_printf(const char *format, ...)
{
	int		print_cnt;
	va_list	values;

	va_start(values, format);
	print_cnt = format_write(format, values);
	va_end(values);
	return (print_cnt);
}

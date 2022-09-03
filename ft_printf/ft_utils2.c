/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:10:31 by hyujang           #+#    #+#             */
/*   Updated: 2022/04/01 15:46:51 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d(va_list values)
{
	char	*str;
	int		len;

	str = ft_itoa((int)va_arg(values, int));
	if (!str)
		return (-1);
	len = write_and_get_len(str);
	free(str);
	return (len);
}

int	print_u(va_list values)
{
	char	*str;
	int		len;

	str = ft_itoa_ui((unsigned int)va_arg(values, unsigned int));
	if (!str)
		return (-1);
	len = write_and_get_len(str);
	free(str);
	return (len);
}

int	convert_hex(unsigned int num, char *base)
{
	char	str[8];
	int		i;

	i = 7;
	while (i >= 0)
	{
		str[i--] = base[num % 16];
		num /= 16;
	}
	i = 0;
	while (i < 8 && str[i] == '0')
		i++;
	if (i == 8)
	{
		write(1, "0", 1);
		return (1);
	}
	write(1, str + i, 8 - i);
	return (8 - i);
}

int	print_x(va_list values, int upper)
{
	unsigned int	num;

	num = (unsigned int)va_arg(values, unsigned int);
	if (upper == 1)
		return (convert_hex(num, "0123456789ABCDEFG"));
	else
		return (convert_hex(num, "0123456789abcdefg"));
}

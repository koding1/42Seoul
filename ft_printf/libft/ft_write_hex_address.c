/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex_address.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:24:03 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/23 18:03:12 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_write_hex_address(void *addr)
{
	int					i;
	char				str[16];
	unsigned long long	addr_int;

	i = 15;
	addr_int = (unsigned long long)addr;
	while (i >= 0)
	{
		str[i] = "0123456789abcdef"[addr_int % 16];
		addr_int /= 16;
		i--;
	}
	write(1, "0x", 2);
	i = 0;
	while (str[i] == '0' && i < 16)
		i++;
	if (i == 16)
	{
		write(1, "0", 1);
		return (3);
	}
	write(1, str + i, 16 - i);
	return (16 - i + 2);
}

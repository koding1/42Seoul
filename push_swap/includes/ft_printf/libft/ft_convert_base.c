/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:58:49 by hyujang           #+#    #+#             */
/*   Updated: 2022/04/01 15:15:03 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	nbr2int(char *nbr, char *base_from, int base_len)
{
	int			i;
	int			end;
	int			ns;
	long long	num;

	num = 0;
	i = 0;
	end = 0;
	while (nbr[i] != 0 && ((9 <= nbr[i] && nbr[i] <= 13) || nbr[i] == ' '))
		i++;
	ns = set_i_end(nbr, base_from, &i, &end);
	while (i < end)
	{
		num = (num * base_len) + find_index(base_from, nbr[i]);
		i++;
	}
	if (ns % 2 == 1)
		return (num *(-1));
	return (num);
}

static void	int2nbr(char *p, long long num, char *base_to, int i)
{
	if (num / check_base(base_to) > 0)
		int2nbr(p, num / check_base(base_to), base_to, i - 1);
	p[i] = base_to[num % check_base(base_to)];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	num;
	char		*p;
	int			full_len;
	int			flag;

	flag = 0;
	if (check_base(base_from) <= 1 || check_base(base_to) <= 1)
		return (0);
	num = nbr2int(nbr, base_from, check_base(base_from));
	if (num < 0)
	{
		flag = 1;
		num *= (-1);
	}
	full_len = ft_len(num, base_to);
	p = (char *)malloc((full_len + flag + 1) * sizeof(char));
	if (!p)
		return (0);
	int2nbr(p, num, base_to, full_len - 1 + flag);
	if (flag)
		p[0] = '-';
	p[full_len + flag] = 0;
	return (p);
}

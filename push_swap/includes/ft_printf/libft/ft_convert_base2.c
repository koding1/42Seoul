/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:53:50 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/21 16:33:54 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_index(char *base, char ch)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (ch == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		if ((9 <= base[i] && base[i] <= 13) || base[i] == 32 \
			|| base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	set_i_end(char *str, char *base, int *i, int *end)
{
	int	ns;

	ns = 0;
	while (str[*i] != 0)
	{
		if (-1 == find_index(base, str[*i]) && str[*i] == '-')
			ns++;
		if (find_index(base, str[*i]) >= 0)
		{
			*end = *i;
			while (find_index(base, str[*end]) >= 0)
				*end = *end + 1;
			break ;
		}
		*i = *i + 1;
	}
	return (ns);
}

int	ft_len(long long num, char *base_to)
{
	if (num / check_base(base_to) > 0)
		return (ft_len(num / check_base(base_to), base_to) + 1);
	return (1);
}

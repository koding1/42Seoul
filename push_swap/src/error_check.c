/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:59:50 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/09 14:03:25 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_write_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	range_check(char *str)
{
	int		i;
	int		len;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (!('0' <= str[i] && str[i] <= '9'))
		error_write_exit();
	while (str[i] && str[i] == '0')
		i++;
	len = i;
	while (str[len])
	{
		if (('0' <= str[len] && str[len] <= '9') || str[len] == ' ')
			len++;
		else
			error_write_exit();
	}
	if ((len - i) > 10)
		error_write_exit();
}

static int	ft_atoi_and_check(const char *str)
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
		if (num > 2147483647 && flag == 1)
			error_write_exit();
		if (num > 2147483648 && flag == -1)
			error_write_exit();
		i++;
	}
	return ((int)(num * flag));
}

void	split_free(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

void	valid_check_and_init(int argc, char *argv[], t_deque *deq, int *arr)
{
	int		i;
	int		data;
	char	**p;
	int		cnt;
	char	**tmp;

	cnt = 0;
	i = 1;
	while (i < argc)
	{
		p = ft_split(argv[i], ' ');
		if (p == 0 || *p == 0)
			error_write_exit();
		tmp = p;
		while (*p)
		{
			range_check(*p);
			data = ft_atoi_and_check(*p);
			arr[cnt++] = data;
			append_head(deq, make_new_node(data));
			p++;
		}
		split_free(tmp);
		i++;
	}
}

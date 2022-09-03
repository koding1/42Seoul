/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:44:35 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:44:38 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	arr_malloc(int argc, char *argv[])
{
	int		i;
	char	**p;
	int		cnt;
	char	**tmp;

	cnt = 0;
	i = 1;
	while (i < argc)
	{
		p = ft_split(argv[i], ' ');
		if (p == 0)
			error_write_exit();
		tmp = p;
		while (*p)
		{
			cnt++;
			p++;
		}
		split_free(tmp);
		i++;
	}
	return (cnt);
}

static void	init_main(t_deque *a, t_deque *b, t_deque *inst)
{
	init_list(a);
	init_list(b);
	init_list(inst);
}

void	mapping_str(t_deque_set *ab, t_deque *inst, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(&ab->a, 0, inst);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(&ab->b, 0, inst);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(&ab->a, &ab->b, inst);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(ab, inst);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(ab, inst);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(&ab->a, 0, inst);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(&ab->b, 0, inst);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(&ab->a, &ab->b, inst);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(&ab->a, 0, inst);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(&ab->b, 0, inst);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(&ab->a, &ab->b, inst);
	else
		error_write_exit();
}

void	is_sorted_list(t_deque_set *ab, int num_cnt)
{
	t_node	*p;
	int		i;

	if (ab->a.cnt != num_cnt || ab->b.cnt != 0)
	{
		write(1, "KO\n", 3);
		return ;
	}
	i = 0;
	p = ab->a.head;
	while (i < num_cnt - 1)
	{
		if (p->val < p->next->val)
		{
			write(1, "KO\n", 3);
			return ;
		}
		p = p->next;
		i++;
	}
	write(1, "OK\n", 3);
}

int	main(int argc, char *argv[])
{
	t_deque_set	ab;
	int			*arr;
	t_deque		inst;
	int			num_cnt;
	char		*str;

	if (argc < 2)
		return (1);
	num_cnt = (arr_malloc(argc, argv));
	arr = (int *)malloc_and_check(num_cnt * sizeof(int));
	init_main(&ab.a, &ab.b, &inst);
	valid_check_and_init(argc, argv, &ab.a, arr);
	is_unique_array(arr, ab.a.cnt);
	quick_sort(arr, 0, num_cnt - 1);
	mapping_simple_number(&ab.a, arr);
	while (1)
	{
		str = get_next_line(0);
		if (str == 0)
			break ;
		mapping_str(&ab, &inst, str);
		free(str);
	}
	is_sorted_list(&ab, num_cnt);
	return (0);
}

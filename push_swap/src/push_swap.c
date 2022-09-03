/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:56:56 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/09 13:54:56 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	main(int argc, char *argv[])
{
	t_deque_set	ab;
	int			*arr;
	t_deque		inst;
	int			num_cnt;

	if (argc < 2)
		return (1);
	num_cnt = (arr_malloc(argc, argv));
	arr = (int *)malloc_and_check(num_cnt * sizeof(int));
	init_main(&ab.a, &ab.b, &inst);
	valid_check_and_init(argc, argv, &ab.a, arr);
	is_unique_array(arr, ab.a.cnt);
	is_sorting_array(arr, ab.a.cnt);
	quick_sort(arr, 0, num_cnt - 1);
	mapping_simple_number(&ab.a, arr);
	if (num_cnt <= 5 && num_cnt != 4)
		pre_def_funtions(&ab, num_cnt, &inst);
	else
		quick_sort_deque(&ab, num_cnt, &inst);
	print_all_node_inst(&inst);
	return (0);
}

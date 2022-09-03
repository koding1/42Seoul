/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:56:56 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:45:37 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printf_mapping_inst(int code)
{
	if (code == SA)
		write(1, "sa\n", 3);
	if (code == SB)
		write(1, "sb\n", 3);
	if (code == SS)
		write(1, "ss\n", 3);
	if (code == PA)
		write(1, "pa\n", 3);
	if (code == PB)
		write(1, "pb\n", 3);
	if (code == RA)
		write(1, "ra\n", 3);
	if (code == RB)
		write(1, "rb\n", 3);
	if (code == RR)
		write(1, "rr\n", 3);
	if (code == RRA)
		write(1, "rra\n", 4);
	if (code == RRB)
		write(1, "rrb\n", 4);
	if (code == RRR)
		write(1, "rrr\n", 4);
}

void	data_reduce(t_deque *deque)
{
	t_node	*p;
	t_node	*prev_tmp;

	p = deque->head;
	while (p)
	{
		prev_tmp = p->prev;
		if (can_skip(deque, p))
			p = prev_tmp;
		else
			p = p->next;
	}
}

void	print_all_node_inst(t_deque *deque)
{
	t_node	*p;

	data_reduce(deque);
	p = deque->head;
	while (p)
	{
		printf_mapping_inst(p->val);
		p = p->next;
	}
}

void	print_all_node(t_deque *deque)
{
	t_node	*p;

	write(1, "[top]\n", 6);
	p = deque->tail;
	while (p)
	{
		ft_printf("%d\n", p->val);
		p = p->prev;
	}
	write(1, "[bottom]\n", 9);
}

void	print_list_ab(t_deque_set *ab)
{
	print_all_node(&ab->a);
	print_all_node(&ab->b);
}

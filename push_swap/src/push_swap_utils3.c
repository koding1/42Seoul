/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:57:22 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/08 14:17:07 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_deque *deque, int flag, t_deque *inst)
{
	if (flag)
		append_tail(inst, make_new_node(RRA));
	if (deque->cnt < 2)
		return ;
	deque->tail->next = deque->head;
	deque->head->prev = deque->tail;
	deque->tail = deque->head;
	deque->head = deque->head->next;
	deque->tail->next = 0;
	deque->head->prev = 0;
}

void	rrb(t_deque *deque, int flag, t_deque *inst)
{
	if (flag)
		append_tail(inst, make_new_node(RRB));
	if (deque->cnt < 2)
		return ;
	deque->tail->next = deque->head;
	deque->head->prev = deque->tail;
	deque->tail = deque->head;
	deque->head = deque->head->next;
	deque->tail->next = 0;
	deque->head->prev = 0;
}

void	rrr(t_deque *a, t_deque *b, t_deque *inst)
{
	append_tail(inst, make_new_node(RRR));
	rra(a, 0, inst);
	rrb(b, 0, inst);
}

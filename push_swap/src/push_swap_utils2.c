/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:57:22 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/09 14:03:25 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_deque *deque, int flag, t_deque *inst)
{
	if (deque->cnt < 2)
		return ;
	if (flag)
		append_tail(inst, make_new_node(RA));
	deque->tail->next = deque->head;
	deque->head->prev = deque->tail;
	deque->head = deque->tail;
	deque->tail = deque->tail->prev;
	deque->tail->next = 0;
	deque->head->prev = 0;
}

void	rb(t_deque *deque, int flag, t_deque *inst)
{
	if (deque->cnt < 2)
		return ;
	if (flag)
		append_tail(inst, make_new_node(RB));
	deque->tail->next = deque->head;
	deque->head->prev = deque->tail;
	deque->head = deque->tail;
	deque->tail = deque->tail->prev;
	deque->tail->next = 0;
	deque->head->prev = 0;
}

void	rr(t_deque *a, t_deque *b, t_deque *inst)
{
	if (a->cnt < 2 && b->cnt < 2)
		return ;
	append_tail(inst, make_new_node(RR));
	ra(a, 0, inst);
	rb(b, 0, inst);
}

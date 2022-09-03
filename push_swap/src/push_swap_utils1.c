/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:57:22 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/08 16:45:56 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_deque *deque, int flag, t_deque *inst)
{
	t_node	*p;

	if (deque->cnt < 2)
		return ;
	if (flag)
		append_tail(inst, make_new_node(SA));
	p = deque->tail->prev;
	if (p->prev == 0)
		deque->head = deque->tail;
	else
		p->prev->next = deque->tail;
	p->next = 0;
	deque->tail->next = p;
	deque->tail->prev = p->prev;
	p->prev = deque->tail;
	deque->tail = p;
}

void	sb(t_deque *deque, int flag, t_deque *inst)
{
	t_node	*p;

	if (deque->cnt < 2)
		return ;
	if (flag)
		append_tail(inst, make_new_node(SB));
	p = deque->tail->prev;
	if (p->prev == 0)
		deque->head = deque->tail;
	else
		p->prev->next = deque->tail;
	p->next = 0;
	deque->tail->next = p;
	deque->tail->prev = p->prev;
	p->prev = deque->tail;
	deque->tail = p;
}

void	ss(t_deque *a, t_deque *b, t_deque *inst)
{
	if (a->cnt < 2 && b->cnt < 2)
		return ;
	append_tail(inst, make_new_node(SS));
	sa(a, 0, inst);
	sb(b, 0, inst);
}

void	pa(t_deque_set *deque, t_deque *inst)
{
	int	val;

	if (deque->b.head == 0)
		return ;
	append_tail(inst, make_new_node(PA));
	val = deque->b.tail->val;
	del_tail(&deque->b);
	append_tail(&deque->a, make_new_node(val));
}

void	pb(t_deque_set *deque, t_deque *inst)
{
	int	val;

	if (deque->a.head == 0)
		return ;
	append_tail(inst, make_new_node(PB));
	val = deque->a.tail->val;
	del_tail(&deque->a);
	append_tail(&deque->b, make_new_node(val));
}

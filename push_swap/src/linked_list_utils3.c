/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:56:56 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:46:48 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	delete_node(t_deque *deq, t_node *p)
{
	deq->cnt--;
	if ((deq->head != p) && (deq->tail != p))
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	else
	{
		if (deq->head == p)
		{
			deq->head = p->next;
			if (deq->head)
				deq->head->prev = 0;
		}
		if (deq->tail == p)
		{
			deq->tail = p->prev;
			if (deq->tail)
				deq->tail->next = 0;
		}
	}
	free(p);
}

int	compression(t_deque *deq, t_node *p, int val)
{
	delete_node(deq, p->next);
	p->val = val;
	return (1);
}

int	delete_two_inst(t_deque *deq, t_node *p)
{
	t_node	*q;

	q = p->next;
	delete_node(deq, p);
	if (q != 0)
		delete_node(deq, q);
	return (1);
}

int	can_skip(t_deque *deq, t_node *p)
{
	if (p->next == 0)
		return (0);
	if (try_compression(deq, p))
		return (1);
	if (try_delete(deq, p))
		return (1);
	return (0);
}

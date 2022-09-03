/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:56:56 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/09 13:56:00 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*make_new_node(int val)
{
	t_node	*new_node;

	new_node = (t_node *)malloc_and_check(1 * sizeof(t_node));
	new_node->val = val;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

void	append_head(t_deque *deque, t_node *new_node)
{
	deque->cnt++;
	if (deque->head == 0 && deque->tail == 0)
	{
		deque->head = new_node;
		deque->tail = new_node;
		return ;
	}
	new_node->next = deque->head;
	deque->head->prev = new_node;
	deque->head = new_node;
}

void	append_tail(t_deque *deque, t_node *new_node)
{
	deque->cnt++;
	if (deque->head == 0 && deque->tail == 0)
	{
		deque->head = new_node;
		deque->tail = new_node;
		return ;
	}
	new_node->prev = deque->tail;
	deque->tail->next = new_node;
	deque->tail = new_node;
}

void	del_tail(t_deque *deque)
{
	t_node	*p;

	if (deque->cnt == 0)
		return ;
	p = deque->tail;
	if (deque->cnt == 1)
	{
		deque->head = 0;
		deque->tail = 0;
	}
	else
	{
		deque->tail->prev->next = 0;
		deque->tail = deque->tail->prev;
	}
	deque->cnt--;
	free(p);
}

void	init_list(t_deque *deque)
{
	deque->cnt = 0;
	deque->head = 0;
	deque->tail = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_funtions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:46:08 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:46:09 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_and_update(int val, int *arr, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

void	mapping_simple_number(t_deque *deq, int *arr)
{
	t_node	*p;

	p = deq->head;
	while (p)
	{
		p->val = find_and_update(p->val, arr, deq->cnt);
		p = p->next;
	}
}

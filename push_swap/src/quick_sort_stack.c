/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:38 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:47:39 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_pv(t_deque *deque, t_node *p, int range, t_pivot *pv)
{
	int		i;
	t_node	*q;
	int		large_cnt;
	int		small_cnt;

	i = 0;
	q = deque->tail;
	large_cnt = 0;
	small_cnt = 0;
	while (i < range)
	{
		if (p->val > q->val)
			small_cnt++;
		if (p->val < q->val)
			large_cnt++;
		q = q->prev;
		i++;
	}
	if (large_cnt == (range / 3))
		pv->p_large = p->val;
	if (small_cnt == (range / 3))
		pv->p_small = p->val;
}

void	find_pivot(t_deque *deque, int range, t_pivot *pv)
{
	int		i;
	t_node	*p;

	p = deque->tail;
	i = 0;
	while (i < range)
	{
		set_pv(deque, p, range, pv);
		p = p->prev;
		i++;
	}
}

void	set_original_position(t_deque_set *ab, t_deque *inst, \
								int ra_cnt, int rb_cnt)
{
	int	i;

	while (ra_cnt > 0 && rb_cnt > 0)
	{
		rrr(&ab->a, &ab->b, inst);
		ra_cnt--;
		rb_cnt--;
	}
	i = 0;
	while (i < ra_cnt)
	{
		rra(&ab->a, 1, inst);
		i++;
	}
	i = 0;
	while (i < rb_cnt)
	{
		rrb(&ab->b, 1, inst);
		i++;
	}
}

void	init_cnt_pivot(t_deque *deque, int range, t_pivot *pv, t_record *cnt)
{
	cnt->pa_cnt = 0;
	cnt->pb_cnt = 0;
	cnt->ra_cnt = 0;
	cnt->rb_cnt = 0;
	find_pivot(deque, range, pv);
}

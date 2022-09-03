/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:45:53 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:45:54 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_pa_rb(t_deque_set *ab, t_deque *inst, t_pivot pv, t_record *cnt)
{
	if (ab->b.tail->val > pv.p_small)
	{
		pa(ab, inst);
		cnt->pa_cnt++;
		if (pv.p_large > ab->a.tail->val)
		{
			ra(&ab->a, 1, inst);
			cnt->ra_cnt++;
		}
	}
	else
	{
		rb(&ab->b, 1, inst);
		cnt->rb_cnt++;
	}
}

void	quick_sort_deque2(t_deque_set *ab, int range, t_deque *inst)
{
	t_pivot		pv;
	t_record	cnt;

	if (range < 1)
		return ;
	if (range < 3)
	{
		if (range == 2 && ab->b.tail->val < ab->b.tail->prev->val)
			sb(&ab->b, 1, inst);
		pa(ab, inst);
		if (range == 2)
			pa(ab, inst);
		return ;
	}
	init_cnt_pivot(&ab->b, range, &pv, &cnt);
	while (range--)
		do_pa_rb(ab, inst, pv, &cnt);
	quick_sort_deque(ab, cnt.pa_cnt - cnt.ra_cnt, inst);
	set_original_position(ab, inst, cnt.ra_cnt, cnt.rb_cnt);
	quick_sort_deque(ab, cnt.ra_cnt, inst);
	quick_sort_deque2(ab, cnt.rb_cnt, inst);
}

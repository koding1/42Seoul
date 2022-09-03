/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:48:15 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:48:16 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_pb_ra(t_deque_set *ab, t_deque *inst, t_pivot pv, t_record *cnt)
{
	if (ab->a.tail->val < pv.p_large)
	{
		pb(ab, inst);
		cnt->pb_cnt++;
		if (pv.p_small < ab->b.tail->val)
		{
			rb(&ab->b, 1, inst);
			cnt->rb_cnt++;
		}
	}
	else
	{
		ra(&ab->a, 1, inst);
		cnt->ra_cnt++;
	}
}

void	quick_sort_deque(t_deque_set *ab, int range, t_deque *inst)
{
	t_pivot		pv;
	t_record	cnt;

	if (range < 1)
		return ;
	if (range <= 3)
	{
		if (range == 2 && ab->a.tail->val > ab->a.tail->prev->val)
			sa(&ab->a, 1, inst);
		if (range == 3)
			three_sorting_rules_a(ab, inst);
		return ;
	}
	init_cnt_pivot(&ab->a, range, &pv, &cnt);
	while (range--)
		do_pb_ra(ab, inst, pv, &cnt);
	set_original_position(ab, inst, cnt.ra_cnt, cnt.rb_cnt);
	quick_sort_deque(ab, cnt.ra_cnt, inst);
	quick_sort_deque2(ab, cnt.rb_cnt, inst);
	quick_sort_deque2(ab, cnt.pb_cnt - cnt.rb_cnt, inst);
}

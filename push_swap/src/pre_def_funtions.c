/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_def_funtions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:06 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:47:08 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	case_321(t_deque_set *ab, t_deque *inst)
{
	sa(&ab->a, 1, inst);
	rra(&ab->a, 1, inst);
}

static void	case_132(t_deque_set *ab, t_deque *inst)
{
	rra(&ab->a, 1, inst);
	sa(&ab->a, 1, inst);
}

static void	pre_def_three(t_deque_set *ab, t_deque *inst)
{
	t_node	*p1;
	t_node	*p2;
	t_node	*p3;

	p1 = ab->a.tail;
	p2 = ab->a.tail->prev;
	p3 = ab->a.tail->prev->prev;
	if ((p1->val >= p2->val) && (p2->val >= p3->val))
		case_321(ab, inst);
	else if ((p1->val >= p2->val) && (p2->val <= p3->val) \
			&& (p1->val >= p3->val))
		ra(&ab->a, 1, inst);
	else if ((p1->val >= p2->val) && (p2->val <= p3->val) \
			&& (p1->val <= p3->val))
		sa(&ab->a, 1, inst);
	else if ((p1->val <= p2->val) && (p2->val <= p3->val))
		return ;
	else if ((p1->val <= p2->val) && (p2->val >= p3->val) \
			&& (p1->val >= p3->val))
		rra(&ab->a, 1, inst);
	else if ((p1->val <= p2->val) && (p2->val >= p3->val) \
			&& (p1->val <= p3->val))
		case_132(ab, inst);
}

static void	pre_def_five(t_deque_set *ab, t_deque *inst)
{
	int		i;
	t_node	*p;

	i = 0;
	while (i < 5)
	{
		p = ab->a.tail;
		if (p->val == 0 || p->val == 1)
			pb(ab, inst);
		else
			ra(&ab->a, 1, inst);
		i++;
	}
	pre_def_three(ab, inst);
	if (ab->b.tail->val < ab->b.tail->prev->val)
		sb(&ab->b, 1, inst);
	pa(ab, inst);
	pa(ab, inst);
}

void	pre_def_funtions(t_deque_set *ab, int num_cnt, t_deque *inst)
{
	if (num_cnt <= 1)
		exit(0);
	if (num_cnt == 2)
	{
		if (ab->a.tail->val > ab->a.tail->prev->val)
			sa(&ab->a, 1, inst);
	}
	if (num_cnt == 3)
		pre_def_three(ab, inst);
	if (num_cnt == 5)
		pre_def_five(ab, inst);
}

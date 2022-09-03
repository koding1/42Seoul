/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_rules1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:46:33 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:46:34 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	a_case_1(t_deque_set *ab, t_deque *inst)
{
	sa(&ab->a, 1, inst);
	pb(ab, inst);
	sa(&ab->a, 1, inst);
	ra(&ab->a, 1, inst);
	pa(ab, inst);
	rra(&ab->a, 1, inst);
}

void	a_case_2(t_deque_set *ab, t_deque *inst)
{
	sa(&ab->a, 1, inst);
	ra(&ab->a, 1, inst);
	sa(&ab->a, 1, inst);
	rra(&ab->a, 1, inst);
}

void	a_case_3(t_deque_set *ab, t_deque *inst)
{
	pb(ab, inst);
	sa(&ab->a, 1, inst);
	ra(&ab->a, 1, inst);
	pa(ab, inst);
	rra(&ab->a, 1, inst);
}

void	a_case_4(t_deque_set *ab, t_deque *inst)
{
	ra(&ab->a, 1, inst);
	sa(&ab->a, 1, inst);
	rra(&ab->a, 1, inst);
}

void	three_sorting_rules_a(t_deque_set *ab, t_deque *inst)
{
	t_node	*p1;
	t_node	*p2;
	t_node	*p3;

	p1 = ab->a.tail;
	p2 = ab->a.tail->prev;
	p3 = ab->a.tail->prev->prev;
	if ((p1->val >= p2->val) && (p2->val >= p3->val))
		a_case_1(ab, inst);
	else if ((p1->val >= p2->val) && (p2->val <= p3->val) \
			&& (p1->val >= p3->val))
		a_case_2(ab, inst);
	else if ((p1->val >= p2->val) && (p2->val <= p3->val) \
			&& (p1->val <= p3->val))
		sa(&ab->a, 1, inst);
	else if ((p1->val <= p2->val) && (p2->val <= p3->val))
		return ;
	else if ((p1->val <= p2->val) && (p2->val >= p3->val) \
			&& (p1->val >= p3->val))
		a_case_3(ab, inst);
	else if ((p1->val <= p2->val) && (p2->val >= p3->val) \
			&& (p1->val <= p3->val))
		a_case_4(ab, inst);
}

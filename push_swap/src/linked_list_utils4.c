/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:56:56 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:45:25 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	try_compression(t_deque *deq, t_node *p)
{
	if ((p->val == SA && p->next->val == SB)
		|| (p->val == SB && p->next->val == SA))
		return (compression(deq, p, SS));
	if ((p->val == RA && p->next->val == RB)
		|| (p->val == RB && p->next->val == RA))
		return (compression(deq, p, RR));
	if ((p->val == RRA && p->next->val == RRB)
		|| (p->val == RRB && p->next->val == RRA))
		return (compression(deq, p, RRR));
	return (0);
}

int	try_delete(t_deque *deq, t_node *p)
{
	if ((p->val == RA && p->next->val == RRA)
		|| (p->val == RRA && p->next->val == RA))
		return (delete_two_inst(deq, p));
	if ((p->val == RB && p->next->val == RRB)
		|| (p->val == RRB && p->next->val == RB))
		return (delete_two_inst(deq, p));
	if ((p->val == SA && p->next->val == SA)
		|| (p->val == SB && p->next->val == SB))
		return (delete_two_inst(deq, p));
	if ((p->val == RR && p->next->val == RRR)
		|| (p->val == RRR && p->next->val == RR))
		return (delete_two_inst(deq, p));
	if ((p->val == PA && p->next->val == PB)
		|| (p->val == PB && p->next->val == PA))
		return (delete_two_inst(deq, p));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:52:24 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/19 16:13:48 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new_last;
	t_list	*start;
	t_list	*tmp;

	start = 0;
	p = lst;
	while (p)
	{
		tmp = ft_lstnew(f(p->content));
		if (!tmp && start != 0)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		if (p == lst)
			start = tmp;
		else
			new_last->next = tmp;
		new_last = tmp;
		p = p->next;
	}
	return (start);
}

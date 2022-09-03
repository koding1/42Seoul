/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_custom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:15:22 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/21 13:13:58 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	*malloc_and_check(size_t size)
{
	void	*p;

	p = (void *)malloc(size);
	if (p == 0)
		error_write_exit();
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:45:08 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:45:13 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	is_unique_array(int *arr, int cnt)
{
	int	i;
	int	j;

	i = 0;
	while (i < cnt)
	{
		j = i + 1;
		while (j < cnt)
		{
			if (arr[i] == arr[j])
				error_write_exit();
			j++;
		}
		i++;
	}
}

void	is_sorting_array(int *arr, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt - 1)
	{
		if (arr[i] > arr[i + 1])
			return ;
		i++;
	}
	exit(2);
}

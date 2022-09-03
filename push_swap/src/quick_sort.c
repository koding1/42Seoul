/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:17 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:47:21 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	init_l_r_pivot(int	*i, int *j, int l, int r)
{
	*i = l;
	*j = r;
	return ((l + r) / 2);
}

void	quick_sort(int *arr, int l, int r)
{
	int	i;
	int	j;
	int	pivot;
	int	tmp;

	pivot = arr[init_l_r_pivot(&i, &j, l, r)];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j--] = tmp;
			i++;
		}
	}
	if (l < j)
		quick_sort(arr, l, j);
	if (i < r)
		quick_sort(arr, i, r);
}

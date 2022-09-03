/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:29:15 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/13 12:41:59 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		dst_tmp = (unsigned char *)dst;
		src_tmp = (unsigned char *)src;
		while (len--)
			*(dst_tmp++) = *(src_tmp++);
	}
	else
	{
		dst_tmp = (unsigned char *)dst + (len - 1);
		src_tmp = (unsigned char *)src + (len - 1);
		while (len--)
			*(dst_tmp--) = *(src_tmp--);
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:43:26 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/13 12:41:59 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	if (dest_len >= dstsize)
		return (ft_strlen(src) + dstsize);
	src_len = 0;
	while (src_len < dstsize - dest_len - 1)
	{
		if (src[src_len] == 0)
			break ;
		dst[dest_len + src_len] = src[src_len];
		src_len++;
	}
	dst[dest_len + src_len] = 0;
	if (src[src_len] != 0)
		src_len = ft_strlen(src);
	return (dest_len + src_len);
}

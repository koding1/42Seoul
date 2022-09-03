/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:32:40 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/13 16:29:47 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (len < dstsize - 1)
	{
		if (src[len] == 0)
			break ;
		dst[len] = src[len];
		len++;
	}
	if (dstsize != 0)
		dst[len] = 0;
	while (src[len] != 0)
		len++;
	return (len);
}

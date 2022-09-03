/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:42:58 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/16 15:36:06 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l2;

	l2 = ft_strlen(needle);
	if (!l2)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	i = 0;
	while ((haystack[i] != 0) && (i + l2 <= len))
	{
		if (ft_strncmp(haystack + i, needle, l2) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}

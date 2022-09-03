/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:18:58 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/13 14:50:24 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	e;

	s = 0;
	e = ft_strlen(s1);
	if (e == 0)
		return (ft_strdup(s1));
	e--;
	while ((s1[s]) && (ft_strchr(set, s1[s]) != 0))
		s++;
	while (ft_strchr(set, s1[e]) != 0)
	{
		e--;
		if (s > e)
			return (ft_strdup(""));
	}
	if (s <= e)
		return (ft_substr(s1, s, e - s + 1));
	else
		return (ft_strdup(""));
}

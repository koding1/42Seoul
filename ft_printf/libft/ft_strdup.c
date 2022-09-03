/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 11:51:30 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/13 12:41:59 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	new_str = (char *)malloc((s1_len + 1) * sizeof(char));
	if (new_str == 0)
		return (0);
	ft_strlcpy(new_str, s1, s1_len + 1);
	return (new_str);
}

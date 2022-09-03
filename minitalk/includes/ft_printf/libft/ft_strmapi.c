/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:09:01 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/13 14:19:10 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*p;
	size_t	i;

	len = ft_strlen(s);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		p[i] = f((unsigned int)i, s[i]);
		i++;
	}
	p[len] = 0;
	return (p);
}

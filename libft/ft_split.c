/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:22:18 by hyujang           #+#    #+#             */
/*   Updated: 2022/03/19 15:56:41 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_strcnt(char const *s, char c)
{
	int		str_cnt;
	char	*p;

	str_cnt = 0;
	p = (char *)s;
	while ((*p))
	{
		if ((*p) == c)
		{
			while ((*p) == c && (*p))
				p++;
		}
		else
		{
			while ((*p) != c && (*p))
				p++;
			str_cnt++;
		}
	}
	return (str_cnt);
}

static int	set_strs(char const *s, char c, char **p, int str_cnt)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (i < str_cnt)
	{
		while (s[j] == c && s[j])
			j++;
		start = j;
		while (s[j] != c && s[j])
			j++;
		p[i] = ft_substr(s, start, j - start);
		if (p[i] == 0)
		{
			j = 0;
			while (j < i)
				free(p[j++]);
			free(p);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		str_cnt;
	char	**p;

	str_cnt = get_strcnt(s, c);
	p = (char **)malloc((str_cnt + 1) * sizeof(char *));
	if (p == 0)
		return (0);
	if (set_strs(s, c, p, str_cnt) == 0)
		return (0);
	p[str_cnt] = 0;
	return (p);
}

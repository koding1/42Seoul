/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:29:57 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/23 17:53:23 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_end(char *buf, int *idx)
{
	int		i;
	int		j;
	char	*tmp;

	i = *idx;
	while (buf[i] != '\n' && buf[i] != 0)
		i++;
	if (buf[i] == '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i - (*idx) + 1));
	if (!tmp)
		return (0);
	j = 0;
	while (j < i - (*idx))
	{
		tmp[j] = buf[j + (*idx)];
		j++;
	}
	tmp[j] = 0;
	*idx = i;
	return (tmp);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcat(char **new_str, char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 + l2 == 0)
		return (-1);
	*new_str = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!(*new_str))
		return (0);
	i = 0;
	while (i < l1)
	{
		(*new_str)[i] = s1[i];
		i++;
	}
	while (i - l1 < l2)
	{
		(*new_str)[i] = s2[i - l1];
		i++;
	}
	(*new_str)[i] = 0;
	return (1);
}

int	set_fd_arr(char **fd_save, int fd, char *s1, char *s2)
{
	char	*tmp;
	int		flag;

	tmp = 0;
	flag = ft_strcat(&tmp, s1, s2);
	free_pointer(&fd_save[fd]);
	if (!flag)
		return (0);
	else if (flag)
	{
		fd_save[fd] = tmp;
		return (1);
	}
	else
		return (-1);
}

int	is_in_new_line(char **nl, char **fd_save, int fd)
{
	int	idx;

	if (!fd_save[fd])
		return (0);
	idx = 0;
	*nl = read_until_end(fd_save[fd], &idx);
	if (!(*nl))
		return (-1);
	if (idx > 0 && (*nl)[idx - 1] == '\n')
	{
		if (!set_fd_arr(fd_save, fd, "", fd_save[fd] + idx))
			return (-1);
		return (1);
	}
	return (0);
}

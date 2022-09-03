/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:29:24 by hyujang           #+#    #+#             */
/*   Updated: 2022/04/08 20:06:16 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_and_set_arr(char **fd_save, int fd, char **buf)
{
	int		size;

	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buf))
		return (-1);
	size = read(fd, *buf, BUFFER_SIZE);
	if (!size || size < 0)
	{
		free_pointer(&fd_save[fd]);
		return (1);
	}
	(*buf)[size] = 0;
	if (fd_save[fd] != 0)
	{
		if (!set_fd_arr(fd_save, fd, fd_save[fd], *buf))
			return (-1);
	}
	else
	{
		if (!ft_strcat(&fd_save[fd], "", *buf))
			return (-1);
	}
	return (0);
}

char	*free_all_save(char **fd_save, char **prev_str)
{
	int	i;

	free_pointer(prev_str);
	i = 0;
	while (i < OPEN_MAX)
		free_pointer(&fd_save[i++]);
	return (0);
}

void	free_pointer(char **p)
{
	if (*p)
	{
		free(*p);
		*p = 0;
	}
}

char	*get_next_line(int fd)
{
	static char	*fd_save[OPEN_MAX] = {0, };
	char		*prev_str;
	int			check;
	char		*buf;

	if (fd < 0 || fd >= OPEN_MAX)
		return (0);
	prev_str = 0;
	while (1)
	{
		check = is_in_new_line(&prev_str, fd_save, fd);
		if (check == -1)
			return (free_all_save(fd_save, &prev_str));
		if (check == 1)
			return (prev_str);
		check = read_and_set_arr(fd_save, fd, &buf);
		free_pointer(&buf);
		if (check == -1)
			return (free_all_save(fd_save, &prev_str));
		if (check == 1 || check == -2)
			return (prev_str);
		free_pointer(&prev_str);
	}
	return (prev_str);
}

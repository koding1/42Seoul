/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:30:09 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/23 16:16:49 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
int		read_and_set_arr(char **fd_save, int fd, char **buf);
char	*free_all_save(char **fd_save, char **prev_str);
char	*read_until_end(char *buf, int *idx);
size_t	ft_strlen(const char *s);
int		ft_strcat(char **new_str, char *s1, char *s2);
int		set_fd_arr(char **fd_save, int fd, char *s1, char *s2);
int		is_in_new_line(char **nl, char **fd_save, int fd);
void	free_pointer(char **p);

#endif

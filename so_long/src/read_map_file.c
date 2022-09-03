/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:46:28 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/26 20:26:08 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	cat_and_free(t_game *game, char *one_line)
{
	char	*tmp;

	if (game->map.map_str)
	{
		if (ft_strcat(&tmp, game->map.map_str, one_line) == ERROR_CODE_NULL)
			return (ERROR_CODE_NULL);
		free(game->map.map_str);
		game->map.map_str = tmp;
	}
	else
		game->map.map_str = one_line;
	game->map.h++;
	return (1);
}

static void	read_map(t_game *game, char *map_name)
{
	int		fd;
	char	*one_line;
	char	*tmp;

	game->map.map_str = 0;
	game->map.h = 0;
	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
	{
		printf("%s%s\n", ERROR_MSG, strerror(errno));
		exit(0);
	}
	while (1)
	{
		one_line = get_next_line(fd);
		if (one_line == 0)
			break ;
		if (rect_checker(game, one_line) == ERROR_CODE_RECT)
			error_check(ERROR_CODE_RECT);
		if (cat_and_free(game, one_line) == ERROR_CODE_NULL)
			error_check(ERROR_CODE_NULL);
		if (game->map.map_str != one_line)
			free(one_line);
	}
	close(fd);
}

static void	set_map(t_game *game, int i, int j)
{
	game->map.data[i][j] = game->map.map_str[i * game->map.w + j] - '0';
	if (game->map.data[i][j] == P_CODE)
	{
		game->cnts.char_cnt++;
		game->char_po.x = j;
		game->char_po.y = i;
	}
	else if (game->map.data[i][j] == C_CODE)
		game->cnts.item_cnt++;
	else if (game->map.data[i][j] == E_CODE)
		game->cnts.exit_cnt++;
	else if (game->map.data[i][j] != 1 && game->map.data[i][j] != 0)
		error_check(ERROR_CODE_DATA);
}

static void	str_to_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->map.data = (int **)malloc((game->map.h) * sizeof(int *));
	if (game->map.data == ERROR_CODE_NULL)
		error_check(ERROR_CODE_NULL);
	while (i < game->map.h)
	{
		game->map.data[i] = (int *)malloc((game->map.w) * sizeof(int));
		if (game->map.data[i] == ERROR_CODE_NULL)
			error_check(ERROR_CODE_NULL);
		j = 0;
		while (j < game->map.w)
			set_map(game, i, j++);
		i++;
	}
}

void	read_map_file(t_game *game, char *map_name)
{
	read_map(game, map_name);
	str_to_map(game);
	is_valid_map(game);
}

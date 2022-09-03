/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:10:30 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/26 21:10:02 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	rect_checker(t_game *game, char *one_line)
{
	if (one_line[ft_strlen(one_line) - 1] == '\n')
		one_line[ft_strlen(one_line) - 1] = 0;
	if (game->map.map_str == 0)
		game->map.w = ft_strlen(one_line);
	if (game->map.w != ft_strlen(one_line))
		return (ERROR_CODE_RECT);
	return (1);
}

void	wall_checker(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.w)
	{
		if (game->map.data[0][i] != 1)
			error_check(ERROR_CODE_WALL);
		if (game->map.data[game->map.h - 1][i] != 1)
			error_check(ERROR_CODE_WALL);
		i++;
	}
	i = 1;
	while (i < game->map.h - 1)
	{
		if (game->map.data[i][0] != 1 || \
			game->map.data[i][game->map.w - 1] != 1)
			error_check(ERROR_CODE_WALL);
		i++;
	}
}

void	exist_checker(t_game *game)
{
	if (game->cnts.exit_cnt < 1)
		error_check(ERROR_CODE_EXIT);
	if (game->cnts.item_cnt < 1)
		error_check(ERROR_CODE_ITEM);
	if (game->cnts.char_cnt != 1)
		error_check(ERROR_CODE_CHAR);
}

void	is_valid_map(t_game *game)
{
	wall_checker(game);
	exist_checker(game);
}

void	error_check(int code)
{
	if (code == 1)
		return ;
	if (code == ERROR_CODE_NULL)
	{
		printf("%s%s\n", ERROR_MSG, "malloc error");
		code = 1;
	}
	else if (code == ERROR_CODE_WALL)
		printf("%s%s\n", ERROR_MSG, "WALL error");
	else if (code == ERROR_CODE_RECT)
		printf("%s%s\n", ERROR_MSG, "RECT error");
	else if (code == ERROR_CODE_EXIT)
		printf("%s%s\n", ERROR_MSG, "EXIT POINT error");
	else if (code == ERROR_CODE_ITEM)
		printf("%s%s\n", ERROR_MSG, "ITEM EXIST error");
	else if (code == ERROR_CODE_CHAR)
		printf("%s%s\n", ERROR_MSG, "STARTING POINT error");
	else if (code == ERROR_CODE_DATA)
		printf("%s%s\n", ERROR_MSG, "DATA error");
	exit(code);
}

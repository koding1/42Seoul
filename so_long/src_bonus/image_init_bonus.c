/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:30:56 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/26 20:59:47 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	*xpm_to_image_and_check(t_game *g, char *path, int *w, int *h)
{
	void	*p;

	p = mlx_xpm_file_to_image(g->mp, path, w, h);
	if (p == ERROR_CODE_NULL)
		error_check(ERROR_CODE_NULL);
	return (p);
}

static void	num_image_set(t_game *g)
{
	g->num[0].img = xpm_to_image_and_check(g, ZERO_IMAGE_PATH, \
	&g->num[0].img_w, &g->num[0].img_h);
	g->num[1].img = xpm_to_image_and_check(g, ONE_IMAGE_PATH, \
	&g->num[1].img_w, &g->num[1].img_h);
	g->num[2].img = xpm_to_image_and_check(g, TWO_IMAGE_PATH, \
	&g->num[2].img_w, &g->num[2].img_h);
	g->num[3].img = xpm_to_image_and_check(g, THREE_IMAGE_PATH, \
	&g->num[3].img_w, &g->num[3].img_h);
	g->num[4].img = xpm_to_image_and_check(g, FOUR_O_IMAGE_PATH, \
	&g->num[4].img_w, &g->num[4].img_h);
	g->num[5].img = xpm_to_image_and_check(g, FIVE_X_IMAGE_PATH, \
	&g->num[5].img_w, &g->num[5].img_h);
	g->num[6].img = xpm_to_image_and_check(g, SIX_IMAGE_PATH, \
	&g->num[6].img_w, &g->num[6].img_h);
	g->num[7].img = xpm_to_image_and_check(g, SEVEN_IMAGE_PATH, \
	&g->num[7].img_w, &g->num[7].img_h);
	g->num[8].img = xpm_to_image_and_check(g, EIGHT_IMAGE_PATH, \
	&g->num[8].img_w, &g->num[8].img_h);
	g->num[9].img = xpm_to_image_and_check(g, NINE_IMAGE_PATH, \
	&g->num[9].img_w, &g->num[9].img_h);
}

static void	cat_image_set(t_game *g)
{
	g->cats[0].img = xpm_to_image_and_check(g, CAT1_IMAGE_PATH, \
	&g->cats[0].img_w, &g->cats[0].img_h);
	g->cats[1].img = xpm_to_image_and_check(g, CAT2_IMAGE_PATH, \
	&g->cats[1].img_w, &g->cats[1].img_h);
	g->cats[2].img = xpm_to_image_and_check(g, CAT3_IMAGE_PATH, \
	&g->cats[2].img_w, &g->cats[2].img_h);
	g->cats[3].img = xpm_to_image_and_check(g, CAT4_IMAGE_PATH, \
	&g->cats[3].img_w, &g->cats[3].img_h);
}

static void	map_image_set(t_game *g)
{
	g->wall.img = xpm_to_image_and_check(g, WALL_IMAGE_PATH, \
	&g->wall.img_w, &g->wall.img_h);
	g->grass.img = xpm_to_image_and_check(g, GRASS_IMAGE_PATH, \
	&g->grass.img_w, &g->grass.img_h);
	g->cat.img = xpm_to_image_and_check(g, CAT_IMAGE_PATH, \
	&g->cat.img_w, &g->cat.img_h);
	g->chest.img = xpm_to_image_and_check(g, CHEST_IMAGE_PATH, \
	&g->chest.img_w, &g->chest.img_h);
	g->chest.visibility = 1;
	g->exit_o.img = xpm_to_image_and_check(g, EXIT_O_IMAGE_PATH, \
	&g->exit_o.img_w, &g->exit_o.img_h);
	g->exit_o.visibility = 0;
	g->exit_x.img = xpm_to_image_and_check(g, EXIT_X_IMAGE_PATH, \
	&g->exit_x.img_w, &g->exit_x.img_h);
	g->exit_x.visibility = 1;
	g->fish.img = xpm_to_image_and_check(g, FISH_IMAGE_PATH, \
	&g->fish.img_w, &g->fish.img_h);
	g->fish.visibility = 1;
}

void	image_set(t_game *g)
{
	map_image_set(g);
	cat_image_set(g);
	num_image_set(g);
}

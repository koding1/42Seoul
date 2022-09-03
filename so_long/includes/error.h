/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:50:19 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/25 21:35:24 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef struct s_data_cnt {
	int	char_cnt;
	int	item_cnt;
	int	exit_cnt;
	int	move_cnt;
	int	sprite_cnt;
}	t_data_cnt;

# define ERROR_MSG "Error\n"
# define ERROR_CODE_NULL 0
# define ERROR_CODE_WALL -1
# define ERROR_CODE_RECT -2
# define ERROR_CODE_EXIT -3
# define ERROR_CODE_ITEM -4
# define ERROR_CODE_CHAR -5
# define ERROR_CODE_DATA -6

#endif

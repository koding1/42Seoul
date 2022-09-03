/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:17:12 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/04 19:23:46 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"
# define END_SIGNAL 42
# define IDLE 0
# define BUSY 1
# define FINISH 2
# define EPSILON 200

typedef struct s_buffer{
	int		cnt;
	char	data;
}	t_buffer;

#endif

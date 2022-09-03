/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:08:43 by hyujang           #+#    #+#             */
/*   Updated: 2022/04/01 15:38:04 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	write_and_get_len(const char *s);
int	print_c(va_list values);
int	print_s(va_list values);
int	print_p(va_list values);
int	print_d(va_list values);
int	print_u(va_list values);
int	print_x(va_list values, int upper);
int	convert_hex(unsigned int num, char *base);

#endif

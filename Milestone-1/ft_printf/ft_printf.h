/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:53:31 by vacuccu           #+#    #+#             */
/*   Updated: 2025/01/29 16:08:39 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_pchar(int c);
int		ft_pstr(char *s);
int		ft_pnbr(int nb);
int		ft_strlen(char *str);
int		ft_pnbr_unsigned(unsigned int n);
int		ft_pnbr_base(unsigned long n, char *base);
int		ft_ppointer(unsigned long *ptr);

#endif
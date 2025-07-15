/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:24:34 by vacuccu           #+#    #+#             */
/*   Updated: 2025/02/12 18:59:52 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ppointer(unsigned long *ptr)
{
	unsigned long	addr;
	int				printed_chars;

	printed_chars = 0;
	if (ptr == NULL)
	{
		printed_chars += ft_pstr("(nil)");
		return (5);
	}
	else
	{
		addr = (unsigned long)ptr;
		printed_chars += ft_pstr("0x");
		printed_chars += ft_pnbr_base(addr, "0123456789abcdef");
	}
	return (printed_chars);
}

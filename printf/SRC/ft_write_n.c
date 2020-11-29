/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 02:03:53 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/27 02:21:55 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_types_n(va_list argptr, t_struct *f)
{
	t_types_n my;

	if (f->flag_l == 1)
		my.long_int_p = va_arg(argptr, long int*);
	else if (f->flag_ll == 1)
		my.long_long_p = va_arg(argptr, long long int*);
	else if (f->flag_hh == 1)
		my.signed_char_p = va_arg(argptr, signed char*);
	else if (f->flag_h == 1)
		my.short_int_p = va_arg(argptr, short int*);
	else
		my.int_p = va_arg(argptr, int*);
	if (f->flag_l == 1)
		*my.long_int_p = f->len_string;
	else if (f->flag_ll == 1)
		*my.long_long_p = f->len_string;
	else if (f->flag_hh == 1)
		*my.signed_char_p = f->len_string;
	else if (f->flag_h == 1)
		*my.short_int_p = f->len_string;
	else
		*my.int_p = f->len_string;
	f->len_string--;
	return (1);
}

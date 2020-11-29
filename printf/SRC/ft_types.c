/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 23:27:42 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/27 01:35:18 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flags(t_struct *f)
{
	if (f->zero == 1 && f->minus == 1)
		f->zero = 0;
	if (f->space == 1 && f->plus == 1)
		f->space = 0;
	if (f->precision < 0)
		f->precision = -1;
	if (f->precision >= 0)
		f->zero = 0;
	if (f->point == 1 && f->precision < 0)
		f->precision = -1;
	if (f->precision_star == 1 && f->precision < 0)
		f->precision = -1;
	return (1);
}

int		ft_types_bonus(va_list argptr, t_struct *f, int i)
{
	if (f->string[i] == 'n')
		return (ft_types_n(argptr, f));
	else if (ft_strnstr(f->string + i, "ll", 2))
		return (ft_parse_ll(f, argptr, i));
	else if (f->string[i] == 'l')
		return (ft_parse_l(f, argptr, i));
	else if (ft_strnstr(f->string + i, "hh", 2))
		return (ft_parse_hh(f, argptr, i));
	else if (f->string[i] == 'h')
		return (ft_parse_h(f, argptr, i));
	return (0);
}

int		ft_types(va_list argptr, t_struct *f, int i)
{
	if (f->string[i] != 'f' && !ft_strnstr(f->string + i, "Lf", 2))
		ft_check_flags(f);
	if (f->string[i] == 'd' || f->string[i] == 'i')
		return (ft_decint(argptr, f));
	else if (f->string[i] == 'c')
		return (ft_char_c(argptr, f, 0));
	else if (f->string[i] == 's')
		return (ft_string(argptr, f));
	else if (f->string[i] == 'u')
		return (ft_undecint(argptr, f));
	else if (f->string[i] == '%')
		return (ft_char_c(argptr, f, 1));
	else if (f->string[i] == 'x' || f->string[i] == 'X')
		return (ft_unhexint(argptr, f, f->string[i]));
	else if (f->string[i] == 'p')
		return (ft_pointer(argptr, f));
	return (ft_types_bonus(argptr, f, i));
}

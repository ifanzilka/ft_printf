/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 02:46:53 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/29 18:40:06 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_l(t_struct *f, va_list argptr, int i)
{
	f->flag_l = 1;
	f->i++;
	i++;
	if (f->string[i] == 'd' || f->string[i] == 'i')
		return (ft_decint(argptr, f));
	else if (f->string[i] == 'u')
		return (ft_undecint(argptr, f));
	else if (f->string[i] == 'x' || f->string[i] == 'X')
		return (ft_unhexint(argptr, f, f->string[i]));
	else if (f->string[i] == 'n')
		return (ft_types_n(argptr, f));
	return (0);
}

int	ft_parse_h(t_struct *f, va_list argptr, int i)
{
	f->flag_h = 1;
	f->i++;
	i++;
	if (f->string[i] == 'd' || f->string[i] == 'i')
		return (ft_decint(argptr, f));
	else if (f->string[i] == 'u')
		return (ft_undecint(argptr, f));
	else if (f->string[i] == 'x' || f->string[i] == 'X')
		return (ft_unhexint(argptr, f, f->string[i]));
	else if (f->string[i] == 'n')
		return (ft_types_n(argptr, f));
	return (0);
}

int	ft_parse_ll(t_struct *f, va_list argptr, int i)
{
	f->flag_ll = 1;
	f->i += 2;
	i += 2;
	if (f->string[i] == 'd' || f->string[i] == 'i')
		return (ft_decint(argptr, f));
	else if (f->string[i] == 'u')
		return (ft_undecint(argptr, f));
	else if (f->string[i] == 'x' || f->string[i] == 'X')
		return (ft_unhexint(argptr, f, f->string[i]));
	else if (f->string[i] == 'n')
		return (ft_types_n(argptr, f));
	return (0);
}

int	ft_parse_hh(t_struct *f, va_list argptr, int i)
{
	f->flag_hh = 1;
	f->i += 2;
	i += 2;
	if (f->string[i] == 'd' || f->string[i] == 'i')
		return (ft_decint(argptr, f));
	else if (f->string[i] == 'u')
		return (ft_undecint(argptr, f));
	else if (f->string[i] == 'x' || f->string[i] == 'X')
		return (ft_unhexint(argptr, f, f->string[i]));
	else if (f->string[i] == 'n')
		return (ft_types_n(argptr, f));
	return (0);
}

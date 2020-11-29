/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 22:04:51 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/27 01:32:01 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_isflags(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '#' || c == '0')
		return (1);
	return (0);
}

static int		ft_get_width(t_struct *f, int i, va_list argptr)
{
	if (f->string[i] == '*')
	{
		f->width = va_arg(argptr, int);
		if (f->width < 0)
		{
			f->minus = 1;
			f->width = f->width * (-1);
		}
		return (++i);
	}
	else if (f->string[i] >= '0' && f->string[i] <= '9')
	{
		f->width = ft_atoi(&(f->string[i]));
		while (f->string[i] >= '0' && f->string[i] <= '9')
			i++;
	}
	return (i);
}

static	int		ft_get_precision(t_struct *f, int i, va_list argptr)
{
	if (f->string[i] == '*')
	{
		f->precision = va_arg(argptr, int);
		f->precision_star = 1;
		++i;
	}
	else if ((f->string[i] >= '0' && f->string[i] <= '9')
			|| f->string[i] == '-')
	{
		f->precision = ft_atoi(&(f->string[i]));
		while ((f->string[i] >= '0' && f->string[i] <= '9')
				|| f->string[i] == '-')
			i++;
	}
	else
		f->precision = 0;
	if (f->precision < 0)
	{
		f->point = 0;
		f->precision = -1;
	}
	return (i);
}

int				ft_parse_format(va_list argptr, t_struct *f, int i)
{
	if (f->string[i] != '\0')
	{
		while (f->string[i] && ft_isflags(f->string[i]))
		{
			if (f->string[i] == '-')
				f->minus = 1;
			else if (f->string[i] == '0')
				f->zero = 1;
			else if (f->string[i] == ' ')
				f->space = 1;
			else if (f->string[i] == '+')
				f->plus = 1;
			else if (f->string[i] == '#')
				f->lattice = 1;
			i++;
		}
		i = ft_get_width(f, i, argptr);
		if (f->string[i] == '.')
		{
			f->point = 1;
			i++;
			i = ft_get_precision(f, i, argptr);
		}
	}
	return (i);
}

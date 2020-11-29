/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:16:39 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/27 01:26:17 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print(t_struct *f, va_list argptr)
{
	int	len;

	len = 0;
	while (f->string[f->i] != '\0')
	{
		if (f->string[f->i] != '%')
		{
			f->len_string++;
			write(1, &f->string[f->i], 1);
		}
		else
		{
			f->i++;
			f->i = ft_parse_format(argptr, f, f->i);
			if ((f->len_string += ft_types(argptr, f, f->i)) < 0)
				return (-1);
			ft_clear_struct(f);
		}
		f->i++;
	}
	len += f->len_string;
	return (len);
}

void	ft_clear_struct(t_struct *f)
{
	f->minus = 0;
	f->plus = 0;
	f->lattice = 0;
	f->space = 0;
	f->point = 0;
	f->stars = 0;
	f->width = 0;
	f->precision = -1;
	f->u = 0;
	f->flag_l = 0;
	f->flag_ll = 0;
	f->flag_h = 0;
	f->flag_hh = 0;
	f->zero = 0;
	f->adress = 0;
}

void	ft_inits_struct(t_struct *f)
{
	f->i = 0;
	f->len_string = 0;
	f->minus = 0;
	f->plus = 0;
	f->lattice = 0;
	f->zero = 0;
	f->space = 0;
	f->point = 0;
	f->stars = 0;
	f->width = 0;
	f->precision = -1;
	f->precision_star = 0;
	f->str = NULL;
	f->const_str = NULL;
	f->u = 0;
	f->adress = 0;
	f->flag_l = 0;
	f->flag_ll = 0;
	f->flag_h = 0;
	f->flag_hh = 0;
}

int		ft_printf(const char *string, ...)
{
	t_struct		*f;
	va_list			argptr;
	int				cnt;

	if (!string)
		return (-1);
	if (!(f = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	if (!(f->string = ft_strdup(string)))
		return (-1);
	va_start(argptr, string);
	ft_inits_struct(f);
	cnt = ft_print(f, argptr);
	free(f->string);
	free(f);
	va_end(argptr);
	return (cnt);
}

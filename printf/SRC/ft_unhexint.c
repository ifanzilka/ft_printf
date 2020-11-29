/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unhexint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:07:34 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/27 02:18:49 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_precision_x(t_struct *f)
{
	int len;

	len = ft_strlen(f->str);
	if (f->xx > 0)
	{
		if (len < f->precision)
		{
			if (!(ft_add_forward(&f->str, '0', f->precision - len)))
				return (-1);
		}
	}
	else
	{
		if (f->precision == 0)
		{
			free(f->str);
			f->str = ft_strdup("");
		}
		else if ((f->precision > 0) && !
			((ft_add_forward(&f->str, '0', f->precision - len))))
			return (-1);
	}
	return (1);
}

static	int		ft_lattice(t_struct *f, char c)
{
	if (f->lattice == 1 && !(f->xx == 0) && (f->zero == 0 ||
		(f->zero == 1 && (int)ft_strlen(f->str) > f->width)))
	{
		if (!(ft_add_forward(&f->str, c, 1))
			|| !(ft_add_forward(&f->str, '0', 1)))
			return (1);
	}
	return (1);
}

static	int		ft_width_x(t_struct *f)
{
	int		len;
	char	c;

	c = ' ';
	if (f->zero == 1)
		c = '0';
	len = ft_strlen(f->str);
	if (f->width > len)
	{
		if (f->minus == 1)
		{
			if (!(ft_add_back(&f->str, c, f->width - len)))
				return (-1);
		}
		else
		{
			if (!(ft_add_forward(&f->str, c, f->width - len)))
				return (-1);
		}
	}
	return (1);
}

static	int		ft_zero_x(t_struct *f, char c)
{
	int		len;
	char	*tmp;

	tmp = ft_itoa_base(f->xx, 16, c);
	len = ft_strlen(tmp);
	if (f->zero == 1 && f->width > len && f->lattice == 1 && f->xx != 0)
	{
		f->str[1] = c;
	}
	free(tmp);
	return (1);
}

int				ft_unhexint(va_list argptr, t_struct *f, char c)
{
	if (f->flag_l == 1)
		f->xx = va_arg(argptr, unsigned long int);
	else if (f->flag_ll == 1)
		f->xx = va_arg(argptr, unsigned long long int);
	else if (f->flag_hh == 1)
		f->xx = va_arg(argptr, unsigned int);
	else
		f->xx = va_arg(argptr, unsigned int);
	if (!(f->str = ft_itoa_base(f->xx, 16, c)))
		return (-1);
	if (!ft_precision_x(f) || !ft_lattice(f, c) || !ft_width_x(f)
			|| !ft_zero_x(f, c))
		return (-1);
	ft_putstr_fd(f->str, 1);
	f->len = ft_strlen(f->str);
	free(f->str);
	return (f->len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 23:35:51 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/27 01:43:24 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_d_precision(t_struct *f)
{
	int		cnt;
	char	*tmp;
	int		i;

	i = 0;
	cnt = 1;
	if (f->precision >= 0)
	{
		cnt = f->precision;
		tmp = (char*)malloc(cnt + 1);
		if (!tmp)
			return (-1);
		while (i < cnt)
			tmp[i++] = '0';
		tmp[i] = 0;
		free(f->str);
		f->str = tmp;
		ft_zero_d(f);
	}
	return (1);
}

static	int		ft_check_precision_d(t_struct *f)
{
	int len;

	len = ft_strlen(f->str);
	if (f->num > 0 && f->point)
	{
		if (len < f->precision)
		{
			if (f->plus == 1)
			{
				if (!(ft_add_forward(&f->str, '0', f->precision - len)))
					return (-1);
				return (1);
			}
			return ((ft_add_forward(&f->str, '0', f->precision - len)));
		}
	}
	else if (f->num < 0 && f->point)
	{
		if (len < f->precision + 1)
			return (ft_precision_add_neg_d(f));
	}
	else
		return (ft_d_precision(f));
	return (1);
}

static	int		ft_neg_width_d(t_struct *f, char c)
{
	int len;

	len = ft_strlen(f->str);
	if (f->precision < 0 && f->zero && f->space)
	{
		if (!ft_add_forward(&f->str, c, f->width - len - 1))
			return (-1);
		if (!ft_add_forward(&f->str, ' ', 1))
			return (-1);
	}
	else if (!(ft_add_forward(&f->str, c, f->width - len)))
		return (-1);
	if (f->zero == 1)
		ft_zero_d(f);
	return (1);
}

static	int		ft_check_width_d(t_struct *f)
{
	int		len;
	int		i;
	char	c;

	c = ' ';
	if (f->zero == 1)
		c = '0';
	i = 0;
	len = ft_strlen(f->str);
	if (f->width > len || (f->width >= len && f->num > 0))
	{
		if (f->minus == 0)
		{
			if (!ft_neg_width_d(f, c))
				return (-1);
		}
		else
		{
			if (!(ft_add_back(&f->str, c, f->width - len)))
				return (-1);
		}
	}
	return (1);
}

int				ft_decint(va_list argptr, t_struct *f)
{
	if (f->flag_l == 1)
		f->num = va_arg(argptr, long int);
	else if (f->flag_ll == 1)
		f->num = va_arg(argptr, long long int);
	else if (f->flag_hh == 1)
		f->num = (signed char)va_arg(argptr, int);
	else if (f->flag_h == 1)
		f->num = (short int)va_arg(argptr, int);
	else
		f->num = va_arg(argptr, int);
	if (!(f->str = ft_itoa_ll(f->num)))
		return (-1);
	if (!(ft_check_precision_d(f)) || !ft_add_plus_d(f) ||
			!ft_add_space_d(f) || !ft_check_width_d(f))
		return (-1);
	f->len = ft_strlen((f->str));
	ft_putstr_fd(f->str, 1);
	free(f->str);
	return (f->len);
}

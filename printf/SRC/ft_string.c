/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:36:37 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/27 02:00:48 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_write_n_c(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}

static	int		ft_prec(t_struct *f, char c)
{
	if (f->width > f->precision)
	{
		if (f->minus == 0)
		{
			ft_write_n_c(c, f->width - f->precision);
			write(1, f->const_str, f->precision);
			return (f->width);
		}
		else
		{
			write(1, f->const_str, f->precision);
			ft_write_n_c(c, f->width - f->precision);
			return (f->width);
		}
	}
	else
	{
		write(1, f->const_str, f->precision);
		return (f->precision);
	}
}

static	int		ft_no_prec(t_struct *f, char c)
{
	int len;

	len = ft_strlen(f->const_str);
	if (f->width > len)
	{
		if (f->minus == 0)
		{
			ft_write_n_c(c, f->width - len);
			write(1, f->const_str, len);
			return (f->width);
		}
		else
		{
			write(1, f->const_str, len);
			ft_write_n_c(c, f->width - len);
			return (f->width);
		}
	}
	else
	{
		write(1, f->const_str, len);
		return (len);
	}
}

static	int		ft_checks_s(t_struct *f)
{
	int		len;
	char	c;

	c = ' ';
	if (f->zero)
		c = '0';
	len = ft_strlen(f->const_str);
	if (f->precision < len && f->precision >= 0)
	{
		return (ft_prec(f, c));
	}
	else
		return (ft_no_prec(f, c));
}

int				ft_string(va_list argptr, t_struct *f)
{
	f->const_str = va_arg(argptr, char*);
	if (!f->const_str)
		f->const_str = "(null)";
	f->len = ft_checks_s(f);
	return (f->len);
}

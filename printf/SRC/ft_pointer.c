/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:42:29 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/27 02:06:05 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_check_width_p(t_struct *f)
{
	int		len;
	int		i;
	char	c;

	c = ' ';
	if (f->zero == 1)
		c = '0';
	i = 0;
	len = ft_strlen(f->str);
	if (f->width > len)
	{
		if (f->minus == 0)
		{
			if (!(ft_add_forward(&f->str, c, f->width - len)))
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

static	int		ft_add_prec(t_struct *f)
{
	int len;

	len = ft_strlen(f->str);
	if (f->precision > len)
	{
		if (!(ft_add_forward(&f->str, '0', f->precision - len)))
			return (-1);
	}
	if (f->adress == 0 && f->precision == 0)
	{
		free(f->str);
		f->str = ft_strdup("");
	}
	return (1);
}

int				ft_pointer(va_list argptr, t_struct *f)
{
	f->adress = va_arg(argptr, unsigned long long int);
	if (!(f->str = ft_itoa_base(f->adress, 16, 'x')))
		return (-1);
	if (!(ft_add_prec(f)) || !(ft_add_forward(&f->str, 'x', 1))
			|| !(ft_add_forward(&f->str, '0', 1)))
		return (-1);
	if (!(ft_check_width_p(f)))
		return (-1);
	ft_putstr_fd(f->str, 1);
	f->len = ft_strlen(f->str);
	free(f->str);
	return (f->len);
}

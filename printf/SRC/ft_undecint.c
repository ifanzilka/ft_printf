/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undecint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:28:07 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/27 02:11:31 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_u_precision(t_struct *f)
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
	}
	return (1);
}

static	int		ft_check_precision_u(t_struct *f)
{
	int	len;

	len = ft_strlen(f->str);
	if (f->u > 0)
	{
		if (len < f->precision)
		{
			return ((ft_add_forward(&f->str, '0', f->precision - len)));
		}
	}
	else
		return (ft_u_precision(f));
	return (1);
}

static	int		ft_check_width_u(t_struct *f)
{
	int		len;
	int		i;
	char	c;

	c = ' ';
	if (f->zero == 1)
		c = '0';
	i = 0;
	len = ft_strlen(f->str);
	if (f->width > len || (f->width >= len && f->u > 0))
	{
		if (f->minus == 0)
		{
			if (!ft_add_forward(&f->str, c, f->width - len))
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

int				ft_undecint(va_list argptr, t_struct *f)
{
	if (f->flag_l == 1)
		f->u = va_arg(argptr, unsigned long int);
	else if (f->flag_ll == 1)
		f->u = va_arg(argptr, unsigned long long int);
	else if (f->flag_hh == 1)
		f->u = va_arg(argptr, unsigned int);
	else
		f->u = va_arg(argptr, unsigned int);
	if (!(f->str = ft_itoa_unsigned_ll(f->u)))
		return (-1);
	if (!(ft_check_precision_u(f)) || !(ft_check_width_u(f)))
		return (-1);
	ft_putstr_fd(f->str, 1);
	f->len = ft_strlen(f->str);
	free(f->str);
	return (f->len);
}

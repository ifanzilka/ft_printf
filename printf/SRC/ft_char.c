/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:55:39 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/27 01:54:49 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_check_width(t_struct *f)
{
	int		i;
	char	c;

	c = ' ';
	if (f->zero == 1)
		c = '0';
	i = 0;
	if (f->width > 1 && f->minus == 0)
	{
		while (i < f->width - 1)
		{
			ft_putchar_fd(c, 1);
			i++;
		}
		ft_putchar_fd(f->c, 1);
	}
	return (1);
}

static	int		ft_check_minus(t_struct *f)
{
	int	i;

	i = 0;
	if (f->width > 1 && f->minus == 1)
	{
		ft_putchar_fd(f->c, 1);
		while (i < f->width - 1)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	return (1);
}

static	int		ft_check_flags_c(t_struct *f)
{
	if (f->width <= 1)
		ft_putchar_fd(f->c, 1);
	return (1);
}

int				ft_char_c(va_list argptr, t_struct *f, int bools)
{
	if (bools == 1)
		f->c = '%';
	else
		f->c = (unsigned char)va_arg(argptr, unsigned int);
	if (!ft_check_width(f) || !ft_check_minus(f) || !ft_check_flags_c(f))
		return (-1);
	f->len = 1;
	if (f->width > 1)
		f->len = f->width;
	return (f->len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decint2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 03:14:56 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/27 01:49:31 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision_add_neg_d(t_struct *f)
{
	char *tmp;
	char *tmp2;
	char *tmp3;

	tmp = ft_create_str('0', f->precision - ft_strlen(f->str) + 1);
	tmp2 = ft_itoa_ll((-1) * f->num);
	if (!tmp || !tmp2)
		return (-1);
	tmp3 = f->str;
	f->str = ft_strjoin(tmp, tmp2);
	if (!f->str)
		return (-1);
	if (!ft_add_forward(&f->str, '-', 1))
		return (-1);
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (1);
}

int		ft_add_space_d(t_struct *f)
{
	if (f->space == 1 && f->num >= 0 && !(f->precision < 0 && f->zero))
	{
		if (!ft_add_forward(&f->str, ' ', 1))
			return (-1);
	}
	return (1);
}

int		ft_add_plus_d(t_struct *f)
{
	char *itoa;

	itoa = ft_itoa(f->num);
	if (!itoa)
		return (-1);
	if (f->plus && f->num >= 0)
	{
		if (!ft_add_forward(&f->str, '+', 1))
		{
			free(itoa);
			return (-1);
		}
	}
	free(itoa);
	return (1);
}

int		ft_zero_d(t_struct *f)
{
	int		i;
	char	c;

	i = 0;
	if ((f->precision >= 0 && ((f->num >= 0 && f->plus) ||
					(f->num < 0 && f->zero))) || (f->zero == 1))
	{
		while (f->str[i] && (f->str[i] != '-' && f->str[i] != '+'))
			i++;
		if (!f->str[i])
			return (1);
		c = f->str[i];
		f->str[i] = '0';
		f->str[0] = c;
	}
	return (1);
}

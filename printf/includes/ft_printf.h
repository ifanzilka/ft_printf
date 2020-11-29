/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:17:49 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/27 01:11:14 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef struct					s_struct
{
	char						*string;
	int							i;
	int							len_string;
	int							minus;
	int							plus;
	int							zero;
	int							lattice;
	int							space;
	int							point;
	int							stars;
	int							width;
	int							precision;
	int							precision_star;
	long long int				num;
	int							*num_n;
	char						*str;
	char						*const_str;
	int							len;
	unsigned char				c;
	unsigned long int			u;
	unsigned long int			xx;
	unsigned long long int		adress;
	double						floats;
	int							flag_l;
	int							flag_ll;
	int							flag_h;
	int							flag_hh;
}								t_struct;

typedef struct					s_types_n
{
	int							*int_p;
	long int					*long_int_p;
	long long int				*long_long_p;
	signed char					*signed_char_p;
	short int					*short_int_p;
}								t_types_n;

void							ft_inits_struct(t_struct *f);
void							ft_clear_struct(t_struct *f);
int								ft_printf(const char *s, ...);
int								ft_parse_format(va_list argptr,
									t_struct *f, int i);
int								ft_types(va_list argptr, t_struct *f, int i);
int								ft_check_flags(t_struct *f);
int								ft_decint(va_list argptr, t_struct *f);
int								ft_precision_add_neg_d(t_struct *f);
int								ft_add_plus_d(t_struct *f);
int								ft_add_space_d(t_struct *f);
int								ft_zero_d(t_struct *f);
int								ft_char_c(va_list argptr, t_struct *f,
									int bools);
int								ft_string(va_list argptr, t_struct *f);
int								ft_undecint(va_list argptr, t_struct *f);
int								ft_unhexint(va_list argptr, t_struct *f,
									char c);
int								ft_pointer(va_list argptr, t_struct *f);
int								ft_types_n(va_list argptr, t_struct *f);
int								ft_parse_l(t_struct *f, va_list argptr, int i);
int								ft_parse_h(t_struct *f, va_list argptr, int i);
int								ft_parse_ll(t_struct *f, va_list argptr, int i);
int								ft_parse_hh(t_struct *f, va_list argptr, int i);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:02:47 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/01 16:20:49 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ENG
*/

/*
** RUS
**
** Функция bzero() записывает n обнуленных байтов в строку s.
** Если n равно нулю, то b zero() ничего не делает.
**
** RETURN
**
** Функция ничего не возвращает.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

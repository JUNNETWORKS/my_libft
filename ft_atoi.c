/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 02:58:56 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/10 02:47:35 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\f' ||
			nptr[i] == '\r' || nptr[i] == '\n' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			np = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(np * num));
}

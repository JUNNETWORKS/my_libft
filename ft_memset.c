/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 00:05:25 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/10 03:32:26 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	int				counter;

	str = (unsigned char*)s;
	counter = (int)n;
	while (counter--)
		*str++ = c;
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:56:41 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/16 01:25:11 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	int				idx;

	mem = (unsigned char*)s;
	idx = 0;
	while (idx < (int)n)
	{
		if (mem[idx] == (unsigned char)c)
			return (mem + idx);
		idx++;
	}
	return (NULL);
}

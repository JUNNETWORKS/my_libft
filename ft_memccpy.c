/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:04:24 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/10 03:10:27 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;
	int				counter;
	int				idx;

	dest_ptr = (unsigned char*)dest;
	src_ptr = (unsigned char*)src;
	counter = (int)n;
	idx = 0;
	while (idx < counter)
	{
		dest_ptr[idx] = src_ptr[idx];
		if (src_ptr[idx] == c)
			return (dest_ptr + idx + 1);
		idx++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:35:52 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/10 03:29:02 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*buf;
	unsigned char	*src_str;
	unsigned char	*dest_str;
	int				n_int;
	int				idx;

	*buf = malloc(n);
	*src_str = (unsigned char*)src;
	*dest_str = (unsigned char*)dest;
	n_int = (int)n;
	idx = 0;
	while (idx < n_int)
	{
		buf[idx] = src_str[idx];
		idx++;
	}
	idx = 0;
	while (idx < n_int)
	{
		dest_str[idx] = buf[idx];
		idx++;
	}
	free(buf);
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:35:52 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/12 19:04:47 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_bytes;
	unsigned char	*dest_bytes;
	int				n_int;
	int				idx;

	if (dest == NULL && src == NULL)
		return (NULL);
	src_bytes = (unsigned char*)src;
	dest_bytes = (unsigned char*)dest;
	n_int = (int)n;
	idx = dest <= src ? 0 : n_int - 1;
	while (idx < n_int && idx >= 0)
	{
		dest_bytes[idx] = src_bytes[idx];
		idx = dest <= src ? idx + 1 : idx - 1;
	}
	return (dest);
}

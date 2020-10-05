/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:25:03 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/06 03:27:30 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	src_i;
	unsigned int	dest_i;
	unsigned int	dest_len;
	unsigned int	src_len;

	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	dest_i = dest_len;
	src_i = 0;
	while (dest_i + 1 < size && src[src_i] != '\0')
	{
		dst[dest_i] = src[src_i];
		dest_i++;
		src_i++;
	}
	dst[dest_i] = '\0';
	return (dest_len + src_len);
}

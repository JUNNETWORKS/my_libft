/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:04:24 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/06 01:24:42 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char* dest_ptr;
	char* src_ptr;
	int counter;
	int idx;

	dest_ptr = (char*) dest;
	src_ptr = (char*) src;
	counter = (int)n;
	idx = 0;

	while (idx < counter)
	{
		dest_ptr[idx] = src_ptr[idx];
		if (src_ptr[idx] == c)
			return (dest_ptr+idx+1);
		idx++;
	}
	return dest;
}
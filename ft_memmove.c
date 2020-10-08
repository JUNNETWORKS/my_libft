/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:35:52 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/09 02:54:43 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *buf = malloc(n);
	unsigned char *src_str = (unsigned char*)src;
	unsigned char *dest_str = (unsigned char*)dest;
	int n_int;
	int idx;
	
	n_int = (int)n;
	idx = 0;
	while (idx < n_int){
		buf[idx] = src_str[idx];
		idx++;
	}
	idx = 0;
	while (idx < n_int){
		dest_str[idx] = buf[idx];
		idx++;
	}
	free(buf);
	return (dest);
}
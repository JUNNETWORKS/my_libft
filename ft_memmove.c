/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:35:52 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/06 01:53:18 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	char *buf = malloc(n);
	char *src_str = (char*)src;
	char *dest_str = (char*)dest;
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
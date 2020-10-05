/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:56:41 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/06 02:30:30 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char* str;
	int idx;
	
	str = (unsigned char*)s;
	idx = 0;
	while (idx < (int)n && str[idx]){
		if (str[idx] == c)
			return (str+idx);
		idx++;
	}
	return (NULL);
}
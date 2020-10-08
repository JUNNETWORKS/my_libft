/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 02:36:40 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/09 02:54:25 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char* 	str1;
	unsigned char* 	str2;
	int				i;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	while (i < (int)n && (*str1 || *str2)){
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
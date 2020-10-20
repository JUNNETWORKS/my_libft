/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 05:09:40 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/20 23:19:49 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int big_len;
	int little_len;
	int i;

	if (*little == '\0')
		return ((char*)big);
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	i = 0;
	while (i <= ((int)len - little_len) && i < big_len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}

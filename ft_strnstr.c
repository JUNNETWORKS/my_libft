/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 05:09:40 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/15 03:41:18 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	substr_in_front(const char *big, const char *little)
{
	int	little_len;
	int	i;

	little_len = ft_strlen(little);
	i = 0;
	while (i < little_len)
	{
		if (big[i] != little[i])
			return (0);
		i++;
	}
	return (1);
}

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
		if (substr_in_front(big + i, little))
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}

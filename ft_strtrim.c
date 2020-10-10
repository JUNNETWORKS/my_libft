/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:19:24 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/11 04:48:49 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		in_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	int				idx;
	int				start;
	int				end;

	if (*s1 == '\0')
		return ("");
	idx = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (in_set(s1[idx], (char*)set))
		start = ++idx;
	idx = ft_strlen(s1) - 1;
	while (in_set(s1[idx], (char*)set))
		end = --idx;
	if (start >= end)
		return ("");
	str = malloc(end - start + 2);
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (start <= end)
		str[idx++] = s1[start++];
	str[idx] = '\0';
	return (str);
}

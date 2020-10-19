/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:19:24 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/19 10:00:30 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	in_set(char c, char *set)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int				idx;
	int				start_idx;
	int				last_idx;

	if (s1 == NULL || *s1 == '\0')
		return (ft_calloc(sizeof(char), 1));
	start_idx = 0;
	idx = 0;
	while (in_set(s1[idx], (char*)set))
		start_idx = ++idx;
	last_idx = ft_strlen(s1) - 1;
	idx = ft_strlen(s1) - 1;
	while (in_set(s1[idx], (char*)set))
		last_idx = --idx;
	if (start_idx >= last_idx)
		return (ft_calloc(sizeof(char), 1));
	return (ft_substr(s1, start_idx, last_idx - start_idx + 1));
}

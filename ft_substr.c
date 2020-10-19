/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 02:36:34 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/17 13:05:01 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	idx;

	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	*substr = '\0';
	if (start >= ft_strlen(s))
		return (substr);
	idx = 0;
	while (idx < len && *(s + start + idx))
	{
		substr[idx] = *(s + start + idx);
		idx++;
	}
	substr[idx] = '\0';
	return (substr);
}

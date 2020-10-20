/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 02:36:34 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/20 16:03:07 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	idx;

	if (!(substr = malloc(len + 1)))
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

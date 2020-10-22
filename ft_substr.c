/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 02:36:34 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/22 18:31:17 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	// size_t			idx;

	if (!(substr = malloc(len + 1)))
		return (NULL);
	*substr = '\0';
	if (start >= ft_strlen(s))
		return (substr);
	// idx = 0;
	// strlcpy()使える
	ft_strlcpy(substr, s + start, len + 1);
	// while (idx < len && *(s + start + idx))
	// {
	// 	substr[idx] = *(s + start + idx);
	// 	idx++;
	// }
	// substr[idx] = '\0';
	return (substr);
}

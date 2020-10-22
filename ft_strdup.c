/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 04:07:10 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/22 18:12:57 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t			s_len;
	char			*new_str;
	// unsigned int	i;

	s_len = ft_strlen(s);
	if (!(new_str = (char*)malloc(s_len + 1)))
		return (NULL);
	// i = 0;
	// while (i < s_len)
	// {
	// 	new_str[i] = s[i];
	// 	i++;
	// }
	// new_str[s_len] = '\0';
	ft_strlcpy(new_str, s, s_len + 1);
	return (new_str);
}

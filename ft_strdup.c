/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 04:07:10 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/20 16:00:27 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	s_len;
	char			*new_str;
	unsigned int	i;

	s_len = ft_strlen(s);
	if (!(new_str = (char*)malloc(s_len + 1)))
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[s_len] = '\0';
	return (new_str);
}

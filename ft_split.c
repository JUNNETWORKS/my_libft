/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 04:52:46 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/12 02:41:15 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dest, char *src, int n)
{
	int		i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

int		get_split_size(char *str, char c)
{
	int		split_size;

	split_size = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (!*str)
			break ;
		while (*str && *str != c)
			str++;
		split_size++;
	}
	return (split_size);
}

char	**split(char **result, char *str, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (!*str)
			break ;
		len = 0;
		while (str[len] && str[len] != c)
			len++;
		result[i] = malloc(sizeof(char) * (len + 1));
		ft_strcpy(result[i], str, len);
		result[i][len] = '\0';
		i++;
		str += len;
	}
	result[i] = NULL;
	return (result);
}

char **ft_split(char const *s, char c)
{
	int		split_size;
	char	**result;

	split_size = get_split_size((char*)s, c);
	result = (char **)malloc(sizeof(char*) * (split_size + 1));
	if (result == NULL)
		return (NULL);
	return (split(result, (char*)s, c));
}

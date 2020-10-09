/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 03:48:56 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/10 02:48:38 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*allocation;
	int				i;

	allocation = malloc(nmemb * size);
	if (allocation == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		allocation[i] = 0;
	return (void *)allocation;
}

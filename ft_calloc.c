/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 03:48:56 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/11 02:28:29 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*allocation;

	allocation = malloc(nmemb * size);
	if (allocation == NULL)
		return (NULL);
	ft_bzero(allocation, nmemb * size);
	return (void *)allocation;
}

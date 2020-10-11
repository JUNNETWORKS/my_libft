/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 02:42:43 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/12 03:03:37 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_digit(int n)
{
	int		digit;

	digit = 0;
	while (n)
	{
		n /= 10;
		digit++;
	}
	if (digit == 0)
		digit++;
	return (digit);
}

char	*ft_itoa(int n)
{
	int		allocation_size;
	int		digit;
	char	*result;
	int		idx;
	long	nl;

	digit = get_digit(n);
	allocation_size = n < 0 ? digit + 2 : digit + 1;
	result = (char*)malloc(allocation_size);
	if (result == NULL)
		return (result);
	result[allocation_size - 1] = '\0';
	nl = (long)n;
	if (nl < 0)
	{
		result[0] = '-';
		nl *= -1;
	}
	idx = allocation_size - 2;
	if (nl == 0)
		result[0] = '0';
	while (nl)
	{
		result[idx] = '0' + (nl % 10);
		nl /= 10;
		idx--;
	}
	return (result);
}
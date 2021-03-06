/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:21:05 by jtanaka           #+#    #+#             */
/*   Updated: 2021/04/02 20:21:10 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_digit(int n)
{
	int		digit;

	if (n == 0)
		return (1);
	digit = 0;
	while (n)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

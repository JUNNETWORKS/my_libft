/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:45:34 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/12 18:18:55 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			allocation_size;
	int			digit;
	char		result[12];
	int			idx;
	long long	nll;

	nll = (long long)n;
	digit = get_digitll(nll);
	allocation_size = n < 0 ? digit + 2 : digit + 1;
	result[allocation_size - 1] = '\0';
	nll = (long long)n;
	if (nll < 0)
	{
		result[0] = '-';
		nll *= -1;
	}
	idx = allocation_size - 2;
	if (nll == 0)
		result[0] = '0';
	while (nll)
	{
		result[idx--] = '0' + (nll % 10);
		nll /= 10;
	}
	ft_putstr_fd(result, fd);
}

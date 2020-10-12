/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:45:15 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/12 21:46:50 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int size;
	
	// if (lst == NULL)
	// 	return (0);
	size = 1;
	while (lst->next != NULL){
		lst = lst->next;
		size++;
	}
	return (size);
}


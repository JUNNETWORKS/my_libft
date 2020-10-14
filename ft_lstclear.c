/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:55:36 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/14 04:19:11 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_tmp;
	t_list	*previous;

	lst_tmp = *lst;
	while (lst_tmp->next != NULL)
	{
		del(lst_tmp->content);
		previous = lst_tmp;
		lst_tmp = lst_tmp->next;
		free(previous);
	}
	del(lst_tmp->content);
	free(lst_tmp);
	*lst = NULL;
}

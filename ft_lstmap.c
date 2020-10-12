/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:03:24 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/12 22:22:54 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	t_list	*new_lst_tmp;

	new_lst = malloc(sizeof(t_list));
	new_lst->content = f(lst->content);
	lst = lst->next;
	while (lst->next != NULL)
	{
		new_lst_tmp->content = f(lst->content);
		new_lst_tmp->next = malloc(sizeof(t_list));
		new_lst_tmp = new_lst_tmp->next;
	}
	new_lst->content = f(lst->content);
	new_lst->next = NULL;
	return (new_lst);
}


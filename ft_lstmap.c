/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:03:24 by jtanaka           #+#    #+#             */
/*   Updated: 2020/10/13 02:52:58 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	new_lst = malloc(sizeof(t_list));
	new_lst->content = f(lst->content);
	lst = lst->next;
	while (lst->next != NULL)
	{
		new_elem->content = f(lst->content);
		if (new_elem->content == NULL)
		{
			lst = lst->next;
			continue;
		}
		new_elem->next = malloc(sizeof(t_list));
		new_elem = new_elem->next;
		lst = lst->next;
	}
	new_elem->content = f(lst->content);
	new_elem->next = NULL;
	return (new_lst);
}

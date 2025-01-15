/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:00:09 by ariyad            #+#    #+#             */
/*   Updated: 2024/11/02 11:09:10 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	root = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
			return (ft_lstclear(&root, del), NULL);
		ft_lstadd_back(&root, new);
		lst = lst->next;
	}
	return (root);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:12:22 by ariyad            #+#    #+#             */
/*   Updated: 2024/11/02 08:15:06 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		pp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = pp;
	}
}

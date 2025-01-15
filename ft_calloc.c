/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:20:49 by ariyad            #+#    #+#             */
/*   Updated: 2024/11/02 08:45:06 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	pp;

	pp = size * count;
	if (size != 0 && pp / size != count)
		return (NULL);
	ptr = malloc(pp);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, pp);
	return (ptr);
}

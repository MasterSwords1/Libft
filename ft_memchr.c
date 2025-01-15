/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:23:03 by ariyad            #+#    #+#             */
/*   Updated: 2024/10/27 04:17:14 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*so;
	size_t			i;

	so = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (so[i] == (unsigned char)c)
			return (&so[i]);
		i++;
	}
	return (NULL);
}

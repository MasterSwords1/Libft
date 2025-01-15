/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:14:15 by ariyad            #+#    #+#             */
/*   Updated: 2024/11/01 20:32:08 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sa;
	unsigned char	*sb;

	if (!s1 && !s2)
		return (0);
	sa = (unsigned char *)s1;
	sb = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (sa[i] != sb[i])
			return (sa[i] - sb[i]);
		i++;
	}
	return (0);
}

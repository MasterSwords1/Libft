/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:52:27 by ariyad            #+#    #+#             */
/*   Updated: 2024/11/01 16:36:11 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!dst && !src)
		return (NULL);
	if (src > dst)
		return (ft_memcpy(dst, src, n));
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n--)
	{
		d[n] = s[n];
	}
	return (d);
}

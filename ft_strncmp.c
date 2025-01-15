/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:17:35 by ariyad            #+#    #+#             */
/*   Updated: 2024/11/01 20:39:39 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sa;
	unsigned char	*sb;

	if (!s1 && !s2)
		return (0);
	sa = (unsigned char *)s1;
	sb = (unsigned char *)s2;
	i = 0;
	while (sa[i] != '\0' && sb[i] != '\0' && sa[i] == sb[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (sa[i] - sb[i]);
}

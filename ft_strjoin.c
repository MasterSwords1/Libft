/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:28:04 by ariyad            #+#    #+#             */
/*   Updated: 2024/10/24 14:08:46 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dst, const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*s1)
	{
		dst[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		dst[i] = *s2;
		i++;
		s2++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join = ft_strcat(join, s1, s2);
	return (join);
}

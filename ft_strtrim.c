/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:32:22 by ariyad            #+#    #+#             */
/*   Updated: 2025/10/08 04:17:47 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	w_len(char const *s, char const *set, long *i, long *j)
{
	while (s[*i] && ft_strchr(set, s[*i]))
		*i += 1;
	while (*j > *i && s[*j] && ft_strchr(set, s[*j]))
		*j -= 1;
	if (*j <= *i)
		return (0);
	return (*j - *i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	long	i;
	long	j;
	long	k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	trim = malloc((w_len(s1, set, &i, &j) + 1) * sizeof(char));
	if (!trim)
		return (trim);
	k = 0;
	while (i <= j && s1[i])
		trim[k++] = s1[i++];
	trim[k] = 0;
	return (trim);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:32:22 by ariyad            #+#    #+#             */
/*   Updated: 2024/11/01 16:30:32 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	ft_isset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (TRUE);
		set++;
	}
	return (FALSE);
}

static size_t	w_len(char const *s, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = ft_strlen(s) - 1;
	count = 0;
	while (ft_isset(s[i], set))
		i++;
	while (ft_isset(s[j], set))
		j--;
	while (s[i] && i <= j)
	{
		i++;
		count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	trim = (char *)malloc((w_len(s1, set) + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	while (ft_isset(s1[i], set))
		i++;
	while (ft_isset(s1[j], set))
		j--;
	k = 0;
	while (s1[i] && i <= j)
		trim[k++] = s1[i++];
	trim[k] = '\0';
	return (trim);
}

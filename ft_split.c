/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:12:16 by ariyad            #+#    #+#             */
/*   Updated: 2024/11/01 20:51:54 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static t_bool	ft_issep(char s, char c)
{
	return (s == c || s == '\0');
}

static size_t	word_c(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_issep(s[i], c) && ft_issep(s[i + 1], c))
			count++;
		i++;
	}
	return (count);
}

static void	freemem(char **split, size_t i)
{
	while (i--)
	{
		free(split[i]);
	}
	free(split);
}

static t_bool	ft_fill(char **split, const char *s, char sep)
{
	size_t	i;
	size_t	pos;
	size_t	count;

	i = 0;
	pos = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_issep(s[i], sep) && ft_issep(s[i + 1], sep))
		{
			split[pos] = ft_substr(s, i - count, count + 1);
			if (!split[pos++])
				return (freemem(split, pos - 1), FALSE);
			count = -1;
		}
		if (!ft_issep(s[i], sep))
			count++;
		i++;
	}
	split[pos] = NULL;
	return (TRUE);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((word_c(s, c) + 1) * sizeof(char *));
	if (!split || !ft_fill(split, s, c))
		return (NULL);
	return (split);
}

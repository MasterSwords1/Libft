/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:33:21 by ariyad            #+#    #+#             */
/*   Updated: 2025/10/08 03:50:39 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_eight(void *d, const void *s)
{
	long		*l;
	const long	*v = s;

	l = d;
	v = s;
	*l = *v;
}

static void	copy_four(void *d, const void *s)
{
	int			*i;
	const int	*v = s;

	i = d;
	v = s;
	*i = *v;
}

static void	copy_two(void *d, const void *s)
{
	short		*sh;
	const short	*v = s;

	sh = d;
	v = s;
	*sh = *v;
}

static void	copy_one(void *d, const void *s)
{
	char		*c;
	const char	*v = s;

	c = d;
	v = s;
	*c = *v;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	void	(*f[4])(void *, const void *);

	if (n == 0)
		return (NULL);
	i = 0;
	f[0] = copy_one;
	f[1] = copy_two;
	f[2] = copy_four;
	f[3] = copy_eight;
	while (i < n)
	{
		if (n - i >= sizeof(long))
			(void)(f[3](dst + i, src + i), i += sizeof(long));
		else if (n - i >= sizeof(int))
			(void)(f[2](dst + i, src + i), i += sizeof(int));
		else if (n - i >= sizeof(short))
			(void)(f[1](dst + i, src + i), i += sizeof(short));
		else
			(void)(f[0](dst + i, src + i), i += sizeof(char));
	}
	return (dst);
}

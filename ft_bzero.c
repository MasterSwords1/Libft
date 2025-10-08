/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:19:30 by ariyad            #+#    #+#             */
/*   Updated: 2025/10/08 03:38:52 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_eight(void *s)
{
	long	*l;

	l = s;
	*l = 0;
}

static void	copy_four(void *s)
{
	int	*i;

	i = s;
	*i = 0;
}

static void	copy_two(void *s)
{
	short	*sh;

	sh = s;
	*sh = 0;
}

static void	copy_one(void *s)
{
	char	*c;

	c = s;
	*c = 0;
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	void	(*f[4])(void *);

	if (n == 0)
		return ;
	i = 0;
	f[0] = copy_one;
	f[1] = copy_two;
	f[2] = copy_four;
	f[3] = copy_eight;
	while (i < n)
	{
		if (n - i >= sizeof(long))
			(void)(f[3](s + i), i += sizeof(long));
		if (n - i >= sizeof(int))
			(void)(f[2](s + i), i += sizeof(int));
		if (n - i >= sizeof(short))
			(void)(f[1](s + i), i += sizeof(short));
		else
			(void)(f[0](s + i), i += sizeof(char));
	}
}

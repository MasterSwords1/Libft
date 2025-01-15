/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:01:18 by ariyad            #+#    #+#             */
/*   Updated: 2024/11/01 16:38:19 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_of(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

static t_bool	check_len(const char *s)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i] == '0')
		i++;
	while (ft_isdigit(s[i + k]))
		k++;
	return (k > ft_strlen("9223372036854775807")
		|| (k == ft_strlen("9223372036854775807")
			&& ft_strncmp(&s[i], "9223372036854775807", k) > 0));
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		num;
	size_t	i;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (check_len(&str[i]))
		return (ft_of(sign));
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sign);
}

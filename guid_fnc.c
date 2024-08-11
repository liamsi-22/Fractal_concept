/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guid_fnc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:07:55 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/08/07 23:08:53 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_isdigit(char nb)
{
	return (nb >= '0' && nb <= '9');
}

static void	ft_error(void)
{
	write(2, "ERROR: Enter a valid numbers", 28);
	exit(EXIT_FAILURE);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	if (('+' == *s || '-' == *s) && *s++ == '-')
		sign = -sign;
	if (!ft_isdigit(*s) && *s != '.')
		ft_error();
	while (*s != '.' && ft_isdigit(*s))
		integer_part = (integer_part * 10) + (*s++ - '0');
	while (*s == '.')
		++s;
	while (ft_isdigit(*s))
	{
		pow /= 10;
		fractional_part = (*s++ - '0') * pow + fractional_part;
	}
	return ((integer_part + fractional_part) * sign);
}

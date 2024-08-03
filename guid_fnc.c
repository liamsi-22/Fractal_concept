/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guid_fnc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:07:55 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/08/03 19:15:21 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (*s1 == *s2) && *s1 && *s2)
	{
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	else
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
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - '0');
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = (*s++ - '0') * pow + fractional_part;
	}
	return ((integer_part + fractional_part) * sign);
}

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (unscaled_num - old_min)
		/ (old_max - old_min) + new_min);
}

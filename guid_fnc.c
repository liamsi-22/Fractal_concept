/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guid_fnc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:07:55 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/07/28 16:50:54 by iel-fagh         ###   ########.fr       */
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

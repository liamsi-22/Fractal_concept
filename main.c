/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:07:58 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/08/07 23:06:14 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_fractal	fract;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || \
	(4 == ac && !ft_strcmp(av[1], "julia")))
	{
		fract.name = av[1];
		if (!ft_strcmp(fract.name, "julia"))
		{
			fract.julia_x = atodbl(av[2]);
			fract.julia_y = atodbl(av[3]);
		}
		fractal_init(&fract);
		fractal_render(&fract);
		mlx_loop(fract.mlx_cnx);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

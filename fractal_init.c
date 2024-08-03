/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:44:04 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/08/03 19:06:18 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	void	malloc_error(void)
{
	perror("problem with malloc");
	exit(EXIT_FAILURE);
}

static	void	data_init(t_fractal *fct)
{
	fct->escape_value = 4;
	fct->iteration = 42;
	fct->shift_x = 0;
	fct->shift_y = 0;
	fct->zoom = 1.0;
}

static	void	event_fnc(t_fractal *fct)
{
	mlx_hook(fct->mlx_wind, KeyPress, KeyPressMask, key_handler, fct);
	mlx_hook(fct->mlx_wind, ButtonPress, ButtonPressMask, mouse_handler, fct);
	mlx_hook(fct->mlx_wind, DestroyNotify, StructureNotifyMask,
		close_handler, fct);
}

void	fractal_init(t_fractal *fct)
{
	fct->mlx_cnx = mlx_init();
	if (fct == NULL)
		malloc_error();
	fct->mlx_wind = mlx_new_window(fct->mlx_cnx, WIDTH, HEIGHT, fct->name);
	if (fct->mlx_wind == NULL)
	{
		mlx_destroy_display(fct->mlx_cnx);
		free(fct->mlx_cnx);
		malloc_error();
	}
	fct->img.img_ptr = mlx_new_image(fct->mlx_cnx, WIDTH, HEIGHT);
	if (fct->img.img_ptr == NULL)
	{
		mlx_destroy_window(fct->mlx_cnx, fct->mlx_wind);
		mlx_destroy_display(fct->mlx_cnx);
		free(fct->mlx_cnx);
		malloc_error();
	}
	fct->img.pixels_ptr = mlx_get_data_addr(fct->img.img_ptr,
			&fct->img.bpp, &fct->img.line_len, &fct->img.endian);
	data_init(fct);
	event_fnc(fct);
}

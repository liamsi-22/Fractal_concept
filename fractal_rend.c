/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_rend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:57:26 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/08/07 22:49:12 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	map(double unscaled_num, double new_min,
					double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (unscaled_num - old_min)
		/ (old_max - old_min) + new_min);
}

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static	void	choose_fractal(t_complex *z, t_complex	*c, t_fractal	*fct)
{
	if (!ft_strcmp(fct->name, "julia"))
	{
		c->x = fct->julia_x;
		c->y = fct->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
		z->x = 0;
		z->y = 0;
	}
}

static	void	handle_pixel(int x, int y, t_fractal *fct)
{
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fct->zoom) + fct->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fct->zoom) + fct->shift_y;
	choose_fractal(&z, &c, fct);
	while (++i < fct->iteration)
	{
		tmp.x = (z.x * z.x) - (z.y * z.y) + c.x;
		tmp.y = (2 * z.x * z.y) + c.y;
		z = tmp;
		if ((z.x * z.x) + (z.y * z.y) > fct->escape_value)
		{
			color = map(i, BLACK, WHITE, fct->iteration);
			my_pixel_put(x, y, &fct->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fct->img, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_cnx, fractal->mlx_wind,
		fractal->img.img_ptr, 0, 0);
}

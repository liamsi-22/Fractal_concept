/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_rend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:57:26 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/07/29 17:00:45 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}



void    handle_pixel(int x, int y, t_fractal *fct)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    i = 0;
    z.x = 0.0;
    z.y = 0.0;

    c.x = map(x, -2, +2, 0, WIDTH) + fct->shift_x;
    c.y = map(y, +2, -2, 0, HEIGHT) + fct->shift_y;
    
    while (i < fct->iteration)
    {
        z = sum_complex(square_complex(z), c);
        
        // is the value escaped
        if ((z.x * z.x) + (z.y *z.y) > fct->escape_value)
        {
            color = map(i, BLACK, WHITE, 0, fct->iteration);
            my_pixel_put(x, y, &fct->img, color);
            return ;
        }
        i++;
    }
    my_pixel_put(x, y, &fct->img, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
    int x;
    int y;
    
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
            handle_pixel(x, y, fractal);
    }
    mlx_put_image_to_window(fractal->mlx_cnx, fractal->mlx_wind, fractal->img.img_ptr, 0, 0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:31:08 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/07/31 09:23:10 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int close_handler(t_fractal *fct)
{
    mlx_destroy_image(fct->mlx_cnx, fct->img.img_ptr);
    mlx_destroy_window(fct->mlx_cnx, fct->mlx_wind);
    mlx_destroy_display(fct->mlx_cnx);
    free(fct->mlx_cnx);
    exit(EXIT_FAILURE);
}

int Key_handler(int keysym, t_fractal  *fct)
{
    if (keysym == XK_Escape)
        close_handler(fct);
    else if (keysym == XK_Left)
        fct->shift_x -= 0.5;
    else if (keysym == XK_Right)
        fct->shift_x += 0.5;
    else if (keysym == XK_Up)
        fct->shift_y += 0.5;
    else if (keysym == XK_Down)
        fct->shift_y -= 0.5;
    else if (keysym == XK_equal)
        fct->iteration += 10;
    else if (keysym == XK_minus)
        fct->iteration -= 10;
    fractal_render(fct);
    return (0);
}

int mouse_handler(int keysym, t_fractal  *fct)
{
    
}
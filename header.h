/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:08:22 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/08/02 17:33:13 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <X11/keysym.h> // Include the header for keysyms
#include <X11/X.h>     // Include X11 header for event constants like KeyPress
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mlx.h"


// define symbols

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
#define HEIGHT 800
#define WIDTH 800


/*
 * COLORS
*/
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// define structs
typedef struct s_complex
{
    // real
    double  x;
    // imaginary
    double  y;
}       t_complex;

typedef struct  s_img
{
    void    *img_ptr;
    char    *pixels_ptr;
    int     bpp;
    int     endian;
    int     line_len;
}       t_img;

typedef struct  s_fractal
{
    // name
    char *name;
    
    // mlx
    void    *mlx_cnx;
    void    *mlx_wind;
    
    // iteration
    int iteration;
    
    // image
    t_img   img;

    //hooks member variables
    double  escape_value;
    
	// double	julia_x;
	// double	julia_y;
    double  shift_x;
    double  shift_y;
    double  zoom;
}       t_fractal;

// helpful funcs
void	putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

// main fnc
void    fractal_init(t_fractal *fct);
void    fractal_render(t_fractal *fractal);

// key handler fnc
int Key_handler(int keysym, t_fractal  *fct);
int	mouse_handler(int button, int x, int y, t_fractal *fct);
int close_handler(t_fractal *fct);

// map scale func
double map(double unscaled_num, double new_min, double new_max, double old_max);

#endif
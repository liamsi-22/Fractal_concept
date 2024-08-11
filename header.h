/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:08:22 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/08/07 22:48:33 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <X11/keysym.h> 
# include <X11/X.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define ERROR_MESSAGE "Please enter \n\t\"./fractol \
	mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
# define HEIGHT 800
# define WIDTH 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

typedef struct s_complex
{
	double	x;
	double	y;
}		t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_cnx;
	void	*mlx_wind;
	int		iteration;
	t_img	img;
	double	escape_value;
	double	julia_x;
	double	julia_y;
	double	shift_x;
	double	shift_y;
	double	zoom;
}		t_fractal;

void	putstr_fd(char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);
double	atodbl(char *s);

void	fractal_init(t_fractal *fct);
void	fractal_render(t_fractal *fractal);

int		key_handler(int keysym, t_fractal *fct);
int		mouse_handler(int button, int x, int y, t_fractal *fct);
int		close_handler(t_fractal *fct);

double	map(double unscaled_num, double new_min,
			double new_max, double old_max);

#endif
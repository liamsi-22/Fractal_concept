/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:07:58 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/07/28 17:17:29 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int ac, char **av)
{
    t_fractal fract;
    
    if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)
    || 4 == ac && !ft_strncmp(av[1], "julia", 5))
    {
        // fract's name
        fract.name = av[1];
        
        // kick off the application
        fractal_init(&fract);

        // rendering the map
        fractal_render(&fract);
        
        // the mlx loop
        mlx_loop(fract.mlx_cnx);
    }
    else
    {
        putstr_fd(ERROR_MESSAGE,STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}
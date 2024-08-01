/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fnc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:20:41 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/07/28 18:24:41 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// mapp scale
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

//sum_complex
// t_complex   sum_complex(t_complex z1, t_complex z2)
// {
//     t_complex   result;

//     result.x = z1.x + z2.x;
//     result.y = z1.y + z2.y;
//     return (result);
// }



//square_complex
// t_complex   square_complex(t_complex z)
// {
//     t_complex   i;

//     i.x = (z.x * z.x) - (z.y * z.y);
//     i.y = 2 * z.x * z.y;
//     return (i);
// }

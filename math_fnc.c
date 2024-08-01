/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fnc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:20:41 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/08/01 20:49:14 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// mapp scale
double map(double unscaled_num, double new_min, double new_max, double old_max)
{
    double old_min;
    
    old_min = 0;
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}
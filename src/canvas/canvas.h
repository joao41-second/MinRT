/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:33:28 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/17 16:03:26 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

typedef union t_color
{
	double red;
	double green;
	double blue;
	int color[3];
} s_color; 

s_color color_new(double red, double green, double blue);

s_color colors_adding(s_color c1,s_color c2);

s_color colors_subtracting(s_color c1,s_color c2);

s_color colors_scalar_multipl(s_color c1,double c2);

s_color colors_multipl(s_color c1,s_color c2);

# define hadamard_product(c1,c2) colors_multipl(c1,c2);

#endif

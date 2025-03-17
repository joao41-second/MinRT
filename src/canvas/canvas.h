/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:33:28 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/17 16:28:07 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

typedef union s_color
{
	double red;
	double green;
	double blue;
	int color[3];
} t_color; 

t_color color_new(double red, double green, double blue);

t_color colors_adding(t_color c1,t_color c2);

t_color colors_subtracting(t_color c1,t_color c2);

t_color colors_scalar_multipl(t_color c1,double c2);

t_color colors_multipl(t_color c1,t_color c2);

# define hadamard_product(c1,c2) colors_multipl(c1,c2);

//------------------------------------------------------//

void canva_inicializ(int x, int y, t_color base);

void canva_set_pixel(int x,int y, t_color base );

void canva_update();

void canva_close();


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:33:28 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/21 23:43:13 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "../miniRT_struct.h"

t_color	c_new(double red, double green, double blue);

t_color	c_adding(t_color c1, t_color c2);

t_color	c_subtracting(t_color c1, t_color c2);

t_color	c_scalar_multipl(t_color c1, double c2);

t_color	c_multipl(t_color c1, t_color c2);

int		c_chek_iqual_color(t_color a, t_color b);

void	c_print(t_color color);

t_color	c_get_color(int color);

double	c_rgb_to_heihte(t_color color);

//------------------------------------------------------//

void	canva_inicializ(t_minirt *rt_struct, int x, int y, t_color base);

void	canva_set_pixel(t_minirt *rt_struct, int x, int y, t_color base);

int		my_mlx_pixel_retunr(t_img_ *data, int x, int y);

void	canva_update(t_minirt *rt_struct);

int		create_trgb( int r, int g, int b);

#endif

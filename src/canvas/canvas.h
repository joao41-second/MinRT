/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:33:28 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/14 00:40:37 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "../miniRT_struct.h"
int	create_trgb(int t, int r, int g, int b);
t_color	c_new(double red, double green, double blue);

t_color	c_adding(t_color c1, t_color c2);

t_color	c_subtracting(t_color c1, t_color c2);

t_color	c_scalar_multipl(t_color c1, double c2);

t_color	c_multipl(t_color c1, t_color c2);

//------------------------------------------------------//

void	canva_inicializ(t_minirt *rt_struct, int x, int y, t_color base);

void	canva_set_pixel(t_minirt *rt_struct, int x, int y, t_color base);

void	canva_update(t_minirt *rt_struct);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:38:04 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/18 09:43:26 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AXIS_H
# define AXIS_H

# include "../miniRT_struct.h"

# define AXIS_SIZE 400
# define AXIS_OFFSET 60
# define AXIS_THICKNESS 2
# define COLOR_X 0x00FF0000  
# define COLOR_Y 0x0000FF00  
# define COLOR_Z 0x000000FF 
# define CUBE_SIZE 0.3 

/**
 * Line drawing data structure
 */
typedef struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_line;

typedef struct s_cube_ctx
{
	t_minirt	*rt;
	t_img_		*target;
	double		(*vertices)[3];
	int			(*edges)[2];
}	t_cube_ctx;

t_point	proj_point(t_camera_ms *cam, t_point point);

void	draw_line(t_img_ *img, t_point start, t_point end, int color);
void	draw_thick_line(t_img_ *img, t_point start, t_point end, int color);
void	init_edges(int edges[12][2]);

void	draw_axis_navigator(t_minirt *rt_struct, t_img_ *target);
void	draw_orientation_cube(t_minirt *rt_struct, t_img_ *target);
void	draw_cube_labels(t_minirt *rt);
#endif
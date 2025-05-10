/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:59:44 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/10 12:29:46 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
#define MINIRT_STRUCT_H

# include "./tuples/tuples.h"
# include "./matrix/matrix.h"
# include "./canvas/canvas_struct.h"
# include "../libft/ft_list/lsit_struct.h"
# include "./ray/ray_struct.h"
# include "./camera/camera.h"
# include "./light/light_struct.h"
# include "./objects/objects.h"

typedef struct s_camera_m
{
	double		x;
	double		y;
	double		field_of_view;

	t_point		loc;
	t_vector	dir;

	t_matrix	tranform_matrix;
	t_matrix	inv_tranform_matrix;
	double		half_width;
	double		half_height;
	double		pixel_size;
}				t_camera_ms;


typedef struct s_world
{
	t_color		ambient;
	t_camera	camera;
	t_light		light;
}				t_world;

typedef struct s_scene
{
	t_object	*objects;
	t_world		world;
}				t_scene;

typedef struct s_minirt
{
	t_canva		canva;
	t_scene		scene;
	t_camera_ms	cam_m;
	t_list_		*word;
	t_ray		c_ray;
	t_light		luz;
	t_ray		cam;
	int			needs_render;
	t_point		point;
	int			x;
	int			y;
}				t_minirt;

#endif

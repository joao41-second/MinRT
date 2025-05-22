/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:59:44 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/22 11:38:10 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "./tuples/tuples.h"
# include "./matrix/matrix.h"
# include "./canvas/canvas_struct.h"
# include "../libft/ft_list/lsit_struct.h"
# include "./ray/ray_struct.h"
# include "./light/light_struct.h"
# include "./objects/objects.h"

typedef enum e_camera_mode
{
	CAM_MODE_R,
	CAM_MODE_J
}	t_camera_mode;

typedef struct s_camera_m
{
	double			x;
	double			y;
	double			field_of_view;

	t_point			origin;
	t_vector		direction;

	t_matrix		tranform_matrix;
	t_matrix		inv_tranform_matrix;
	t_mat_calculate	calculate;

	double			fov;
	double			aspect_ratio;

	double			half_width;
	double			half_height;
	double			pixel_size;
	t_camera_mode	mode;
}	t_camera_ms;

// typedef struct s_camera_m
// {
// 	double		x;
// 	double		y;
// 	double		field_of_view;

// 	t_point		loc;
// 	t_vector	dir;

// 	t_matrix	tranform_matrix;
// 	t_mat_calculate	calculate;
// 	t_matrix	inv_tranform_matrix;
// 	double		half_width;
// 	double		half_height;
// 	double		pixel_size;
// }				t_camera_ms;

typedef struct s_world
{
	t_color		ambient;
	t_camera_ms	camera;
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
	t_camera_ms	camera;
	t_list_		*word;
	t_ray		c_ray;
	t_light		luz;
	t_ray		cam;
	int			needs_render;
	t_point		point;
	t_color		color;
	double		rota_x;
	double		rota_y;

	int			menu;

}				t_minirt;

#endif

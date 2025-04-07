/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:59:44 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/03 12:51:40 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "../libft/ft_list/lsit_struct.h"
# include "./canvas/canvas_struct.h"
# include "./tuples/tuples.h"
# include "./ray/ray_struct.h"
# include "./matrix/matrix.h"
# include "./objects/objects.h"

typedef enum e_obj_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
}	t_obj_type;

typedef struct s_plane
{
	t_vector	point;
	t_vector	normal;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	axis;
	float		diameter;
	float		height;
	t_color		color;
}	t_cylinder;

typedef struct s_object
{
	t_obj_type		type;
	union
	{
		t_plane		plane;
		t_sphere	sphere;
		t_cylinder	cylinder;
	}	u_data;
	struct s_object	*next;
}	t_object;

typedef struct s_camera
{
	float		fov;
	t_vector	pos;
	t_vector	dir;
}	t_camera;

typedef struct s_world
{
	t_color		ambient;
	t_camera	camera;
	t_light		light;
}	t_world;

typedef struct s_scene
{
	t_object	*objects;
	t_world		world;
}	t_scene;
typedef struct s_minirt
{
	t_canva		canva;
	t_scene		scene;
	t_list_		*word;
	t_ray	c_ray;
}	t_minirt;

#endif

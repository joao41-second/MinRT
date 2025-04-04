/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:59:44 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/04 02:46:26 by rerodrig         ###   ########.fr       */
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



typedef struct s_camera
{
	float		fov;
	t_vector	pos;
	t_vector	dir;
}	t_camera;
typedef struct s_light
{
	float		brightness;
	t_color		color;
	t_vector	pos;
}	t_light;
typedef struct s_world
{
	t_color		ambient;
	t_camera	camera;
	t_light		light;
}	t_world;

typedef struct s_scene
{
	int			object_count;
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

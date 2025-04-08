/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:05:57 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/08 16:07:10 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
#define OBJECTS_H

#include "../miniRT_struct.h"
typedef struct s_sphere 
{
	double	ray_s;
	t_point center;
	t_matrix transform;
	t_matrix inv_transform;

		
}	t_sphere;

t_sphere sphere(t_point point_satrt , double ray_s);

typedef struct s_plane
{
	double	ray_s;
	t_point		center;
	t_vector	normal;
	t_color		color;
	t_matrix	transform;
	t_matrix	inv_transform;
}	t_plane;

t_plane create_plane(t_point center , double ray_s);


typedef enum e_obj_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_TRIANGLE,
}	t_obj_type;

typedef struct s_triangle 
{
	t_point p1;
	t_point p2;
	t_point p3;
	t_vector normal;
	t_vector edge1;
	t_vector edge2;
	t_matrix transform;
	t_matrix inv_transform;
} t_triangle;

t_triangle create_triangle(t_point p1, t_point p2, t_point p3);

typedef struct s_object
{
	t_obj_type		type;
	union
	{
		t_plane		plane;
		t_sphere	sphere;
		t_triangle	triangle;
	}	u_data;
	struct s_object	*next;
}	t_object;

t_object *create_object(void *data, t_obj_type type);


#endif

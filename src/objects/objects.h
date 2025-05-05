/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:05:57 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 02:50:03 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
#define OBJECTS_H

#include "../miniRT_struct.h"

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	axis;
	float		diameter;
	float		height;
	t_color		color;
}	t_cylinder;


typedef struct s_mat_values 
{
	double amb;
	double diffuse;
	double specular;
	double shininess;
} t_m_values;

typedef struct s_material
{
	t_color color;
	t_m_values values;
} t_mater;


typedef struct s_sphere 
{
	double	ray_s;
	t_point center;
	t_matrix transform;
	t_matrix inv_transform;	t_matrix inv_transpose ;
	float		diameter;
	t_mater		 matiral;
	
}	t_sphere;

typedef struct s_light
{
	float		brightness;
	t_color		intenstiy;
	t_point		point;
	t_vector	pos;
}	t_light;

t_sphere sphere(t_point point_satrt , double ray_s);

t_mater obj_material_init(t_color intensty,t_m_values values);

t_m_values obj_init_values_material(double ambient ,double diffuse, double sepcular ,double shininess);

void obj_material_print(t_mater mat);

t_light ligth_init(t_color intensty,t_point point);



typedef struct s_plane
{
	double	ray_s;
	t_point		center;
	t_vector	normal;
	t_vector	base_normal;
	t_color		color;
	t_matrix	transform;
	t_matrix	inv_transform;
	t_matrix	inv_transpose;
	t_mater		matiral;
}	t_plane;




t_plane create_plane(t_point center , double ray_s);


typedef enum e_obj_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
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
	t_color		color;
	t_matrix transform;
	t_matrix inv_transform;
	t_matrix	inv_transpose;
	t_mater		 matiral;
} t_triangle;

t_triangle create_triangle(t_point p1, t_point p2, t_point p3);

typedef struct s_object
{
	t_obj_type		type;
	union
	{
		t_plane		plane;
		t_sphere	sphere;
		t_cylinder	cylinder;
		t_triangle	triangle;
	}	u_data;
	struct s_object	*next;
}	t_object;

t_object *create_object(void *data, t_obj_type type);

#endif

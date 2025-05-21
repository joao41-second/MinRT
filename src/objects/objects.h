/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:05:57 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/21 22:39:30 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "../miniRT_struct.h"

typedef struct s_cylinder
{
	t_point		center;
	t_vector	orientation;
	double		radius;
	double		height;
	double		minimum;
	double		maximum;
	int			closed;
}					t_cylinder;

typedef struct s_mat_values
{
	double			amb;
	double			diffuse;
	double			specular;
	double			shininess;
}					t_m_values;

typedef struct s_material
{
	t_color			color;
	t_color			pattern;
	t_color			pattern_b;
	t_m_values		values;
}					t_mater;

typedef struct s_sphere
{
	double			ray_s;
	t_point			center;
	float			diameter;
}					t_sphere;

typedef struct s_plane
{
	t_point			point1;
	t_point			point2;
	t_point			point3;
	t_vector		normal;
}					t_plane;

typedef struct s_light
{
	float			brightness;
	t_color			intenstiy;
	t_point			point;
}					t_light;

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
}	t_triangle;

typedef union s_matrix_cal
{

	t_matrix 		mat[7];
	struct 
	{
		t_matrix		restl;
		t_matrix		restl_temp;
		t_scaling		scal;
		t_translation		tras;
		t_rotation		rot_x;
		t_rotation		rot_y;
		t_rotation		rot_z;
	};
} 	t_mat_calculate;

typedef struct s_object
{
	t_obj_type		type;
	union
	{
		t_plane		plane;
		t_sphere	sphere;
		t_cylinder	cylinder;
		t_triangle	triangle;
	} u_data;
	t_mater			matiral;
	t_matrix		transform;
	t_matrix		inv_transform;
	t_matrix		inv_transpose;
	
	t_mat_calculate		mat_calculate;

	}					t_object;

t_sphere			sphere(t_point point_satrt, double ray_s);


t_mater	obj_material_init(t_color intensty,t_color pattern ,t_m_values values);

t_m_values			obj_init_values_material(double ambient, double diffuse,
						double sepcular, double shininess);

void				obj_material_print(t_mater mat);

t_light				ligth_init(t_color intensty, t_point point);



t_triangle			create_triangle(t_point p1, t_point p2, t_point p3);
t_cylinder create_cylinder(t_point center, t_vector orientation, double radius, double height);
t_object			*create_object(void *data, t_obj_type type, t_mater mat);

t_plane create_plane(t_point point1,t_point point2 ,t_point point3);

#endif

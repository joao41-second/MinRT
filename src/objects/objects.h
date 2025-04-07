/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:05:57 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/07 12:10:02 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
#define OBJECTS_H

#include "../miniRT_struct.h"

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

#endif

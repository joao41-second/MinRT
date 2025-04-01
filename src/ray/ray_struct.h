/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:37:14 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/01 17:15:58 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RAY_STRUCT_H
#define RAY_STRUCT_H

#include "../miniRT_struct.h"

typedef union s_ray
{
	struct
	{
		t_tuple origin;
		t_tuple direction;
	};
	t_tuple all[2];
} t_ray;

typedef struct s_intersection
{
	void *object;
	double t[2];
	double inter;
	t_ray  ray_start;
	t_tuple point[2];
}	t_intersection;

typedef struct s_limits_range_intersections 
{
	double l_Max_x;
	double l_Nin_x;
	double l_Max_y;
	double l_Nin_y;
	double l_Max_z;
	double l_Nin_z;
	double unit;
} t_limits_range_intersections;

typedef struct s_object_intersectd
{
	void *object;
	t_list_ **ints;
	double max;
	double min;

} t_obj_int;

typedef struct  s_intersections 
{
	t_limits_range_intersections data;	
	t_list_ **objects;
	t_list_ *max;
	t_list_ *min;
} t_intersections;



#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:37:14 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/07 12:28:51 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_STRUCT_H
# define RAY_STRUCT_H

# include "../miniRT_struct.h"
# include "../objects/objects.h"

typedef union s_ray
{
	struct
	{
		t_tuple		origin;
		t_tuple		direction;
	};
	t_tuple			all[2];
}					t_ray;

typedef struct s_intersection
{
	void			*object;
	double			t[2];
	double			inter;
	t_ray			ray_start;
	t_tuple			point[2];
	t_mater			mat;
}					t_intersection;

//________________________________limts______//

typedef struct s_limt
{
	double			l_max;
	double			l_min;

}					t_limit;

typedef struct s_limits_range_intersections
{
	t_limit			x;
	t_limit			y;
	t_limit			z;
	double			unit;
}					t_lim_ran_int;

//------------------------------------------//
typedef struct s_object_intersectd
{
	void			*object;
	t_obj_type		type;
	t_list_			*ints;
	double			max;
	double			min;
	t_mater			mat;

}					t_obj_int;

typedef struct s_intersections
{
	t_lim_ran_int	data;
	t_list_			*inter;
	t_mater			mat;
}					t_intersections;

#endif

/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:11:18 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/03 12:59:18 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include "../miniRT_struct.h"
#include "ray_struct.h"

#define WALL_SIZE 7.0
#define WALL_Z 10.0


t_ray ray_transform(t_ray ray,t_matrix t_matrix);

t_ray ray_gener(t_point point,t_vector dir);

t_point ray_position(t_ray ray_,double nb);

t_intersection ray_int_sphere(t_ray ray,t_sphere shp);

t_tuple ray_ang_to_vect(double x,double y,double z);

t_obj_int ray_for_objects(t_list_ *objs_w,t_ray ray);

void ray_canva( t_minirt *rt_struct);

void ray_set_transform (t_sphere *sph,t_matrix mat);



#endif

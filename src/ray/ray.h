/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:11:18 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/07 21:41:25 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include "../miniRT_struct.h"
#include "ray_struct.h"




t_ray ray_transform(t_ray ray,t_matrix t_matrix);

t_ray ray_gener(t_point point,t_vector dir);

t_point ray_position(t_ray ray_,double nb);

t_intersection ray_int_sphere(t_ray ray,t_sphere shp);
t_intersection ray_int_plane(t_ray ray, t_object *plane);
t_intersection ray_int_object(t_ray ray,t_object obj);

t_tuple ray_ang_to_vect(double x,double y,double z);

t_obj_int ray_for_objects(t_list_ *objs_w,t_ray ray);

void ray_canva(t_point point, t_minirt *rt_struct);

void ray_set_transform (t_sphere *sph,t_matrix mat);
void ray_set_transform_obj (t_object *obj,t_matrix mat);


#endif

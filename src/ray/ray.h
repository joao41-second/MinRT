/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:11:18 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/01 15:17:10 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include "../miniRT_struct.h"

#define WALL_SIZE -10.0

t_ray ray_gener(t_point point,t_vector dir);

t_point ray_position(t_ray ray,double nb);

t_intersection ray_int_sphere(t_ray ray,t_sphere shp);

t_tuple ray_ang_to_vect(double x,double y,double z);

t_obj_int ray_for_objects(t_list_ *objs_w,t_ray ray);

void ray_canva(t_point point, t_minirt *rt_struct);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:57:01 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/15 14:33:44 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
#define LIGHT_H

#include "../miniRT_struct.h"
#include "light_struct.h"

t_vector lig_normalize(t_object *obj,t_point p_the_obj) ;

t_vector lig_reflect(t_vector in ,t_vector normal);


t_color lig_lighting(t_mater mat,t_light luz,t_point point,t_vector norm,t_tuple eyev);

t_computations lig_prepare_computations( t_obj_int inter,t_ray ray);

t_color lig_color_at(t_minirt *rt_struct, t_ray ray);

#endif


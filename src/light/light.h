/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:57:01 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/08 21:01:01 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
#define LIGHT_H

#include "../miniRT_struct.h"

t_vector lig_normalize(t_sphere sph,t_point p_the_obj) ;

t_vector lig_reflect(t_vector in ,t_vector normal);


t_color lig_lighting(t_mater mat,t_light luz,t_point point,t_vector norm,t_tuple eyev);

t_computations lig_prepare_computations( t_obj_int inter,t_ray ray);

t_color lig_color_at(t_minirt *rt_struct, t_ray ray);


void lig_print_tuple(t_tuple tuple);

t_matrix lig_view_transform(t_tuple form,t_tuple to , t_tuple up);
#endif


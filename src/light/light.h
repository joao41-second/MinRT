/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:57:01 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 18:13:32 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "../miniRT_struct.h"

t_matrix		lig_view_transform(t_tuple form, t_tuple to, t_tuple up);

t_vector		lig_normalize(t_object obj, t_point p_the_obj);

t_vector		lig_reflect(t_vector in, t_vector normal);

t_computations	lig_prepare_computations(t_obj_int inter, t_ray ray);

t_color			lig_shade_hit(t_obj_int obj, t_light luz, t_computations comp);

t_color			lig_lighting(t_mater mat, t_light luz, t_computations comp);

t_color			lig_shade_hit(t_obj_int obj, t_light luz, t_computations comp);

t_color			lig_color_at(t_minirt *rt_struct, t_ray ray);

void			lig_print_tuple(t_tuple tuple);

t_color			lig_reflect_color(t_minirt *rt_struct, t_computations comp);

void			lig_set_color_patern(t_mater *mat, t_computations comp);

t_color			lig_loop_ligth(t_minirt *rt_struct, t_obj_int ray_in_obj,
					t_computations compt);

void			lig_set_texture(t_object *test, t_obj_int *ray_in_obj,
					t_computations *compt);
#endif

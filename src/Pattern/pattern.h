/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:59:26 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 16:40:22 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H
# include "../miniRT_struct.h"

t_color		pat_stripe_at(t_point point, char axi, t_color a, t_color b);

t_color		pat_pixe_at(t_point point, t_img_ *img, t_uv *uv);

t_color		pat_pixe_at_triang(t_point point, t_img_ *img, t_triangle *trinange,
				t_uv *ret_uv);

t_vector	pat_nomral_preturb(t_uv uv, t_vector normal, t_img_ *img,
				double vaule_in_mat);

void		pat_set_dp_trinagle(t_point edge0, t_point edge1, t_point edge2,
				float *dp);

t_uv		uv_sacl(t_uv a, float b);

t_uv		uv_add(t_uv a, t_uv b);

#endif

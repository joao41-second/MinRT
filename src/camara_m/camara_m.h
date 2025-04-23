/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camara_m.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:37:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/18 21:36:26 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CAMARA_M
#define  CAMARA_M

#include "../miniRT_struct.h"

void cm_windo_put(t_minirt *rt_struct,int x_,int y_);

t_camera_ms cm_init(double x , double y,double field_of_view,t_matrix tranform);

t_ray cm_ray_for_pixel (t_camera_ms cam, double px, double py);

#endif

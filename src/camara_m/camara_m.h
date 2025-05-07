/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camara_m.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:37:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/07 09:56:58 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMARA_M_H
# define CAMARA_M_H

#include "../miniRT_struct.h"
void		cm_windo_put(t_minirt *rt_struct, int x_, int y_);

t_camera_ms	cm_init(double x, double y, double field_of_view,t_matrix const tranform);

t_ray		cm_ray_for_pixel(t_camera_ms cam, double px, double py);
void		cm_pixel_size(t_camera_ms *ret);
#endif

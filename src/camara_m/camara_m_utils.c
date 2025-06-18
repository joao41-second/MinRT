/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camara_m_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:40:30 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/22 11:34:34 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "../ray/ray_struct.h"

void	cm_pixel_size(t_camera_ms *ret)
{
	double	half_view ;
	double	aspect;

	half_view = tan(ret->field_of_view / 2);
	aspect = ret->x / ret->y;
	if (aspect >= 1)
	{
		ret->half_width = half_view;
		ret->half_height = half_view / aspect;
	}
	else
	{
		ret->half_height = half_view;
		ret->half_width = half_view * aspect;
	}
	ret->pixel_size = (ret->half_width * 2) / ret->x ;
}

t_camera_ms	cm_init(double x, double y, double field_of_view, t_matrix tranform)
{
	t_camera_ms	ret;

	ret.tranform_matrix = tranform;
	ret.inv_tranform_matrix = mat_inv(tranform);
	ret.field_of_view = field_of_view;
	ret.x = x;
	ret.y = y;
	ret.half_width = x;
	ret.half_height = y;
	ret.origin = create_point(0, 0, 0);
	ret.direction = create_vector(0, 0, 0);
	cm_pixel_size(&ret);
	return (ret);
}

void	cm_update(t_camera_ms *cam)
{
	cam->inv_tranform_matrix = mat_inv(cam->tranform_matrix);
}

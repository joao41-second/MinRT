/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camara_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:40:30 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/18 20:44:24 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "camara_m.h"

#include "../minRT.h"

void cm_pixel_size(t_camera_ms *ret)
{
	double half_view ;
	double aspect;

	half_view = tan(ret->field_of_view /2);
	aspect = ret->half_height / ret->half_width;

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
	ret->pixel_size = (ret->half_width * 2) / ret->half_height;
}

t_camera_ms cm_init(double x , double y,double field_of_view,t_matrix tranform)
{
	t_camera_ms ret;

	ret.tranform_matrix = tranform;
	ret.inv_tranform_matrix = mat_inv(tranform);
	ret.field_of_view = field_of_view;
	ret.x = x;
	ret.y = y;
	ret.half_width = x;
	ret.half_height = y;
	ret.loc = create_point(0, 0, 0);
	ret.dir = create_vector(0,0, 1);
	cm_pixel_size(&ret);
	return(ret);
}


t_ray cm_ray_for_pixel (t_camera_ms cam, double px, double py)
{
	t_ray ret;
	double xoffset;
	double yoffset;

	double x_word;
	double y_word;

	t_tuple pixel;
	t_tuple origin;

	xoffset = (px + 0.5) * cam.pixel_size;
	yoffset = (py + 0.5) * cam.pixel_size;

	x_word = cam.half_width - xoffset;
	y_word = cam.half_height - yoffset;

	pixel = mat_x_tuple(create_point(x_word, y_word, -1), cam.inv_tranform_matrix);
	origin = mat_x_tuple(cam.loc, cam.inv_tranform_matrix);

	ret.origin = origin;
	ret.direction = normalize(sub_tuples(pixel,origin));

	return(ret);
}


void cm_windo_put(t_minirt *rt_struct,int x_,int y_)
{
	int x;
	int y;
	t_ray ray;
	t_color color;

	y = -1;
	while (++y < y_) 
	{
		x = -1;
		while (++x < x_) 
		{
			ray = cm_ray_for_pixel(rt_struct->cam_m, x,y);	
	 		color = lig_color_at(rt_struct, ray);
			canva_set_pixel(rt_struct, x, y, color);
		
		}
	
	}

}

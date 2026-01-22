/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camara_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:40:30 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/17 18:45:10 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "../ray/ray_struct.h"

void	cm_pixel_size(t_camera_ms *ret)
{
	static float	half_view ;
	static float	aspect;

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

t_camera_ms	cm_init(double x, double y, double field_of_view
		, t_matrix const tranform)
{
	t_camera_ms	ret;

	ret.tranform_matrix = tranform;
	ret.inv_tranform_matrix = mat_inv(tranform);
	ret.field_of_view = field_of_view;
	ret.x = x;
	ret.y = y;
	ret.half_width = x;
	ret.half_height = y;
	ret.loc = create_point(0, 0, 0);
	ret.dir = create_vector(0, 0, 0);
	cm_pixel_size(&ret);
	return (ret);
}

t_ray	cm_ray_for_pixel(t_camera_ms cam, double px, double py)
{
	t_ray	ret;
	double	xoffset;
	double	yoffset;
	t_tuple	pixel;
	t_tuple	origin;

	xoffset = (px + 0.5) * cam.pixel_size;
	yoffset = (py + 0.5) * cam.pixel_size;
	pixel = mat_x_tuple((t_point){{cam.half_width
			- xoffset, cam.half_height - yoffset, -1, 1}},
			cam.inv_tranform_matrix);
	origin = mat_x_tuple(cam.loc, cam.inv_tranform_matrix);
	ret.origin = origin;
	ret.dir = normalize(sub_tuples(pixel, origin));
	return (ret);
}

void	cm_pixle_paint(t_minirt *rt_struct, int min_y, int min_x, int scal)
{
	int	x;
	int	y;	

	y = -1;
	while (++y < scal)
	{
		x = -1;
		while (++x < scal)
		{
			canva_set_pixel(rt_struct, min_x + x, min_y + y, rt_struct->color);
		}
	}
}


void	cm_windo_put(t_minirt *rt_struct, int min_x , int min_y ,int x_, int y_, int resul )
{
	t_ray	ray;
	int		x;
	int		y;
	t_color c1;

	y = min_y;
	while (y < y_)
	{
		x = min_x;
		while (x < x_)
		{
			ray = cm_ray_for_pixel(rt_struct->cam_m, x, y);
			c1 = lig_color_at(rt_struct, ray,16);
			rt_struct->color = c1;
			cm_pixle_paint(rt_struct, y, x, resul);
			x += resul;	

		}
		y += resul;
	}
}

typedef struct data_thead
{
	int x_;
	int y_;
	int min_y; 
	int min_x; 
	int result;
	t_minirt *rt_struct;
} t_data_thead;


void * thread_windos(void *thead)
{
	t_data_thead *data = (t_data_thead*)thead;
	data->rt_struct->cam = cm_ray_for_pixel(data->rt_struct->cam_m,
			(double)WALL_X , (double)WALL_Y );
	cm_windo_put(data->rt_struct, data->min_x,data->min_y,data->x_,data->y_,data->result);
	
	return NULL;
}

#include <pthread.h>
void	cm_create_frame_thead(t_minirt *rt_struct,int x_, int y_, int resul)
{
	    pthread_t thread0;
	    pthread_t thread1;
	    t_data_thead str_th;
	    t_data_thead str_th2;

	    str_th.result =resul; 
	    str_th.rt_struct = rt_struct;
	    str_th.x_ = x_/2;
	    str_th.y_ = y_; 
	    str_th.min_x = 0; 
	    str_th.min_y = 0; 
		
	    ft_printf(" he max x %d ,y %d \n",x_/2,y_/2);
	    str_th2.result = resul; 
	    str_th2.rt_struct = rt_struct;
 	    str_th2.min_x = x_/2; 
	    str_th2.min_y = 0; 
	    str_th2.x_ = x_;
	    str_th2.y_ = y_; 

	    pthread_create(&thread1, NULL, thread_windos, &str_th2);

	    pthread_create(&thread0, NULL, thread_windos, &str_th);

 	    pthread_join(thread0, NULL);
 	    pthread_join(thread1, NULL);





}

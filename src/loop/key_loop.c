/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:32:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/08 18:06:42 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../minRT.h"

void key_loop(int key, t_minirt *rt_structj)
{

	t_matrix ok ;

	ok = mat_gener_identity(4);

	t_point point = create_point(0,1,-5);
	

	if(key == 119)	
	{
		point.y +=0.008;
	}
	if(key == 115)	
	{
		point.y-=0.008;
	}
	if(key == 100)	
	{
		rt_structj->c_ray.origin.x+=0.008;
	}
	if(key == 97)	
	{
		rt_structj->c_ray.origin.x-=0.008;
	}
	if(key == 120)	
	{
		rt_structj->c_ray.origin.z+=0.008;
	}
	if(key == 122)	
	{
		rt_structj->c_ray.origin.z-=0.008;
	}




	if(key == 65362)
	{
		rt_structj->c_ray.direction.z +=0.1;
	}
	if(key == 65364)
	{
		rt_structj->c_ray.direction.z -=0.1;
	}
	if(key == 65361)
	{
		rt_structj->c_ray.direction.y +=0.1;
	}
	if(key == 65363)
	{
		rt_structj->c_ray.direction.y -=0.1;
	}
	if(key == 99)
	{
		rt_structj->c_ray.direction.x +=0.1;
	}
	if(key == 118)
	{
		rt_structj->c_ray.direction.x -=0.1;
	}

//	t_matrix mat2 = mat_gener_trans(-point.x, -point.y, -point.z);
//	lig_view_transform(point, create_point(0,10,0), create_vector(0, 1, 0),&ok,mat2);

 //       rt_structj->cam_m = cm_init(400, 400, M_PI/2, ok);



	

	printf("key %d %f %f %f \n",key,point.x,point.y,point.z);
}

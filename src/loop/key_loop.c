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
	int x;
x = -5	;
	if(key == 49)
	{
		rt_structj->luz.point = create_point(x, 5, 5);
	}

	if(key == 50)
	{
		rt_structj->luz.point = create_point(x, -5, 5);
	}

	if(key == 51)
	{
		rt_structj->luz.point = create_point(x, -5, -5);
	}

	if(key == 52)
	{
		rt_structj->luz.point = create_point(x, 5, -5);
	}

	if(key == KEY_W)
	{
		rt_structj->point.x +=0.1;
	}

	if(key == KEY_S)
	{
		rt_structj->point.x -=0.1;
	}

	if(key == KEY_D)
	{
		rt_structj->point.y +=0.1;
	}

	if(key == KEY_A)
	{
		rt_structj->point.y -=0.1;
	}



//	t_matrix mat2 = mat_gener_trans(-point.x, -point.y, -point.z);
//	lig_view_transform(point, create_point(0,10,0), create_vector(0, 1, 0),&ok,mat2);

 //       rt_structj->cam_m = cm_init(400, 400, M_PI/2, ok);



	

	printf("key %d %f %f %f \n",key,point.x,point.y,point.z);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:32:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/30 16:51:48 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../minRT.h"
#include <stdio.h>

void key_loop(int key, t_minirt *rt_structj)
{
//	t_matrix ok ;

//	ok = mat_gener_identity(0);


//	t_point point = create_point(0,1,-5);
	static	double x;
	static	double z = -0.8;
	static	double y;
	


	if(key == KEY_W)
	{
		x+=0.01;
	}

	if(key == KEY_S)
	{
		x-=0.01;
	}

	if(key == KEY_D)
	{
	}

	if(key == KEY_A)
	{
	}

	t_matrix ok ;


	ok = mat_gener_identity(4);

	rt_structj->point = create_point(0,0,-2);

	ok = lig_view_transform(rt_structj->point, create_point(0,0,0), create_vector(0, 1,0));
	
	ok = mat_multip( mat_gener_rota('x',x * (180/M_PI)),ok);

        rt_structj->cam_m = cm_init( WALL_X ,WALL_Y , M_PI/2, ok);
	if(is_equal_double(x, 360))
		x = 0;
	printf("rota %f\n",x);




}

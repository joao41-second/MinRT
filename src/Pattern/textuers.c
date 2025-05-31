/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textuers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:43:45 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/31 13:31:15 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minRT.h"
#include <math.h>
#include <stdio.h>

t_color pat_pixe_at(t_point point,t_img_ *img)
{
	t_color color;
	double theta;
	int x = 0;
	int y = 0;
	int col;


	theta = acos(point.x / sqrt(point.x * point.x + point.z * point.z));
	if(point.z < 0 )
		theta = (2 * M_PI) - theta;
	x = (theta /(2*M_PI)) * img->width;
	y = ((1-(1- point.y) /2)) * (img->height-1);
		
		color = c_get_color( my_mlx_pixel_retunr(img, x, y));

	return color;
}

t_uv uv_add(t_uv a , t_uv b)
{
	return ((t_uv){ a.u +b.u , a.v + b.v});
}
t_uv uv_sacl(t_uv a,float b)
{
	return ((t_uv){ a.u *b , a.v * b});
}

t_color pat_pixe_at_triang(t_point point,t_img_ *img,t_triangle *trinange)
{
	t_point edge0;
	t_point edge1;
	t_point edge2;
	float dp[5];
	float denom;
	float beta;
	float gamma;
	float alpha;
	t_uv uv;

	edge2 = sub_tuples(point,trinange->p1);
	edge1 = trinange->edge2;
	edge0 = trinange->edge1;
	dp[0] = dot_product(edge0, edge0);
	dp[1] = dot_product(edge0, edge1);
	dp[2] = dot_product(edge1, edge1);
	dp[3] = dot_product(edge2, edge0);
	dp[4] = dot_product(edge2, edge1);
	denom = (dp[0]*dp[2])-(dp[1]*dp[1]);
	beta = (dp[2]*dp[3]-dp[1]*dp[4])/denom;
	gamma = (dp[0]*dp[4]-dp[1]*dp[3])/denom;
	alpha = 1.0 - beta -gamma;;
	uv = uv_add(uv_add(uv_sacl(trinange->uv1, alpha),uv_sacl(trinange->uv2, beta)),uv_sacl(trinange->uv3, gamma));

	return (c_get_color( my_mlx_pixel_retunr(img, uv.u * img->width-1, uv.v * img->height-1)));
}

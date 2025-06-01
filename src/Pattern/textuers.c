/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textuers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:43:45 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/31 15:17:23 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minRT.h"
#include <math.h>
#include <stdio.h>
#include <strings.h>

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
	t_uv uv;
	uv.u = a.u + b.u;

	uv.v = a.v + b.v;
	return (uv);
}
t_uv uv_sacl(t_uv a,float b)
{
	t_uv uv;
	uv.u = a.u * b;

	uv.v = a.v * b;
	return (uv);
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
	float u;
	float v;
	
	
	uv.u = 0;
	uv.v = 0;
	uv.index = 0;
	edge2 = sub_tuples(point,trinange->p1);
	edge1 = trinange->edge2;
	edge0 = trinange->edge1;
	dp[0] = dot_product(edge0, edge0);
	dp[1] = dot_product(edge1, edge0);
	dp[2] = dot_product(edge1, edge1);
	dp[3] = dot_product(edge2, edge0);
	dp[4] = dot_product(edge2, edge1);
	denom = (dp[0]*dp[2])-(dp[1]*dp[1]);
	beta = (dp[2]*dp[3]-dp[1]*dp[4])/denom;
	gamma = (dp[0]*dp[4]-dp[1]*dp[3])/denom;
	alpha = 1.0 - beta -gamma;;
	uv = uv_add(uv_add(uv_sacl(trinange->uv1, alpha),uv_sacl(trinange->uv2, beta)),uv_sacl(trinange->uv3, gamma));

	if(trinange->uv1.index == 2)
	{
	lig_print_tuple(point);
	printf("\nvaueles1 %f %f \n",trinange->uv1.u,trinange->uv1.v);
	printf("vaueles %f %f \n",trinange->uv2.u,trinange->uv2.v);
	printf("vaueles %f %f \n\n",trinange->uv3.u,trinange->uv3.v);
	printf(" g -%f b- %f a-%f",gamma,beta,alpha);}



// Conversão UV → coordenadas de textura (x,y)
	int x = (int)(uv.u * (img->width - 1));
	int y = (int)((1.0f - uv.v) * (img->height ));  // inverte o eixo Y

// Clamp final (opcional, extra segurança)
	if (x < 0)
		x = 0;
	if (x >= img->width) 
		x = img->width - 1;
	if (y < 0)
		y = 0;
	if (y >= img->height) 
		y = img->height - 1;

	


	return (c_get_color( my_mlx_pixel_retunr(img,  x,y )));
}

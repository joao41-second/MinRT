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

t_color	pat_pixe_at(t_point point, t_img_ *img, t_uv *uv)
{
	int		x;
	int		y;
	int		col;
	double	theta;
	t_color	color;

	x = 0;
	y = 0;
	theta = acos(point.x / sqrt(point.x * point.x + point.z * point.z));
	if (point.z < 0)
		theta = (2 * M_PI) - theta;
	x = (theta / (2 * M_PI)) * img->width;
	y = ((1 - (1 - point.y) / 2)) * (img->height -1);
	color = c_get_color(my_mlx_pixel_retunr(img, x, y));
	if (uv != NULL)
	{
		uv->u = x;
		uv->v = y;
	}
	return (color);
}

t_uv	uv_add(t_uv a, t_uv b)
{
	t_uv	uv;

	uv.u = a.u + b.u;
	uv.v = a.v + b.v;
	return (uv);
}

t_uv	uv_sacl(t_uv a, float b)
{
	t_uv	uv;

	uv.u = a.u * b;
	uv.v = a.v * b;
	return (uv);
}

t_color	pat_pixe_at_triang(t_point point, t_img_ *img, t_triangle *trinange, t_uv *ret_uv)
{
	t_uv	uv;
	float	u;
	float	v;
	t_point	edge0;
	t_point	edge1;
	t_point	edge2;
	float	dp[5];
	float	denom;
	float	beta;
	float	gamma;
	float	alpha;
	int		x;
	int		y;

	uv.u = 0;
	uv.v = 0;
	uv.index = 0;
	edge2 = sub_tuples(point, trinange->p1);
	edge1 = trinange->edge2;
	edge0 = trinange->edge1;
	dp[0] = dot_product(edge0, edge0);
	dp[1] = dot_product(edge1, edge0);
	dp[2] = dot_product(edge1, edge1);
	dp[3] = dot_product(edge2, edge0);
	dp[4] = dot_product(edge2, edge1);
	denom = (dp[0] * dp[2]) - (dp[1] * dp[1]);
	beta = (dp[2] * dp[3] - dp[1] * dp[4]) / denom;
	gamma = (dp[0] * dp[4] - dp[1] * dp[3]) / denom;
	alpha = 1.0 - beta - gamma;
	uv = uv_add(uv_add(uv_sacl(trinange->uv1, alpha),
				uv_sacl(trinange->uv2, beta)), uv_sacl(trinange->uv3, gamma));
	x = (int)(uv.u * (img->width - 1));
	y = (int)((1.0f - uv.v) * (img->height));
	if (x < 0)
		x = 0;
	if (x >= img->width)
		x = img->width - 1;
	if (y < 0)
		y = 0;
	if (y >= img->height)
		y = img->height - 1;
	if (ret_uv != NULL)
	{
		ret_uv->u = x;
		ret_uv->v = y;
	}
	return (c_get_color(my_mlx_pixel_retunr(img, x, y)));
}

t_vector	pat_nomral_preturb(t_uv uv, t_vector normal,
		t_img_ *img, double vaule_in_mat)
{
	t_vector	vect;
	t_color		colors[4];
	float		vaule;
	double		height[4];
	t_uv		uv_;

	vaule = 0.001;
	colors[0] = c_get_color(my_mlx_pixel_retunr(img, uv.u + vaule, uv.v));
	colors[1] = c_get_color(my_mlx_pixel_retunr(img, uv.u - vaule, uv.v));
	colors[2] = c_get_color(my_mlx_pixel_retunr(img, uv.u, uv.v + vaule));
	colors[3] = c_get_color(my_mlx_pixel_retunr(img, uv.u, uv.v - vaule));
	height[0] = c_rgb_to_heihte(colors[0]);
	height[1] = c_rgb_to_heihte(colors[1]);
	height[2] = c_rgb_to_heihte(colors[2]);
	height[3] = c_rgb_to_heihte(colors[3]);
	uv_.u = (height[0] - height[1]) * vaule_in_mat;
	uv_.v = (height[2] - height[3]) * vaule_in_mat;
	vect.x = normal.x + uv_.u;
	vect.y = normal.y ;
	vect.z = normal.z + uv_.v;
	return (normalize(vect));
}

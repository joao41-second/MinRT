/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textuers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:43:45 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/21 23:45:37 by jperpct          ###   ########.fr       */
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

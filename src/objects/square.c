/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:03:08 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/26 14:36:30 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"
#include <stdio.h>

t_point *obj_create_points(t_point p1,t_point p2,t_point p3,t_point p4)
{	
	t_point * points;

	points = ft_malloc(sizeof(t_point)*4, NULL);	
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4; 
	return (points);

}

void obj_square(t_point *points,t_list_ *word,t_mater mat,t_matrix  matrix)
{
	t_object *obj_triangle1;
	t_triangle tmp;

//	word = ft_node_end(word);
	
	tmp = create_triangle(points[0],points[1],points[2]);
	obj_triangle1 = create_object(&tmp, OBJ_SQUARE, mat,NULL);
	obj_triangle1->triangle = ft_malloc(sizeof(t_triangle)*2,NULL);
	obj_triangle1->triangle[0] = create_triangle(points[0],points[1],points[2]);
	obj_triangle1->triangle[1]  = create_triangle(points[3],points[0],points[2]);	


	obj_triangle1->index = 2;
	obj_triangle1->type = OBJ_TRIANGLE;
	ray_set_transform_obj(obj_triangle1, matrix);	
	obj_triangle1->type = OBJ_SQUARE;

	ft_add_node(obj_triangle1,&word);	
}

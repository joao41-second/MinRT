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
	t_triangle tri1;	
	t_triangle tri2;
	t_object *obj_triangle1;
	t_object *obj_triangle2;

	word = ft_node_end(word);
	tri1 = create_triangle(points[0],points[1],points[2]);
	obj_triangle1 = create_object(&tri1, OBJ_TRIANGLE, mat,NULL);
	ray_set_transform_obj(obj_triangle1, matrix);
	ft_add_node(obj_triangle1, &word);
	tri2 = create_triangle(points[3],points[0],points[2]);
	obj_triangle2 = create_object(&tri2, OBJ_TRIANGLE, mat,NULL);
	ray_set_transform_obj(obj_triangle2, matrix);
	ft_add_node(obj_triangle2, &word);
	
}

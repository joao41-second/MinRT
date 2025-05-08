/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:45:40 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/07 11:46:28 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

t_mat_calculate obj_mat_calulate_init()
{
	t_mat_calculate ret;
	int x;

	x = -1;
	while (++x < 6)
	{
		ret.mat[x] = mat_gener(4);	
	}

	return (ret);
}


t_object	*create_object(void *data, t_obj_type type, t_mater mat)
{
	t_object	*obj;

	obj = (t_object *)ft_malloc(sizeof(t_object), NULL);
	obj->type = type;
	obj->transform = mat_gener(4);
	obj->inv_transform = mat_gener(4);
	obj->inv_transpose = mat_gener(4);
	obj->matiral = mat;
	obj->mat_calculate = obj_mat_calulate_init();
	if (type == OBJ_SPHERE)
		obj->u_data.sphere = *(t_sphere *)data;
	else if (type == OBJ_PLANE)
		obj->u_data.plane = *(t_plane *)data;
	else if (type == OBJ_TRIANGLE)
        obj->u_data.triangle = *(t_triangle *)data;
	else if (type == OBJ_CYLINDER)
		obj->u_data.cylinder = *(t_cylinder *)data;
	return (obj);
}

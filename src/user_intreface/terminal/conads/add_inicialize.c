/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_inicialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:03:22 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/21 21:24:36 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minRT.h"
#include "../termianl_stuct.h"
#include <stdio.h>

t_element *cc_add_new_object_elemnt_type()
{
	t_element *element;
	element = ft_malloc(sizeof(t_element)*1, NULL);
	element->opcion = NULL;
	ft_add_node(ft_strdup("sp"),&element->opcion );
	ft_add_node(ft_strdup("plan"),&element->opcion );
	ft_add_node(ft_strdup("triang"),&element->opcion );
	element->opcion = ft_node_start(element->opcion);
	return (element);
}

t_element *cc_add_new_object_elemnt_posicion()
{
	t_element *element;
	element = ft_malloc(sizeof(t_element)*1, NULL);
	element->opcion = NULL;
	ft_add_node(ft_strdup("0.0.0"),&element->opcion );
	ft_add_node(ft_strdup("0.0.5"),&element->opcion );
	ft_add_node(ft_strdup("0.3.5"),&element->opcion );
	element->opcion = ft_node_start(element->opcion);
	return (element);
}

t_comand *cc_add_new_object()
{
	t_comand *add_obj;
	t_point *point;
	int *objc;
	t_mater *mat;
	mat = ft_malloc(sizeof(t_mater), NULL);

	point = ft_malloc(sizeof(t_point), NULL);

	point[0] = create_point(0, 0, 0);
	objc = ft_malloc(sizeof(int), NULL);
	objc[0] = OBJ_SPHERE;
	mat[0] = obj_material_init(c_new(0, 1, 0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));	
	add_obj =  ft_malloc(1*sizeof(t_comand), NULL);
	add_obj->name = "add";
	ft_add_node(cc_add_new_object_elemnt_type(), &add_obj->element);
	ft_add_node(cc_add_new_object_elemnt_posicion(), &add_obj->element);
	add_obj->element = ft_node_start(add_obj->element);
	add_obj->viod1 = point;
	add_obj->viod2 = mat;
	add_obj->viod3 = objc;
	add_obj->exec = ter_exec_obj;
	return (add_obj);
}

void ter_exec_obj(t_user_in *data,void* v1,void*v2,void *v3)
{
	t_point *point;
	int *objc;
	t_mater *mat;
	t_sphere sph;
	t_object *obj;
		
	point = v1;
	objc = v3;
	mat = v2;
	
	printf("ola %d \n",(int)*objc);
	if(*objc == OBJ_SPHERE)
	{
		printf("ola \n");
		sph = sphere(create_point(0, 0, 0), 1);
		obj = create_object(&sph, OBJ_SPHERE, *mat);
		ray_set_transform_obj(obj, mat_gener_scal(1, 1, 1));
		data->word = ft_node_end(data->word);
		ft_add_node(obj,& data->word);	
		data->word = ft_node_start(data->word);
	}

}

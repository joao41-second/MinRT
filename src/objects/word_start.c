/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:35:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/06 13:41:30 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

void	start_word(t_minirt *rt_struct)
{
	t_sphere	sph;
	t_list_		*word_objects;
	t_mater		mat1;
	t_object	*obj_sphere;
	t_point		luz;

	luz = create_point(0, 3, -3);
	mat1 = obj_material_init(c_new(1, 0, 0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));
	word_objects = NULL;
	sph = sphere(create_point(0, 0, 0), 1);
	obj_sphere = create_object(&sph, OBJ_SPHERE, mat1);
	ray_set_transform_obj(obj_sphere, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_sphere, &word_objects);
	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(5, 5, 5), luz);
}

/*void start_word_test(t_minirt  *rt_struct,double ambinet,t_color color)
{
	t_sphere sph;
	t_sphere sph2;	
	t_sphere sph3;
	t_list_ *word_objects;
	t_mater mat;

	t_point luz = create_point(10, -10,10);
	

	word_objects = NULL;
	sph = sphere(create_point(0, 0, 0),1) ;


	mat = obj_material_init(color, 
	obj_init_values_material(ambinet, 0.7, 0.2, 200));
 	t_object *obj_sphere = create_object(&sph, OBJ_SPHERE,mat);
	ray_set_transform_obj(obj_sphere,mat_gener_scal( 1, 1, 1));
	ft_add_node(obj_sphere,&word_objects );

	sph2 = sphere(create_point(0, 0, 0),1) ;
 	t_object *obj_sphere2 = create_object(&sph2, OBJ_SPHERE,mat);
	ray_set_transform_obj(obj_sphere,mat_gener_scal( 1, 1, 1));
	ft_add_node(obj_sphere2,&word_objects);	


	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(1,1,1), luz);	

}*/

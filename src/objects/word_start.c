/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:35:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/23 09:34:53 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

void start_word(t_minirt  *rt_struct)
{
	t_sphere sph;
	t_sphere sph2;
	t_obj_int intr_in_objc;
	t_list_ *word_objects;
	

	word_objects = NULL;
	sph = sphere(create_point(0, 0, 0),1) ;
	ray_set_transform(&sph,mat_gener_scal( 1, 1, 1));
 	t_object *obj_sphere = create_object(&sph, OBJ_SPHERE);
	ft_add_node(obj_sphere,&word_objects );
	sph2 = sphere(create_point(0, 1, 0),1) ;
	ray_set_transform(&sph2,mat_gener_scal(0.5, 0.5, 0.5) );
 	t_object *obj_sphere2 = create_object(&sph2, OBJ_SPHERE);
	ft_add_node(obj_sphere2,&word_objects);	
	t_plane pln = create_plane(create_point(0, 1, 0), 1);
	t_object *obj_plane = create_object(&pln, OBJ_PLANE);
	ray_set_transform_obj(obj_plane,mat_gener_rota('x', -1));
 //	ft_add_node(obj_plane,&word_objects );
//	print_list_(word_objects);	


//
	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(1,1,1), create_point(5, 5, 5));	
	rt_struct->c_ray = ray_gener( create_point(1,1, 0), create_vector(1, 1, 0));


}

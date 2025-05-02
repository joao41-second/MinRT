/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:35:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/01 18:16:33 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

void start_word(t_minirt  *rt_struct)
{
	t_sphere sph;
	t_sphere sph2;	
	t_sphere sph3;
	t_list_ *word_objects;

	t_point luz = create_point(0, 3,-3);
	

	word_objects = NULL;
	sph = sphere(create_point(0, 0, 0),1) ;
	ray_set_transform(&sph,mat_gener_scal( 1, 1, 1));
 	t_object *obj_sphere = create_object(&sph, OBJ_SPHERE);
	ft_add_node(obj_sphere,&word_objects );

	sph2 = sphere(create_point(-0.5, -0.5, -0.5),1) ;
	ray_set_transform(&sph2,mat_gener_scal(1, 1, 1) );
 	t_object *obj_sphere2 = create_object(&sph2, OBJ_SPHERE);
	//ft_add_node(obj_sphere2,&word_objects);	

	sph3 = sphere(luz,1) ;

	ray_set_transform(&sph3,mat_gener_scal(0.3, 0.3, 0.3) );
 	t_object *obj_sphere3 = create_object(&sph3, OBJ_SPHERE);
	//ft_add_node(obj_sphere3,&word_objects);	


	t_plane pln = create_plane(create_point(-10, -10, 0), 0.5);
	t_object *obj_plane = create_object(&pln, OBJ_PLANE);
	ray_set_transform_obj(obj_plane,mat_gener_rota('z', 1));
// 	ft_add_node(obj_plane,&word_objects );


	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(1,1,1), luz);	


}

void start_word_test(t_minirt  *rt_struct,double ambinet,t_color color)
{
	t_sphere sph;
	t_sphere sph2;	
	t_sphere sph3;
	t_list_ *word_objects;

	t_point luz = create_point(-10, 10,-10);
	

	word_objects = NULL;
	sph = sphere(create_point(0, 0, 0),1) ;
	sph.matiral.values.amb = ambinet;


	sph.matiral = obj_material_init(color, obj_init_values_material(ambinet, 0.7, 0.2, 200));
	ray_set_transform(&sph,mat_gener_scal( 1, 1, 1));
 	t_object *obj_sphere = create_object(&sph, OBJ_SPHERE);
	ft_add_node(obj_sphere,&word_objects );

	sph2 = sphere(create_point(0, 0, 0),1) ;
	ray_set_transform(&sph2,mat_gener_scal(0.5, 0.5, 0.5) );
 	t_object *obj_sphere2 = create_object(&sph2, OBJ_SPHERE);
	ft_add_node(obj_sphere2,&word_objects);	


	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(1,1,1), luz);	

}

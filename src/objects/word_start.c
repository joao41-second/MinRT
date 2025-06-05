/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:35:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/31 15:31:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

void	start_word(t_minirt *rt_struct)
{
	t_sphere	sph;
	t_sphere	sph2;
	t_list_		*word_objects;
	t_mater		mat1;
	t_mater		mat2;

	t_mater		mat3;
	t_object	*obj_sphere;
	t_object	*obj_sphere2;
	t_object	*obj_sphere3;
	t_point		luz;

	luz = create_point(0, 0, 0);
	luz = mat_x_tuple(create_point(0, 0, 0),mat_gener_trans(-3, 3, 3));
	mat1 = obj_material_init(c_new(1, 0, 0), c_new(-1, -1, -1),
			obj_init_values_material(0.1, 0.6, 0.3, 100),0);
	word_objects = NULL;
	sph = sphere(create_point(0, 0, 0), 1);
	//obj_sphere = create_object(&sph, OBJ_SPHERE, mat1, NULL);
obj_sphere = create_object(&sph, OBJ_SPHERE, mat1, obj_creat_texture(rt_struct->canva, "./texture/mand.xpm"));
	ray_set_transform_obj(obj_sphere, mat_multip( mat_gener_scal(1, 1, 1), mat_gener_trans(0, 1, 0)));
	ft_add_node(obj_sphere, &word_objects);

	mat2 = obj_material_init(c_new(0.5, 0.5,0.5),c_new(-1, -1, -1),
			obj_init_values_material(0.1, 0.6, 0.3, 100),3);	
	mat3 = obj_material_init(c_new(1, 1, 0),c_new(1, 0, 0),
			obj_init_values_material(0.1, 0.6, 0.3, 100),0);

	t_plane pln = create_plane(create_point(0, -2, 0),  create_point(1, -2, 0), create_point(0,-2 , 5));
	t_object *obj_plane = create_object(&pln, OBJ_PLANE, mat2,NULL);
	ray_set_transform_obj(obj_plane,mat_multip( mat_gener_scal(1, 1, 1), mat_gener_trans(0, 0, 0)));
	ft_add_node(obj_plane,&word_objects );



 	rt_struct->word = word_objects;


//	obj_open_stl_start(rt_struct, "./texture/Gun.obj", mat_multip(  mat_gener_scal(1, 1, 1),mat_gener_trans(0, 1, 0)),mat2);



	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(2, 2, 2), luz);
}

void start_word_test(t_minirt  *rt_struct,double ambinet,t_color color)
{
	t_sphere sph;
	t_sphere sph2;	
	t_sphere sph3;
	t_list_ *word_objects;
	t_mater mat1;

	t_point luz = create_point(-10, 10,-10);
	

	word_objects = NULL;
	sph = sphere(create_point(0, 0, 0),1) ;
	mat1 = obj_material_init(c_new(1, 0, 0),c_new(-1, -1, -1),
			obj_init_values_material(ambinet, 0.7, 0.2, 200),0);

 	t_object *obj_sphere = create_object(&sph, OBJ_SPHERE,mat1,NULL);
	ray_set_transform_obj(obj_sphere, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_sphere,&word_objects );

	sph2 = sphere(create_point(0, 0, 0),1) ;

 	t_object *obj_sphere2 = create_object(&sph2, OBJ_SPHERE,mat1,NULL);

	ray_set_transform_obj(obj_sphere2, mat_gener_scal(1, 1, 1));
//	ft_add_node(obj_sphere2,&word_objects);	
	

	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(1,1,1), luz);	

}

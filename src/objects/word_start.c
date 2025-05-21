/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:35:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/21 22:44:35 by jperpct          ###   ########.fr       */
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
	luz = mat_x_tuple(create_point(0, 0, 0),mat_gener_trans(3, 3, -3));
	mat1 = obj_material_init(c_new(1, 0, 0), c_new(1, 1, 0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));
	word_objects = NULL;
	sph = sphere(create_point(0, 0, 0), 1);
	obj_sphere = create_object(&sph, OBJ_SPHERE, mat1);
	ray_set_transform_obj(obj_sphere, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_sphere, &word_objects);

	mat2 = obj_material_init(c_new(0, 1, 0),c_new(-1, -1, -1),
			obj_init_values_material(0.1, 0.6, 0.3, 100));

	sph2 = sphere(create_point(0, 0, 0), 1);
	obj_sphere2 = create_object(&sph2, OBJ_SPHERE, mat2);
	ray_set_transform_obj(obj_sphere2,mat_multip(mat_multip( mat_gener_scal(1, 2, 2), mat_gener_trans(0, 1, 1)), mat_gener_rota('z', 0.5)));
	ft_add_node(obj_sphere2, &word_objects);
	mat3 = obj_material_init(c_new(1, 1, 0),c_new(1, 0, 0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));

	sph2 = sphere(create_point(0, 0, 0), 1);
	obj_sphere3 = create_object(&sph2, OBJ_SPHERE, mat3);
	ray_set_transform_obj(obj_sphere3,mat_multip( mat_gener_scal(1, 1, 1), mat_gener_trans(0, 0, 2)));
	ft_add_node(obj_sphere3, &word_objects);

	t_plane pln = create_plane(create_point(0, -2, 0),  create_point(1, -2, 0), create_point(0,-2 , 5));

	t_object *obj_plane = create_object(&pln, OBJ_PLANE, mat2);

	ray_set_transform_obj(obj_plane,mat_multip( mat_gener_scal(1, 1, 1), mat_gener_trans(0, -2, 0)));
	ft_add_node(obj_plane,&word_objects );

	t_plane pln2 = create_plane(create_point(5, 0, 0),  create_point(5, 1, 0), create_point(5,0 , 5));
	t_object *obj_plane2 = create_object(&pln2, OBJ_PLANE, mat3);

	//ft_add_node(obj_plane2,&word_objects );

	t_plane pln3 = create_plane(create_point(5, 2, 2),  create_point(5, 2, 1), create_point(5,2 , 5));
	
	t_object *obj_plane3 = create_object(&pln3, OBJ_PLANE, mat2);


	t_cylinder cyl = create_cylinder(create_point(0 ,0, 0), create_vector(0,1, 0), 0.2, 5);	
	t_object *obj_cylinder = create_object(&cyl, OBJ_CYLINDER, mat1);
	obj_cylinder->matiral = obj_material_init(c_new(1.0, 1.0, 0), c_new(-1, -1, -1),obj_init_values_material(0.3, 0.6, 0.3, 200));
	ray_set_transform_obj(obj_cylinder, mat_gener_scal(1, 1, 1));
	//ray_set_transform_obj(obj_cylinder,mat_gener_rota('z', 1));
	ft_add_node(obj_cylinder, &word_objects);

//	ft_add_node(obj_plane3,&word_objects );
	
	t_triangle tri1 = create_triangle(create_point(-0.5, 1, 0), create_point(-0.5, 0, 0), create_point(-0.5, 0, 5));
	t_object *obj_triangle1 = create_object(&tri1, OBJ_TRIANGLE, mat1);
	obj_triangle1->matiral = obj_material_init(c_new(1.0, 0, 1.0),c_new(-1, -1, -1), obj_init_values_material(0.1, 0.6, 0.9, 100));
	ray_set_transform_obj(obj_triangle1, mat_gener_scal(1, 1, 1));
	//ft_add_node(obj_triangle1, &word_objects);

	t_triangle tri2 = create_triangle(create_point(-0.5, 1, 0), create_point(-0.5, 0,5), create_point(-0.5,1 ,5 ));
	t_object *obj_triangle2 = create_object(&tri2, OBJ_TRIANGLE, mat2);
	obj_triangle2->matiral = mat1;
	ray_set_transform_obj(obj_triangle2, mat_gener_scal(1, 1, 1));
//	ft_add_node(obj_triangle2, &word_objects);

	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(1, 1, 1), luz);
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
			obj_init_values_material(ambinet, 0.7, 0.2, 200));

 	t_object *obj_sphere = create_object(&sph, OBJ_SPHERE,mat1);
	ray_set_transform_obj(obj_sphere, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_sphere,&word_objects );

	sph2 = sphere(create_point(0, 0, 0),1) ;

 	t_object *obj_sphere2 = create_object(&sph2, OBJ_SPHERE,mat1);

	ray_set_transform_obj(obj_sphere2, mat_gener_scal(1, 1, 1));
//	ft_add_node(obj_sphere2,&word_objects);	


	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(1,1,1), luz);	

}

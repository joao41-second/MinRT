/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:35:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/09 13:51:13 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

void	init_triangles(t_list_ **word_objects)
{
	t_triangle	tri1;
	t_triangle	tri2;
	t_object	*obj_triangle1;
	t_object	*obj_triangle2;
	t_mater		mat1;

	mat1 = obj_material_init(c_new(1, 0, 0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));
	tri1 = create_triangle(create_point(0, 1, 0), create_point(1, 0, 0),
			create_point(0, 0, 1));
	obj_triangle1 = create_object(&tri1, OBJ_TRIANGLE, mat1);
	obj_triangle1->matiral = obj_material_init(c_new(1.0, 0, 1.0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));
	ray_set_transform_obj(obj_triangle1, mat_multip(
			mat_gener_scal(1.75, 1.75, 1.75), mat_gener_trans(0, 0, 0)));
	ft_add_node(obj_triangle1, word_objects);
	tri2 = create_triangle(create_point(0, 1, 0), create_point(1, 0, 0),
			create_point(1, 1, 0));
	obj_triangle2 = create_object(&tri2, OBJ_TRIANGLE, mat1);
	ray_set_transform_obj(obj_triangle2,
		mat_multip(mat_gener_scal(1.75, 1.75, 1.75), mat_gener_trans(0, 0, 0)));
	ft_add_node(obj_triangle2, word_objects);
}

void	init_cylinders(t_list_ **word_objects)
{
	t_cylinder	cyl;
	t_object	*obj_cylinder;
	t_mater		mat1;

	mat1 = obj_material_init(c_new(1, 0, 0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));
	cyl = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0),
			0.2, 5);
	obj_cylinder = create_object(&cyl, OBJ_CYLINDER, mat1);
	obj_cylinder->matiral = obj_material_init(c_new(1.0, 1.0, 0),
			obj_init_values_material(0.3, 0.6, 0.3, 200));
	ray_set_transform_obj(obj_cylinder, mat_multip(mat_gener_scal(1, 1, 1),
			mat_gener_rota('z', 0)));
	ray_set_transform_obj(obj_cylinder, mat_gener_rota('z', 1));
	ft_add_node(obj_cylinder, word_objects);
}

void	init_spheres(t_list_ **word_objects)
{
	t_sphere	sph;
	t_object	*obj_sphere;
	t_mater		mat1;

	mat1 = obj_material_init(c_new(1, 0, 0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));
	sph = sphere(create_point(0, 0, 0), 1);
	obj_sphere = create_object(&sph, OBJ_SPHERE, mat1);
	ray_set_transform_obj(obj_sphere, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_sphere, word_objects);
}

// pln = create_plane(create_point(0, 0, 0), create_point(1, 0, 0),
// 		create_point(0, 0, 5));
void	init_planes(t_list_ **word_objects)
{
	t_plane		pln;
	t_object	*obj_plane;
	t_mater		mat2;

	mat2 = obj_material_init(c_new(0, 1, 0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));
	pln = create_plane_parser(create_point(0, 0, 0), create_vector(0, 1, 0));
	obj_plane = create_object(&pln, OBJ_PLANE, mat2);
	ray_set_transform_obj(obj_plane, mat_multip(mat_gener_scal(1, 1, 1),
			mat_gener_trans(0, 0, 0)));
	ft_add_node(obj_plane, word_objects);
}

void	start_word(t_minirt *rt_struct)
{
	t_list_		*word_objects;
	t_point		luz;

	word_objects = NULL;
	luz = create_point(0, 0, 0);
	luz = mat_x_tuple(create_point(0, 0, 0), mat_gener_trans(3, 3, -3));
	init_spheres(&word_objects);
	init_planes(&word_objects);
	init_triangles(&word_objects);
	init_cylinders(&word_objects);
	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(1, 1, 1), luz);
}

// void start_word_test(t_minirt  *rt_struct,double ambinet,t_color color)
// {
// 	t_sphere sph;
// 	t_sphere sph2;	
// 	t_sphere sph3;
// 	t_list_ *word_objects;
// 	t_mater mat1;
// 	t_point luz = create_point(-10, 10,-10);
// 	word_objects = NULL;
// 	sph = sphere(create_point(0, 0, 0),1) ;
// 	mat1 = obj_material_init(c_new(1, 0, 0),
// 			obj_init_values_material(ambinet, 0.7, 0.2, 200));
//  	t_object *obj_sphere = create_object(&sph, OBJ_SPHERE,mat1);
// 	ray_set_transform_obj(obj_sphere, mat_gener_scal(1, 1, 1));
// 	ft_add_node(obj_sphere,&word_objects );
// 	sph2 = sphere(create_point(0, 0, 0),1) ;

//  	t_object *obj_sphere2 = create_object(&sph2, OBJ_SPHERE,mat1);

// 	ray_set_transform_obj(obj_sphere2, mat_gener_scal(1, 1, 1));
// //	ft_add_node(obj_sphere2,&word_objects);	
// 	rt_struct->word = ft_node_start(word_objects);
// 	rt_struct->luz = ligth_init(c_new(1,1,1), luz);	
// }

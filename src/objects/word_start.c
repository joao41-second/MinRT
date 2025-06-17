/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:35:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/17 17:45:55 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

void	init_cylinders(t_minirt *rt, t_list_ **word_objects)
{
	t_cylinder	cyl;
	t_object	*obj_cylinder;
	t_mater		mat1;

	mat1 = obj_material_init(c_new(1, 0, 0),c_new(-1, -1, -1),
			obj_init_values_material(0.1, 0.6, 0.3, 100), 0.0);
	cyl = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0),
			0.2, 5);
	obj_cylinder = create_object(&cyl, OBJ_CYLINDER, mat1, obj_creat_texture(rt->canva, NULL));
	obj_cylinder->matiral = obj_material_init(c_new(1.0, 1.0, 0), c_new(-1, -1, -1),
			obj_init_values_material(0.3, 0.6, 0.3, 200),0.0);
	ray_set_transform_obj(obj_cylinder, mat_multip(mat_gener_scal(1, 1, 1),
			mat_gener_rota('z', 0)));
	ray_set_transform_obj(obj_cylinder, mat_gener_rota('z', 1));
	ft_add_node(obj_cylinder, word_objects);
}
void	start_word(t_minirt *rt_struct)
{
	t_sphere	sph;
	t_sphere	sph2;
	t_list_		*word_objects;
	t_mater		mat1;
	t_mater		mat3;
	t_object	*obj_sphere;
	t_object	*obj_sphere2;
	t_point		luz;
	t_plane		pln;
	t_object	*obj_plane;
	t_cylinder	cyl;
	t_object	*obj_cylinder;

	luz = create_point(0, 0, 0);
	luz = mat_x_tuple(create_point(0, 0, 0), mat_gener_trans(0, 5, -50));
	mat1 = obj_material_init(c_new(1, 0, 0), c_new(-1, -1, -1),
			obj_init_values_material(0.1, 0.6, 0.3, 100), 0);
	word_objects = NULL;
	sph = sphere(create_point(0, 0, 0), 1);
	obj_sphere =
		create_object(&sph, OBJ_SPHERE, mat1,
				obj_creat_texture(rt_struct->canva, NULL));
	ray_set_transform_obj(
		obj_sphere,
		mat_multip(mat_multip(mat_gener_scal(1, 1, 1), mat_gener_trans(0, 1,
						1)),
					mat_gener_rota('z', 0.5)));
	sph2 = sphere(create_point(0, 0, 0), 1);
	mat1.bumbp = 0;
	obj_sphere2 =
		create_object(&sph2, OBJ_SPHERE, mat1,
				obj_creat_texture(rt_struct->canva, "./texture/pla.xpm"));
	my_mlx_pixel_retunr(obj_sphere2->texture, 1, 1);
	ray_set_transform_obj(
		obj_sphere2,
		mat_multip(mat_multip(mat_gener_scal(1, 1, 1), mat_gener_trans(0, 1,
						1)),
					mat_gener_rota('z', 0.5)));
	mat3 = obj_material_init(c_new(1, 1, 0), c_new(1, 0, 0),
			obj_init_values_material(0.1, 0.6, 0.3, 100), 0.1);
	pln = create_plane(create_point(0, -2, 0), create_point(1, -2, 0),
			create_point(0, -2, 5));
	obj_plane = create_object(&pln, OBJ_PLANE, mat3, NULL);
	ray_set_transform_obj(obj_plane, mat_multip(mat_gener_scal(1, 1, 1),
				mat_gener_trans(0, 0, 0)));


	cyl = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0),
			0.2, 5);
	obj_cylinder = create_object(&cyl, OBJ_CYLINDER, mat1, obj_creat_texture(rt_struct->canva, NULL));
	obj_cylinder->matiral = obj_material_init(c_new(1.0, 1.0, 0), c_new(-1, -1, -1),
			obj_init_values_material(0.3, 0.6, 0.3, 200),0.0);
	ray_set_transform_obj(obj_cylinder, mat_multip(mat_gener_scal(1, 1, 1),
			mat_gener_rota('z', 0)));
	ray_set_transform_obj(obj_cylinder, mat_gener_rota('z', 1));
	ft_add_node(obj_cylinder, &word_objects);
	ft_add_node(obj_plane, &word_objects);
	init_cylinders(rt_struct, &word_objects);
	rt_struct->word = word_objects;
	 obj_open_stl_start(
	 	rt_struct, "./texture/Gun.obj", mat_multip(mat_gener_scal(1, 1, 1),
	 			mat_gener_trans( 0,1, 0)), mat1);
	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz[0] = ligth_init(c_new(3, 3, 3), luz);
	rt_struct->luz[1] = ligth_init(c_new(1, 1, 1), (t_point){{50, 3, 0}});
	rt_struct->luz_index = 1;
}

void	start_word_test(t_minirt *rt_struct, double ambinet, t_color color)
{
	t_sphere	sph;
	t_sphere	sph2;
	t_list_		*word_objects;
	t_mater		mat1;
	t_point		luz;
	t_object	*obj_sphere;
	t_object	*obj_sphere2;

	luz = create_point(-10, 10, -10);
	(void)color;
	word_objects = NULL;
	sph = sphere(create_point(0, 0, 0), 1);
	mat1 = obj_material_init(c_new(1, 0, 0), c_new(-1, -1, -1),
			obj_init_values_material(ambinet, 0.7, 0.2, 200), 0);
	obj_sphere = create_object(&sph, OBJ_SPHERE, mat1, NULL);
	ray_set_transform_obj(obj_sphere, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_sphere, &word_objects);
	sph2 = sphere(create_point(0, 0, 0), 1);
	obj_sphere2 = create_object(&sph2, OBJ_SPHERE, mat1, NULL);
	ray_set_transform_obj(obj_sphere2, mat_gener_scal(1, 1, 1));
	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz[0] = ligth_init(c_new(1, 1, 1), luz);
}

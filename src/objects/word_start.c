/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:35:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/12 14:38:23 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

void print_list_(t_list_ *list)
{
    t_list_ *current = list;

    while (current != NULL)
    {
        if (current->content != NULL)
        {
            t_object *obj = (t_object *)current->content;
            printf("Debug: obj->data = %p\n", (void *)&obj->u_data);
            if (obj == NULL)
            {
                printf("Object data is NULL.\n");
                current = current->next;
                continue;
            }
            if (obj->type == OBJ_SPHERE)
                printf("Object type: Sphere\n");
            else if (obj->type == OBJ_PLANE)
                printf("Object type: Plane\n");
			else if (obj->type == OBJ_TRIANGLE)
				printf("Object type: Triangle\n");
            else
                printf("Object type: Unknown\n");
            if (obj->type == OBJ_SPHERE)
            {
                t_sphere *sphere = &obj->u_data.sphere;
                if (sphere != NULL)
                {
                    printf("Sphere: Center(%f, %f, %f), Radius(%f)\n",
                           sphere->center.x, sphere->center.y, sphere->center.z,
                           sphere->ray_s);
                }
                else
                    printf("Sphere data is NULL.\n");
            }
            else if (obj->type == OBJ_PLANE)
            {
                t_plane *plane = &obj->u_data.plane;
                if (plane != NULL)
                {
                    printf("Plane: Point(%f, %f, %f), Normal(%f, %f, %f)\n",
                           plane->center.x, plane->center.y, plane->center.z,
                           plane->normal.x, plane->normal.y, plane->normal.z);
                }
                else
                    printf("Plane data is NULL.\n");
            }
			else if (obj->type == OBJ_TRIANGLE)
            {
                t_triangle *triangle = &obj->u_data.triangle;
                if (triangle != NULL)
                {
                    printf("Triangle: Points(%f, %f, %f), (%f, %f, %f), (%f, %f, %f)\n",
                           triangle->p1.x, triangle->p1.y, triangle->p1.z,
                           triangle->p2.x, triangle->p2.y, triangle->p2.z,
                           triangle->p3.x, triangle->p3.y, triangle->p3.z);
                }
                else
                    printf("Triangle data is NULL.\n");
            }
        }
        else
            printf("Empty node.\n");
        current = current->next;
    }
}

void	start_word(t_minirt *rt_struct)
{
	t_sphere	sph;
	t_list_		*word_objects;
	t_mater		mat1;
	t_object	*obj_sphere;
	t_point		luz;

	luz = create_point(0, -5, 0);
	mat1 = obj_material_init(c_new(1, 0, 0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));
	word_objects = NULL;
	sph = sphere(create_point(0, 0, 0), 1);
	obj_sphere = create_object(&sph, OBJ_SPHERE, mat1);
	ray_set_transform_obj(obj_sphere, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_sphere, &word_objects);


	t_plane pln = create_plane(create_point(0,0, 0));
	t_object *obj_plane = create_object(&pln, OBJ_PLANE, mat1);
	obj_plane->matiral = obj_material_init(c_new(0,1.0,0), obj_init_values_material(0.5,0.6, 0.3, 100));
	// ray_set_transform_obj(obj_plane,mat_gener_rota('x', 0.3));
	// ray_set_transform_obj(obj_plane, mat_gener_scal(1, 1, 1));
	// ray_set_transform_obj(obj_plane,mat_gener_trans(0, 2, 0));
	ft_add_node(obj_plane,&word_objects );
	
	t_triangle tri1 = create_triangle(create_point(0, -2, -2), create_point(-2, -2, 0), create_point(-3, 0, -2));
	t_object *obj_triangle1 = create_object(&tri1, OBJ_TRIANGLE, mat1);
	obj_triangle1->matiral = obj_material_init(c_new(1.0, 0, 1.0), obj_init_values_material(0.1, 0.6, 0.3, 200));
	ray_set_transform_obj(obj_triangle1, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_triangle1, &word_objects);

	t_triangle tri2 = create_triangle(create_point(0, -1, -3), create_point(-2, -2, 0), create_point(-2, 0, -2));
	t_object *obj_triangle2 = create_object(&tri2, OBJ_TRIANGLE, mat1);
	obj_triangle2->matiral = obj_material_init(c_new(0, 1.0, 1.0), obj_init_values_material(0.1, 0.6, 0.3, 200));
	ray_set_transform_obj(obj_triangle2, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_triangle2, &word_objects);

	t_cylinder cyl = create_cylinder(create_point(-2 ,0, -3), create_vector(0,1, 0), 0.2, 5);	
	t_object *obj_cylinder = create_object(&cyl, OBJ_CYLINDER, mat1);
	obj_cylinder->matiral = obj_material_init(c_new(1.0, 1.0, 0), obj_init_values_material(0.3, 0.6, 0.3, 200));
	ray_set_transform_obj(obj_cylinder, mat_gener_scal(1, 1, 1));
	ray_set_transform_obj(obj_cylinder,mat_gener_rota('z', 1));
	ft_add_node(obj_cylinder, &word_objects);
	print_list_(ft_node_start(word_objects));
		//init camera
		t_point origin = create_point(0, 0, 10);
		t_vector direction = create_vector(0,  0, -1);
		double fov =100.0;
		camera_init(&rt_struct->camera, origin, direction, fov);
	
	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(1, 1, 1), luz);
}

// void start_word_test(t_minirt  *rt_struct,double ambinet,t_color color)
// {
// 	t_sphere sph;
// 	t_sphere sph2;	
// 	t_sphere sph3;
// 	t_list_ *word_objects;
// 	t_mater mat;

// 	t_point luz = create_point(10, -10,10);
	

// 	word_objects = NULL;
// 	sph = sphere(create_point(0, 0, 0),1) ;


// 	mat = obj_material_init(color, 
// 	obj_init_values_material(ambinet, 0.7, 0.2, 200));
//  	t_object *obj_sphere = create_object(&sph, OBJ_SPHERE,mat);
// 	ray_set_transform_obj(obj_sphere,mat_gener_scal( 1, 1, 1));
// 	ft_add_node(obj_sphere,&word_objects );

// 	sph2 = sphere(create_point(0, 0, 0),1) ;
//  	t_object *obj_sphere2 = create_object(&sph2, OBJ_SPHERE,mat);
// 	ray_set_transform_obj(obj_sphere,mat_gener_scal( 1, 1, 1));
// 	ft_add_node(obj_sphere2,&word_objects);	


// 	rt_struct->word = ft_node_start(word_objects);
// 	rt_struct->luz = ligth_init(c_new(1,1,1), luz);	

// }

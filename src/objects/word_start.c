/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:35:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/14 17:50:38 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
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

            // Print the object type as a string
            if (obj->type == OBJ_SPHERE)
                printf("Object type: Sphere\n");
            else if (obj->type == OBJ_PLANE)
                printf("Object type: Plane\n");
			else if (obj->type == OBJ_TRIANGLE)
				printf("Object type: Triangle\n");
            else
                printf("Object type: Unknown\n");

            // Additional logic for printing object details
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
                {
                    printf("Sphere data is NULL.\n");
                }
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
                {
                    printf("Plane data is NULL.\n");
                }
            }
			else if (obj->type == OBJ_TRIANGLE)
            {
                printf("Object type: Triangle\n");
                t_triangle *triangle = &obj->u_data.triangle;
                if (triangle != NULL)
                {
                    printf("Triangle: Points(%f, %f, %f), (%f, %f, %f), (%f, %f, %f)\n",
                           triangle->p1.x, triangle->p1.y, triangle->p1.z,
                           triangle->p2.x, triangle->p2.y, triangle->p2.z,
                           triangle->p3.x, triangle->p3.y, triangle->p3.z);
                }
                else
                {
                    printf("Triangle data is NULL.\n");
                }
            }
        }
        else
        {
            printf("Empty node.\n");
        }
        current = current->next;
    }
}

void draw_cube(t_minirt *rt_struct, t_point position, t_color color, double scale)
{
    t_list_ *word_objects = NULL;

    // Define the cube vertices
    t_point cube_vertices[8] = {
        create_point(-1, -1, -1), // Vertex 0
        create_point(1, -1, -1),  // Vertex 1
        create_point(1, 1, -1),   // Vertex 2
        create_point(-1, 1, -1),  // Vertex 3
        create_point(-1, -1, 1),  // Vertex 4
        create_point(1, -1, 1),   // Vertex 5
        create_point(1, 1, 1),    // Vertex 6
        create_point(-1, 1, 1)    // Vertex 7
    };

    // Define the cube faces
    int cube_faces[12][3] = {
        {0, 1, 2}, {0, 2, 3}, // Front face
        {4, 5, 6}, {4, 6, 7}, // Back face
        {0, 1, 5}, {0, 5, 4}, // Bottom face
        {2, 3, 7}, {2, 7, 6}, // Top face
        {0, 3, 7}, {0, 7, 4}, // Left face
        {1, 2, 6}, {1, 6, 5}  // Right face
    };

    // Create triangles for the cube
    for (int i = 0; i < 12; i++) {
        t_triangle tri = create_triangle(
            cube_vertices[cube_faces[i][0]],
            cube_vertices[cube_faces[i][1]],
            cube_vertices[cube_faces[i][2]]
        );
        t_object *obj_triangle = create_object(&tri, OBJ_TRIANGLE);
        ray_set_transform_obj(obj_triangle, mat_gener_scal(scale, scale, scale));
        ray_set_transform_obj(obj_triangle, mat_gener_trans(position.x, position.y, position.z));
        ft_add_node(obj_triangle, &word_objects);
    }

    // Add the cube to the scene
    rt_struct->word = ft_node_start(word_objects);
}

void draw_axis_with_cubes(t_minirt *rt_struct)
{
    // Define positions for the cubes
    t_point x_position = create_point(-1, -1, 0);
    t_point y_position = create_point(-1, -1, 1);
    t_point z_position = create_point(-1, -1, 1);

    // Draw cubes for each axis
    draw_cube(rt_struct, x_position, c_new(255, 0, 0), 0.5); // Red for X-axis
    draw_cube(rt_struct, y_position, c_new(0, 255, 0), 0.5); // Green for Y-axis
    draw_cube(rt_struct, z_position, c_new(0, 0, 255), 0.5); // Blue for Z-axis
}
void start_word(t_minirt  *rt_struct)
{
	t_sphere sph;
	t_sphere sph2;
	t_obj_int intr_in_objc;
	t_list_ *word_objects;

	word_objects = NULL;
	t_object *obj_sphere;

	sph = sphere(create_point(0, 0, 50),1) ;
	obj_sphere = create_object(&sph, OBJ_SPHERE);
    ray_set_transform_obj(obj_sphere, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_sphere,&word_objects );

	t_plane pln = create_plane(create_point(1, 0, 0), 1);
	t_object *obj_plane = create_object(&pln, OBJ_PLANE);
	ray_set_transform_obj(obj_plane,mat_gener_rota('x', -1));
    ft_add_node(obj_plane,&word_objects );
	// print_list_(word_objects);	

    t_triangle tri = create_triangle(create_point(1,0,0), create_point(0,1,1), create_point(1,1,0));
    t_object *obj_triangle = create_object(&tri, OBJ_TRIANGLE);
	ray_set_transform_obj(obj_triangle, mat_gener_scal(1, 2, 1));
    ft_add_node(obj_triangle,&word_objects );

	print_list_(word_objects);	
	// sph = sphere(create_point(0, 0, 0),1) ;
	// //ray_set_transform(&sph,mat_multip(mat_gener_scal(1, 0.5, 1), mat_gener_rota('Z',(M_PI/5 ))));
	// ray_set_transform(&sph,mat_gener_scal(1, 1, 1));
	// ft_add_node(&sph,&word_objects );
	// //sph2 = sphere(create_point(0, 0, 0),1) ;
	// //ray_set_transform(&sph2,mat_gener_scal(0.5, 0.5, 0.5) );
	// ft_add_node(&sph2,&word_objects);	
	
	
	
	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(1,1,1), create_point(-10, 10, -10));	
	rt_struct->c_ray = ray_gener( create_point(0,0, 0), create_vector(0, 0, 1));


}

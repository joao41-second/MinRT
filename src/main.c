/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:45:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/21 14:45:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "matrix/matrix.h"
// #include "minRT.h"
// #include "ray/ray.h"
// #include "ray/ray_struct.h"
// #include "tuples/tuples.h"

// # define M_PI 3.1415926535897932384626433832795
// void print_list_(t_list_ *list)
// {
//     t_list_ *current = list;

//     while (current != NULL)
//     {
//         if (current->content != NULL)
//         {
//             t_object *obj = (t_object *)current->content;

//             printf("Debug: obj->data = %p\n", (void *)&obj->u_data);
//             if (obj == NULL)
//             {
//                 printf("Object data is NULL.\n");
//                 current = current->next;
//                 continue;
//             }

//             // Print the object type as a string
//             if (obj->type == OBJ_SPHERE)
//                 printf("Object type: Sphere\n");
//             else if (obj->type == OBJ_PLANE)
//                 printf("Object type: Plane\n");
//             else
//                 printf("Object type: Unknown\n");

//             // Additional logic for printing object details
//             if (obj->type == OBJ_SPHERE)
//             {
//                 t_sphere *sphere = &obj->u_data.sphere;
//                 if (sphere != NULL)
//                 {
//                     printf("Sphere: Center(%f, %f, %f), Radius(%f)\n",
//                            sphere->center.x, sphere->center.y, sphere->center.z,
//                            sphere->ray_s);
//                 }
//                 else
//                 {
//                     printf("Sphere data is NULL.\n");
//                 }
//             }
//             else if (obj->type == OBJ_PLANE)
//             {
//                 t_plane *plane = &obj->u_data.plane;
//                 if (plane != NULL)
//                 {
//                     printf("Plane: Point(%f, %f, %f), Normal(%f, %f, %f)\n",
//                            plane->center.x, plane->center.y, plane->center.z,
//                            plane->normal.x, plane->normal.y, plane->normal.z);
//                 }
//                 else
//                 {
//                     printf("Plane data is NULL.\n");
//                 }
//             }
//         }
//         else
//         {
//             printf("Empty node.\n");
//         }
//         current = current->next;
//     }
// }

// void rotate_plane(t_object *plane_obj, char axis, double angle)
// {
//     t_matrix rotation_matrix = mat_gener_rota(axis, angle);
//     ray_set_transform_obj(plane_obj, rotation_matrix);
// }


// int	main(int ac, char **av, char **env)
// {
// 	t_minirt	rt_struct;
// 	int			status;
// 	t_list_ *word_objects;

// 	word_objects = NULL;
// 	status = 0;
// 	(void)ac;
// 	(void)av;
// 	(void)env;
// 	ft_start_alloc();
// 	t_sphere sph;
// 	t_sphere sph2;
// 	t_obj_int intr_in_objc;
// 	t_object *obj_sphere;

// 	sph = sphere(create_point(1, 0, 0),1) ;
// 	obj_sphere = create_object(&sph, OBJ_SPHERE);
// 	// ray_set_transform((t_sphere *)obj_sphere->data,mat_gener_scal(1, 1, 1) );
//     ray_set_transform_obj(obj_sphere, mat_gener_scal(1, 1, 1));
// 	ft_add_node(obj_sphere,&word_objects );

// 	// print_list_(word_objects);	
// 	t_plane pln = create_plane(create_point(1, 0, 0), 1);
// 	t_object *obj_plane = create_object(&pln, OBJ_PLANE);
// 	// t_matrix rot_y = mat_gener_rota('x', 45);
// 	// rotate_plane(obj_plane, 'x', M_PI / 4); 
// 	ray_set_transform_obj(obj_plane,mat_gener_rota('y', 45));
// 	// ft_add_node(obj_plane,&word_objects);
// 	print_list_(word_objects);	

// 	t_object plane;
//     plane.type = OBJ_PLANE;
//     plane.u_data.plane.center = create_point(0, 0, 0);
//     plane.u_data.plane.normal = create_vector(0, 1, 0);
//     plane.u_data.plane.color = c_new(1, 0, 0);
//     plane.u_data.plane.transform = mat_gener_identity(4);
//     plane.u_data.plane.inv_transform = mat_gener_identity(4);
    
//     t_ray r1 = ray_gener(create_point(0, 10, 0), create_vector(0, 0, 1));
//     t_ray r2 = ray_gener(create_point(0, 0, 0), create_vector(0, 0, 1));
//     t_ray r3 = ray_gener(create_point(0, 1, 0), create_vector(0, -1, 0));
//     t_ray r4 = ray_gener(create_point(0, -1, 0), create_vector(0, 1, 0));
    
//     t_intersection intr1 = ray_int_plane(r1, &plane);
//     t_intersection intr2 = ray_int_plane(r2, &plane);
//     t_intersection intr3 = ray_int_plane(r3, &plane);
//     t_intersection intr4 = ray_int_plane(r4, &plane);
    
//     printf("Intersections with parallel ray: %f\n", intr1.inter);
//     printf("Intersections with coplanar ray: %f\n", intr2.inter);
//     printf("Intersections from above: %f, t = %f\n", intr3.inter, intr3.t[0]);
//     printf("Intersections from below: %f, t = %f\n", intr4.inter, intr4.t[0]);


// 	rt_struct.word = word_objects;
	
// 	canva_inicializ(&rt_struct, WALL_X, WALL_Y,c_new(0, 0, 0));	
// 	return (status);

// }

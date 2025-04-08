/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:45:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/21 14:45:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix/matrix.h"
#include "minRT.h"
#include "ray/ray.h"
#include "ray/ray_struct.h"
#include "tuples/tuples.h"
#include <time.h>
// Define the left mouse button constant
#define MOUSE_LEFT_BUTTON 1

# define M_PI 3.1415926535897932384626433832795
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
        }
        else
        {
            printf("Empty node.\n");
        }
        current = current->next;
    }
}


int	canva_loop(t_minirt *rt_struct)
{
	// loop(rt_struct);
    static int ok = 0;

	// if(ok == 0)
	// {
	rt_struct->c_ray = ray_gener( create_point(0, 0, 0), create_vector(0, 0, 1));
	ft_pocket_new("canva");
	
	// Inlined implementation of ray_canva function
	    // clock_t inicio = clock();
		t_point point = create_point(0, 0, -10);
		double x;
        double y;
        double x_;
        double y_;
        t_tuple raiva;
        t_tuple sub;
        x = -1;
        y = -1;
        if (!rt_struct->needs_render)
        return (1); 
        rt_struct->needs_render = 0;
		while (++y < WALL_Y) 
		{
			x = -1;
			// y_ = (metade - y) * pix_size;
			while(++x < WALL_X)
			{
				// x_ = (-metade + x) * pix_size;
				// raiva = create_point(x_, y_, WALL_Z);
				// sub = sub_tuples(raiva, rt_struct->c_ray.direction);
				// t_obj_int intersections = ray_for_objects(rt_struct->word, ray_gener(point, normalize(sub)));
                t_ray ray = camera_generate_ray(&rt_struct->scene.world.camera, x, y);
                // Check for intersections with objects in the scene
                t_obj_int intersections = ray_for_objects(rt_struct->word, ray);
				if(intersections.min != INT_MAX)
				{
					t_object *closest_obj = (t_object *)intersections.ints->content;
					
					canva_set_pixel(rt_struct, x, y, c_new(255.0, 1.0, 100.0));
				}
				else
					canva_set_pixel(rt_struct, x, y, c_new(255.0, 255, 100.0));
			}	
		}
	
        // clock_t fim = clock();
    	// double tempo_exec = (double)(fim - inicio) / CLOCKS_PER_SEC; // Converte para segundos
    	// printf("Tempo de execução: %.6f segundos\n", tempo_exec);
	
	ft_free_all_pocket("canva");
	// }
	// ok++;

	canva_update(rt_struct);

	return (1);
}

int canva_loop_key(int keycode, void *param) {
    t_minirt *rt_struct = (t_minirt *)param;

    if (keycode == KEY_UP || keycode == KEY_DOWN || 
        keycode == KEY_LEFT || keycode == KEY_RIGHT || 
        keycode == KEY_W || keycode == KEY_S) {
        camera_move(&rt_struct->scene.world.camera, keycode);
        rt_struct->needs_render = 1;
        printf("Camera moved: Key %d\n", keycode);
    } else if (keycode == KEY_ESC) {
        mlx_destroy_window(rt_struct->canva.mlx,
                           rt_struct->canva.mlx_wind); // Exit on ESC key
        exit(0);
    }

    return (1);
}


int canva_loop_mouse(int button, int x, int y, void *param) {
    t_minirt *rt_struct = (t_minirt *)param;

    if (button == MOUSE_LEFT_BUTTON) { // Rotate on left mouse click/drag
        camera_rotate(&rt_struct->scene.world.camera,
                      (double)x / WALL_X - 0.5,
                      (double)y / WALL_Y - 0.5);
                      canva_update(rt_struct);
        rt_struct->needs_render = 1;
        printf("Camera rotated\n");
    }

    return (1);
}

int	main(int ac, char **av, char **env)
{
	t_minirt	rt_struct;
	int			status;
	t_list_ *word_objects;

	word_objects = NULL;
	status = 0;
	(void)ac;
	(void)av;
	(void)env;
	ft_start_alloc();

    rt_struct.needs_render = 1;
	t_sphere sph;
	t_sphere sph2;
	t_obj_int intr_in_objc;
	t_object *obj_sphere;

	sph = sphere(create_point(0, 0, 50),1) ;
	obj_sphere = create_object(&sph, OBJ_SPHERE);
    ray_set_transform_obj(obj_sphere, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_sphere,&word_objects );

	t_plane pln = create_plane(create_point(1, 0, 0), 1);
	t_object *obj_plane = create_object(&pln, OBJ_PLANE);
	ray_set_transform_obj(obj_plane,mat_gener_rota('x', -1));
    ft_add_node(obj_plane,&word_objects );
	print_list_(word_objects);	

	t_object plane;
    plane.type = OBJ_PLANE;
    plane.u_data.plane.center = create_point(0, 0, 0);
    plane.u_data.plane.normal = create_vector(0, 1, 0);
    plane.u_data.plane.color = c_new(1, 0, 0);
    plane.u_data.plane.transform = mat_gener_identity(4);
    plane.u_data.plane.inv_transform = mat_gener_identity(4);
    
    t_ray r1 = ray_gener(create_point(0, 10, 0), create_vector(0, 0, 1));
    t_ray r2 = ray_gener(create_point(0, 0, 0), create_vector(0, 0, 1));
    t_ray r3 = ray_gener(create_point(0, 1, 0), create_vector(0, -1, 0));
    t_ray r4 = ray_gener(create_point(0, -1, 0), create_vector(0, 1, 0));
    
    t_intersection intr1 = ray_int_plane(r1, &plane);
    t_intersection intr2 = ray_int_plane(r2, &plane);
    t_intersection intr3 = ray_int_plane(r3, &plane);
    t_intersection intr4 = ray_int_plane(r4, &plane);
    
    printf("Intersections with parallel ray: %f\n", intr1.inter);
    printf("Intersections with coplanar ray: %f\n", intr2.inter);
    printf("Intersections from above: %f, t = %f\n", intr3.inter, intr3.t[0]);
    printf("Intersections from below: %f, t = %f\n", intr4.inter, intr4.t[0]);

	rt_struct.word = word_objects;
	
    //init camera
    camera_init(&rt_struct.scene.world.camera);
	// Inlined implementation of canva_inicializ function
    rt_struct.canva.mlx = ft_add_memory(mlx_init(), NULL);
    rt_struct.canva.mlx_wind = mlx_new_window(rt_struct.canva.mlx,
            WALL_X, WALL_Y, "new minRT");
    rt_struct.canva.canva.img = mlx_new_image(rt_struct.canva.mlx, WALL_X, WALL_Y);
    rt_struct.canva.canva.addr = mlx_get_data_addr(rt_struct.canva.canva.img,
            &rt_struct.canva.canva.bits_per_pixel,
            &rt_struct.canva.canva.line_length,
            &rt_struct.canva.canva.endian);
    mlx_key_hook(rt_struct.canva.mlx_wind, canva_loop_key, &rt_struct);
    mlx_mouse_hook(rt_struct.canva.mlx_wind, canva_loop_mouse, &rt_struct);
    mlx_loop_hook(rt_struct.canva.mlx, canva_loop, &rt_struct);
    mlx_hook(rt_struct.canva.mlx_wind,
        17, 01, &mlx_loop_end, rt_struct.canva.mlx);
    mlx_loop(rt_struct.canva.mlx);
    mlx_destroy_image(rt_struct.canva.mlx, rt_struct.canva.canva.img);
    mlx_destroy_window(rt_struct.canva.mlx, rt_struct.canva.mlx_wind);
    mlx_destroy_display(rt_struct.canva.mlx);
    ft_free_all();
	
	
	return (status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:29:56 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/15 13:32:27 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "../camera/keys.h"

int	canva_loop(t_minirt *rt_struct)
{
	loop(rt_struct);
	return (1);
}
/**
 * Implementation of standard orthographic views
 * These functions can be called when specific keys are pressed
 */
void set_top_view(t_camera *cam)
{
    cam->origin = create_point(0, 10, 0);
    cam->direction = create_vector(0, -1, 0);
    camera_update_view(cam);
}
void set_front_view(t_camera *cam)
{
    cam->origin = create_point(0, 0, -10);
    cam->direction = create_vector(0, 0, 1);
    camera_update_view(cam);
}
void set_right_view(t_camera *cam)
{
    cam->origin = create_point(10, 0, 0);
    cam->direction = create_vector(-1, 0, 0);
    camera_update_view(cam);
}
void set_left_view(t_camera *cam)
{
    cam->origin = create_point(-10, 0, 0);
    cam->direction = create_vector(1, 0, 0);
    camera_update_view(cam);
}
void set_back_view(t_camera *cam)
{
    cam->origin = create_point(0, 0, 10);
    cam->direction = create_vector(0, 0, -1);
    camera_update_view(cam);
}
void set_bottom_view(t_camera *cam)
{
    cam->origin = create_point(0, -10, 0);
    cam->direction = create_vector(0, 1, 0);
    camera_update_view(cam);
}
/**
 * Extended key handler to support standard views
 * Add these cases to your existing canva_loop_key function
 */
int canva_loop_key(int keycode, void *param)
{
    t_minirt *rt_struct = (t_minirt *)param;
    if (keycode == KEY_UP || keycode == KEY_DOWN || 
        keycode == KEY_LEFT || keycode == KEY_RIGHT || 
        keycode == KEY_W || keycode == KEY_S) {
        camera_move(&rt_struct->scene.world.camera, keycode);
    } 
    else if (keycode == NUMPAD_1) {  
        set_front_view(&rt_struct->scene.world.camera);
    }
    else if (keycode == NUMPAD_4) {  
        set_right_view(&rt_struct->scene.world.camera);
    }
    else if (keycode == NUMPAD_7) {  
        set_top_view(&rt_struct->scene.world.camera);
    }
    else if (keycode == NUMPAD_2) {  
        set_back_view(&rt_struct->scene.world.camera);
    }
    else if (keycode == NUMPAD_5) {  
        set_left_view(&rt_struct->scene.world.camera);
    }
    else if (keycode == NUMPAD_8) {  
        set_bottom_view(&rt_struct->scene.world.camera);
    }
    else if (keycode == KEY_ESC) {
        mlx_destroy_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind);
        exit(0);
    }
    return (1);
}
int canva_loop_mouse(int button, int x, int y, void *param) {
    t_minirt *rt_struct = (t_minirt *)param;
    if (button == MOUSE_LEFT_BUTTON) { 
        camera_rotate(&rt_struct->scene.world.camera,
                      (double)x / WALL_X - 0.5,
                      (double)y / WALL_Y - 0.5);
                      canva_update(rt_struct);
        printf("Camera rotated\n");
    }
    return (1);
}
void	canva_inicializ(t_minirt *rt_struct, int x, int y, t_color base)
{
	(void)base;
	rt_struct->canva.mlx = ft_add_memory(mlx_init(), NULL);
	rt_struct->canva.mlx_wind = mlx_new_window(rt_struct->canva.mlx,
			x, y, "new minRT");
	rt_struct->canva.canva.img = mlx_new_image(rt_struct->canva.mlx, x, y);
	rt_struct->canva.canva.addr = mlx_get_data_addr(rt_struct->canva.canva.img,
			&rt_struct->canva.canva.bits_per_pixel,
			&rt_struct->canva.canva.line_length,
			&rt_struct->canva.canva.endian);
	mlx_key_hook(rt_struct->canva.mlx_wind, canva_loop_key, rt_struct);
	mlx_mouse_hook(rt_struct->canva.mlx_wind, canva_loop_mouse, rt_struct);
	mlx_loop_hook(rt_struct->canva.mlx, canva_loop, rt_struct);
	mlx_hook(rt_struct->canva.mlx_wind,
		17, 01, &mlx_loop_end, rt_struct->canva.mlx);
	mlx_loop(rt_struct->canva.mlx);
	mlx_destroy_image(rt_struct->canva.mlx, rt_struct->canva.canva.img);
	mlx_destroy_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind);
	mlx_destroy_display(rt_struct->canva.mlx);
	ft_free_all();
}

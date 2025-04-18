/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:49:55 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/18 10:40:06 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAMERA_H
# define CAMERA_H

# include "../miniRT_struct.h"

#include "keys.h"

# define DEFAULT_FOV 30.0
# define MOUSE_SENSITIVITY 0.02
# define MOVE_SPEED 10.0

typedef struct s_camera {
    t_point      origin;
    t_vector     direction;
    double       fov;
    double       aspect_ratio;
    t_matrix     view_matrix;
    t_matrix     inv_view_matrix;
} t_camera;

void        camera_init(t_camera *cam);
void        camera_update_view(t_camera *cam);
t_ray       camera_generate_ray(t_camera *cam, double x, double y);
// Camera transformations
void        camera_rotate(t_camera *cam, double dx, double dy);
void        camera_move(t_camera *cam, int keycode);
// Math utilities
t_matrix    mat_lookat(t_point eye, t_point center, t_vector up);

#endif

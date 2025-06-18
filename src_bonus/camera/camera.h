/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:49:55 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/07 10:17:44 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "../matrix/matrix.h"
# include "../miniRT_struct.h"
# include "../tuples/tuples.h"
# include "keys.h"

# define DEFAULT_FOV 60.0
# define ROTATION_SPEED 0.01
# define MOVE_SPEED 1.0

typedef struct s_camera
{
	t_point		origin;
	t_vector	direction;
	double		fov;
	double		aspect_ratio;
	t_matrix	view_matrix;
	t_matrix	inv_view_matrix;
}				t_camera;

void			camera_init(t_camera *cam, t_point origin, t_vector direction,
					double fov);
void			camera_update_view(t_camera *cam);
t_ray			camera_generate_ray(t_camera *cam, double x, double y);
// Camera transformations
void			camera_rotate(t_camera *cam, double dx, double dy);
void			camera_move(t_camera *cam, int keycode);
// Math utilities
t_matrix		mat_lookat(t_point eye, t_point center, t_vector up);
t_matrix		mat_rotate(t_vector axis, double angle);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:32:34 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/02 12:26:21 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H
# include "../miniRT_struct.h"

void	loop(t_minirt *rt_struct);

void	mouse(t_minirt *rt_struct);

void	rotate_plane(t_object *plane, char axis, double ang, t_camera_ms *cam);
void	ray_reset_transform_obj(t_object *obj);
void	rotate_scene(t_minirt *rt_struct, char axis, double angle);
void	set_ortho(t_camera_ms *cam, t_point origin,
			t_vector direction);
void	handle_orthographic_view(t_minirt *rt_struct);
void	key_loop(int key, t_minirt *rt_struct);
#endif

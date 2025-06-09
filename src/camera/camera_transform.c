/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:48:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/22 10:07:39 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "camera.h"

static t_matrix	create_rot(t_vector forward, t_vector left, t_vector true_up)
{
	t_matrix	rotation;

	rotation = mat_gener_identity(4);
	rotation.matr[0][0] = left.x;
	rotation.matr[0][1] = left.y;
	rotation.matr[0][2] = left.z;
	rotation.matr[1][0] = true_up.x;
	rotation.matr[1][1] = true_up.y;
	rotation.matr[1][2] = true_up.z;
	rotation.matr[2][0] = -forward.x;
	rotation.matr[2][1] = -forward.y;
	rotation.matr[2][2] = -forward.z;
	return (rotation);
}

t_matrix	mat_lookat(t_point eye, t_point center, t_vector up)
{
	t_vector	forward;
	t_vector	left;
	t_vector	true_up;
	t_matrix	rotation;
	t_matrix	translation;

	forward = normalize(sub_tuples(center, eye));
	left = normalize(cross_product(forward, up));
	true_up = cross_product(left, forward);
	rotation = create_rot(forward, left, true_up);
	translation = mat_gener_trans(-eye.x, -eye.y, -eye.z);
	return (mat_multip(rotation, translation));
}

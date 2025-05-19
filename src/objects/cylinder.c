/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:46:08 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/19 14:51:16 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

t_cylinder create_cylinder(t_point center, t_vector orientation, double radius, double height) {
    t_cylinder cylinder;
    cylinder.center = center;
    cylinder.orientation = normalize(orientation);
    cylinder.radius = radius;
    cylinder.height = height;
    cylinder.minimum = -height / 2.0;
    cylinder.maximum = height / 2.0;
    cylinder.closed = FALSE;
    return cylinder;
}

t_vector cylinder_normal_at(t_cylinder cylinder, t_point point)
{
    double dist = pow(point.x - cylinder.center.x, 2) + pow(point.z - cylinder.center.z, 2);

    if (dist < pow(cylinder.radius, 2)) {
        if (point.y >= cylinder.maximum - EPSILON) {
            return create_vector(0, 1, 0);
        }
        if (point.y <= cylinder.minimum + EPSILON) {
            return create_vector(0, -1, 0);
        }
    }

    t_vector axis = cylinder.orientation;
    t_point projected = add_tuples(cylinder.center, scalar_mult_tuples(axis, dot_product(sub_tuples(point, cylinder.center), axis)));
    return normalize(sub_tuples(point, projected));
}

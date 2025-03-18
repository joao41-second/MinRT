/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:07:37 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/18 16:59:59 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minRT.h"

//create
t_tuple create_tuple(double x, double y, double z, double w)
{
    t_tuple tuple;

    tuple.x = x;
    tuple.y = y;
    tuple.z = z;
    tuple.w = w;
    return (tuple);
}
t_point create_point(double x, double y, double z)
{
    return (create_tuple(x, y, z, W_POINT));
}

t_vector create_vector(double x, double y, double z)
{
    return (create_tuple(x, y, z, W_VECTOR));
}

//operations

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	return (create_tuple((a.x + b.x), (a.y + b.y), (a.z + b.z), (a.w + b.w)));
}
t_tuple	sub_tuples(t_tuple a, t_tuple b)
{
	return (create_tuple((a.x - b.x), (a.y - b.y), (a.z - b.z), (a.w - b.w)));
}

t_tuple neg_tuple(t_tuple tuple)
{
	return (create_tuple(-tuple.x, -tuple.y, -tuple.z, -tuple.w));
}

t_tuple scalar_mult_tuples(t_tuple t, double s)
{
    return (create_tuple((t.x * s), (t.y * s), (t.z * s), (t.w * s)));
}

t_tuple scalar_div_tuples(t_tuple t, double s)
{
    return (create_tuple((t.x / s), (t.y / s), (t.z / s), (t.w / s)));
}
//!TODO
//magnitude
//narmalization
//dot product
//cross product



/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:07:37 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/20 14:33:40 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minRT.h"

//create -------------------------------------------------------------
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

//operations -------------------------------------------------

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


//MANIPULATIONS -------------------------------------------------------------------

double	dot_product(t_tuple *a, t_tuple *b)
{
	return (
		(a->x * b->x) + \
		(a->y * b->y) + \
		(a->z * b->z) + \
		(a->w * b->w)
	);
}

double	magnitude(t_tuple *t)
{
	return (sqrt(dot_product(t, t)));
}

t_tuple	normalize(t_tuple *t)
{
	const double	_magnitude = magnitude(t);

	return (create_tuple(
			(t->x / _magnitude),
			(t->y / _magnitude),
			(t->z / _magnitude),
			(t->w / _magnitude))
	);
}

t_tuple	cross_product(t_tuple *a, t_tuple *b)
{
	return (create_vector(
			((a->y * b->z) - (a->z * b->y)),
			((a->z * b->x) - (a->x * b->z)),
			((a->x * b->y) - (a->y * b->x)))
	);
}

//CHECKERS -------------------------------------------------------------------

int	is_equal_double(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}

int	is_equal_tuple(t_tuple a, t_tuple b)
{
	return (
		is_equal_double(a.x, b.x) && \
		is_equal_double(a.y, b.y) && \
		is_equal_double(a.z, b.z) && \
		is_equal_double(a.w, b.w)
	);
}

int	is_vector(t_tuple t)
{
	return (t.w == W_VECTOR);
}

int	is_point(t_tuple t)
{
	return (t.w == W_POINT);
}

int	is_tuple(t_tuple t)
{
	return (!is_vector(t) && !is_point(t));
}

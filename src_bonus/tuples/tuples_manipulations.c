/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_manipulations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:07:37 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/18 14:52:54 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "tuples.h"
#include <stdio.h>

//MANIPULATIONS -----------------------------------------------------

float	dot_product(t_tuple a, t_tuple b)
{
	float	ok;

	ok = 0;
	ok = (a.x * b.x) + \
		(a.y * b.y) + \
		(a.z * b.z) + \
		(a.w * b.w);
	if (isnan(ok))
	{
		printf("\n");
	}
	return (ok);
}

float	magnitude(t_tuple t)
{
	if (dot_product(t, t) == 0)
		return (0);
	return (sqrt(dot_product(t, t)));
}

t_tuple	normalize(t_tuple t)
{
	const float	_magnitude = magnitude(t);

	if (is_equal_float(_magnitude, 1))
		return (t);
	if (is_equal_tuple(t, create_vector(0, 0, 0)))
		return (t);
	return (create_tuple(
			(t.x / _magnitude),
			(t.y / _magnitude),
			(t.z / _magnitude),
			(t.w / _magnitude))
	);
}

t_tuple	cross_product(t_tuple a, t_tuple b)
{
	return (create_vector(
			((a.y * b.z) - (a.z * b.y)),
			((a.z * b.x) - (a.x * b.z)),
			((a.x * b.y) - (a.y * b.x)))
	);
}

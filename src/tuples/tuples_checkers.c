/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_checkers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:07:37 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/24 11:10:54 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

//CHECKERS -------------------------------------------------------------------

int	is_equal_float(float a, float b)
{
	return (fabs(a - b) < EPSILON);
}
int	is_equal_double(float a, float b)
{
	return (fabs(a - b) < EPSILON);
}

int	is_equal_tuple(t_tuple a, t_tuple b)
{
	return (
		is_equal_float(a.x, b.x) && \
		is_equal_float(a.y, b.y) && \
		is_equal_float(a.z, b.z) && \
		is_equal_float(a.w, b.w)
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

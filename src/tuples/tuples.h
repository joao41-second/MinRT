/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:00:36 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/06 14:00:42 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

//TUPLES, VECTORS, POINTS
# define W_POINT 1
# define W_VECTOR 0
# define EPSILON 0.00001

typedef union s_tuple
{
	float	val[4];
	struct
	{
		float	x;
		float	y;
		float	z;
		float	w;
	};
}	t_tuple;

typedef t_tuple		t_point;
typedef t_tuple		t_vector;

t_tuple		create_tuple(float x, float y, float z, float w);
t_point		create_point(float x, float y, float z);
t_vector	create_vector(float x, float y, float z);

t_tuple		add_tuples(t_tuple a, t_tuple b);
t_tuple		sub_tuples(t_tuple a, t_tuple b);
t_tuple		neg_tuple(t_tuple tuple);
t_tuple		scalar_mult_tuples(t_tuple t, float s);
t_tuple		scalar_div_tuples(t_tuple t, float s);

float		dot_product(t_tuple a, t_tuple b);
float		magnitude(t_tuple t);
t_tuple		normalize(t_tuple t);
t_tuple		cross_product(t_tuple a, t_tuple b);

int			is_equal_float(float a, float b);
int			is_equal_tuple(t_tuple a, t_tuple b);
int			is_vector(t_tuple t);
int			is_point(t_tuple t);
int			is_tuple(t_tuple t);

#endif

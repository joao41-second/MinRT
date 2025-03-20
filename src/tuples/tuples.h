/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:38:54 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/20 14:27:18 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#ifndef TUPLES_H
# define TUPLES_H
# include "../miniRT_struct.h"

//TUPLES, VECTORS, POINTS
#define W_POINT 1
#define W_VECTOR 0
#define EPSILON 0.00001

typedef struct s_tuple
{
    double  x;
    double  y;
    double  z;
    double  w;
}   t_tuple;

typedef t_tuple     t_point;
typedef t_tuple     t_vector;

t_tuple create_tuple(double x, double y, double z, double w);
t_point create_point(double x, double y, double z);
t_vector create_vector(double x, double y, double z);

t_tuple	add_tuples(t_tuple a, t_tuple b);
t_tuple	sub_tuples(t_tuple a, t_tuple b);
t_tuple neg_tuple(t_tuple tuple);
t_tuple scalar_mult_tuples(t_tuple t, double s);
t_tuple scalar_div_tuples(t_tuple t, double s);



#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:07:37 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/24 11:09:23 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "tuples.h"

//operations -------------------------------------------------

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	return (create_tuple((a.x + b.x), (a.y + b.y), (a.z + b.z), (a.w + b.w)));
}

t_tuple	sub_tuples(t_tuple a, t_tuple b)
{
	return (create_tuple((a.x - b.x), (a.y - b.y), (a.z - b.z), (a.w - b.w)));
}

t_tuple	neg_tuple(t_tuple tuple)
{
	t_tuple ret;



	ret = create_tuple(-(tuple.x), -(tuple.y), -(tuple.z), -(tuple.w));
	if(ret.val[0] == -0)
		ret.val[0] = +0;
	if(ret.val[1] == -0)
		ret.val[1] = +0;
	if(ret.val[2] == -0)
		ret.val[2] = +0;
	if(ret.val[3] == -0)
		ret.val[3] = +0;
	return (ret);
}

t_tuple	scalar_mult_tuples(t_tuple t, double s)
{
	return (create_tuple((t.x * s), (t.y * s), (t.z * s), (t.w * s)));
}

t_tuple	scalar_div_tuples(t_tuple t, double s)
{
	return (create_tuple((t.x / s), (t.y / s), (t.z / s), (t.w / s)));
}

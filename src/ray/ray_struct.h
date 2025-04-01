/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:37:14 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/01 10:46:31 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RAY_STRUCT_H
#define RAY_STRUCT_H

typedef union s_ray
{
	struct
	{
		t_tuple origin;
		t_tuple direction;
	};
	t_tuple all[2];
} t_ray;

#endif

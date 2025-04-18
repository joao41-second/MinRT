/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:58:32 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/18 10:45:20 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_SRUCT_H
#define LIGHT_SRUCT_H

#include "../miniRT_struct.h"

typedef struct s_computations 
{
	void *object;
	t_point point;
	t_vector norm;
	t_tuple eyev;
	double 	t;
	int 	inside;
} t_computations;

#endif 

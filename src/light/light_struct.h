/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:58:32 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/06 13:48:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_STRUCT_H
# define LIGHT_STRUCT_H

# include "../miniRT_struct.h"

typedef struct s_computations
{
	void		*object;
	t_point		point;
	t_vector	norm;
	t_tuple		eyev;
	double		t;
	int			inside;
}				t_computations;

typedef struct s_var_lighting
{
	t_color	ret;
	t_color	efectiv;
	t_color	amb_c;
	t_tuple	luztv;
	double	t_luz_dot_normal;
	t_color	diffuse;
	t_color	sepcular;
	double	reflect_dot_eye;
	double	fact;
}	t_lightnig;
#endif

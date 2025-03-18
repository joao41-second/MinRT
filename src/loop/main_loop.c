/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/18 14:39:08 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void main_loop(t_minirt * rt_struct)
{

	canva_set_pixel(rt_struct,  5, 5,color_new(255,0,0));
	canva_update(rt_struct);

}

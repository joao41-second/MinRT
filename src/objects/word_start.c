/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:35:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/08 21:20:57 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void start_word(t_minirt  *rt_struct)
{
	t_sphere sph;
	t_sphere sph2;
	t_obj_int intr_in_objc;
	t_list_ *word_objects;

	word_objects = NULL;
	sph = sphere(create_point(0, 0, 0),1) ;
	//ray_set_transform(&sph,mat_multip(mat_gener_scal(1, 0.5, 1), mat_gener_rota('Z',(M_PI/5 ))));
	ray_set_transform(&sph,mat_gener_scal(1, 1, 1));
	ft_add_node(&sph,&word_objects );
	sph2 = sphere(create_point(0, 0, 0),1) ;
	ray_set_transform(&sph2,mat_gener_scal(0.5, 0.5, 0.5) );
	ft_add_node(&sph2,&word_objects);	
	rt_struct->word = ft_node_start(word_objects);
	rt_struct->luz = ligth_init(c_new(1,1,1), create_point(-10, 10, -10));	
	rt_struct->c_ray = ray_gener( create_point(0,0, -5), create_vector(0, 0, 1));


}

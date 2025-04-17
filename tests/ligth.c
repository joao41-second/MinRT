/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:13:29 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/08 21:14:47 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <stdio.h>

int error_(char *name,int nb, int *error)
{
	if(*error != 0)
	{
		printf(COLOR_RED "%s :error in %d \n",name,nb);
		error = 0;
		return(1);
	}
	return(0);
}

int norm_l(char *name,t_point point,t_point sph_p,t_vector chek)
{
	t_sphere sph;
	int error;
	static int nb;
	t_vector test;

	(void)sph_p;
	error = 0;

	sph = sphere(create_point(0, 0, 0),1);
	test = lig_normalize(sph, point);
	error += is_equal_tuple(test, chek);
	nb++;

	return( error_(name,nb,&error));

}



void _random()
{	
	t_minirt rt_struct;
	t_ray ray;
	t_color color;
	start_word(&rt_struct);

	 ray = ray_gener(create_point(0, 0, -5), create_vector(0, 0, 1));
	 color = lig_color_at(&rt_struct, ray);
	 printf("color %f %f %f \n",color.red,color.blue,color.green);

}

void normalize_(void)
{
	char *name;
	int check;

	name = "ligth";
	check = 0;
	check += norm_l(name,create_point(0,0,0),create_point(0, 0, 0),create_vector(0, 0, 0));
	_random();
	
	if(check == 0)
		printf(" %s: good tests ok",name);
}

void	test_ligth(void)
{
	RUN_TEST(normalize_);

}

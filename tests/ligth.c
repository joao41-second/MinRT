/*                                                        :::      ::::::::   */
/*   ligth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:13:29 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/23 16:51:26 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <math.h>
#include <stdio.h>

int error_(char *name,int nb, int *error)
{
	if(*error != 0)
	{
		printf(COLOR_RED "%s :error in %d \n" COLOR_RESET ,name,nb);
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
	ray_set_transform(&sph,mat_gener_scal( 1, 1, 1));
	test = lig_normalize(sph, point);
	if (!is_equal_tuple(test, chek))
		error ++;
	nb++;
	return( error_(name,nb,&error));

}

int lig_lighting_test(t_light luz ,t_vector norm,t_vector eyev,t_color resp)
{
	static int nb;
	int error;
	t_mater mat;
	t_computations comp;
	t_ray ray;
	t_color color;

	error = 0;
	mat  = obj_material_init(c_new(1,1,1), obj_init_values_material(0.1, 0.9, 0.9, 200));
	comp.eyev = eyev;
	comp.norm  = norm;
	comp.point = create_point(0, 0, 0);
	
	color  = lig_lighting(mat, luz, comp);
	if(c_chek_iqual_color(color, resp) != TRUE)
		error++;
	nb++;
	return( error_("lig_lighting",nb,&error));

}


void _random()
{	
	t_minirt rt_struct;
	t_ray ray;
	t_color color;
	start_word(&rt_struct);
	ray = ray_gener(create_point(0, 0, -5), create_vector(0, 0, 1));
	 color = lig_color_at(&rt_struct, ray);

}
int lig_reflect_test(t_vector norm,t_vector vect,t_vector resp)
{
	static int nb;
	int error;

	error = 0;	
	if(!is_equal_tuple( lig_reflect(vect,norm),resp))
		error++;
	nb++;
	return( error_("lig_reflect",nb,&error));

}

int lig_normalize_test(t_sphere sph,t_point point,t_tuple resp)
{
	static int nb;
	int error;
	
	t_tuple var = lig_normalize(sph,point);
	error = 0;
	
	if(!is_equal_tuple(var,resp))
		error++;


//	mat_print(sph.transform);
//
//	printf("inv trasform \n");
//	mat_print(sph.inv_transform);
//	printf("transpose \n");
//	mat_print(sph.inv_transpose);
	lig_print_tuple(var);	
//	lig_print_tuple(point);
	lig_print_tuple(resp);

	nb++;
	return( error_("lig_reflect",nb,&error));

}

void normalize_test_()
{
	int check;
	t_sphere sph;

	check = 0;
	sph = sphere(create_point(0, 0, 0),1);
	ray_set_transform(&sph,mat_gener_trans(0, 1, 0) );
	check += lig_normalize_test(sph, create_point(0, 1.70711, -0.70711), create_vector(0, 0.70711, -0.70711));
	
	ray_set_transform(&sph, mat_multip(mat_gener_scal(1, 0.5, 1),mat_gener_rota('z',M_PI/5)));

	check += lig_normalize_test(sph, create_point(0, M_SQRT2/2, -M_SQRT2/2), create_vector(0, 0.97014, -0.24254));
	if(check == 0)
		printf(COLOR_GREEN" %s: good lig_normalize tests ok\n"COLOR_RESET,"ligt");	
	check = 0;	
}

void normalize_(void)
{
	char *name;
	int check;

	name = "ligth";
	check = 0;
	check += norm_l(name,create_point(1,0,0),create_point(0, 0, 0),create_vector(1, 0, 0));
	check += norm_l(name,create_point(0,1,0),create_point(0, 0, 0),create_vector(0, 1, 0));
	check += norm_l(name,create_point(0,0,0),create_point(0, 0, 0),create_vector(0, 0, 0));	
	check += norm_l(name,create_point(sqrt(3)/3, sqrt(3)/3 , 
				sqrt(3)/3),create_point(0, 0, 0),create_vector(sqrt(3)/3, sqrt(3)/3,  sqrt(3)/3));	
	if(check == 0)
		printf( COLOR_GREEN" %s: good normalize_ tests ok\n"COLOR_RESET,name);
	check = 0;
	check += lig_lighting_test(ligth_init(c_new(1,1,1),create_point(0, 0, -10)),
			create_vector(0, 0, -1),create_vector(0, 0, -1),c_new(1.9,1.9,1.9));
	check += lig_lighting_test(ligth_init(c_new(1,1,1),
				create_point(0, 0,-10)), create_vector(0, 0, -1),
			create_vector(0,  M_SQRT2/2, -M_SQRT2/2),c_new(1,1,1));
	check += lig_lighting_test(ligth_init(c_new(1,1,1),
				create_point(0, 10,-10)), create_vector(0, 0, -1),
			create_vector(0,  0, -1),c_new(0.736396 ,0.736396 ,0.736396 ));
	check += lig_lighting_test(ligth_init(c_new(1,1,1),
				create_point(0, 10,-10)), create_vector(0, 0, -1),
			create_vector(0,  -M_SQRT2/2, -M_SQRT2/2),c_new(1.6364,1.6364,1.6364));
	check += lig_lighting_test(ligth_init(c_new(1,1,1),
				create_point(0, 0,10)), create_vector(0, 0, -1),
			create_vector(0,  0, -1),c_new(0.1,0.1,0.1));
	if(check == 0)
		printf( COLOR_GREEN" %s: good lig_lighting_test_ tests ok\n"COLOR_RESET,name);
	check = 0;
	
	check += lig_reflect_test(create_vector(0,1,0),create_vector(1, -1, 0), create_vector(1, 1, 0));

	check += lig_reflect_test(create_vector(M_SQRT2/2,M_SQRT2/2,0),create_vector(0,-1, 0), create_vector(1, 0, 0));

	if(check == 0)
		printf( COLOR_GREEN" %s: good lig_reflect tests ok\n"COLOR_RESET,"ligt");
	normalize_test_();
}

void	test_ligth(void)
{
	RUN_TEST(normalize_);

}

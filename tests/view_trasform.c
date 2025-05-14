/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_trasform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:15:30 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/29 17:22:26 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.h"
#include <math.h>
#include <stdio.h>

int lig_view_transform_test( t_tuple form, t_tuple to ,t_tuple up, t_matrix repons)
{
	static int nb;
	int error;
	
	error = 0;
	t_matrix mat;
	mat = lig_view_transform(form, to, up);
	if(mat_iqual(mat, repons) == FALSE)
		error++;
	nb++;
	return( error_("view_trasform",nb,&error));
}


int cm_init_test(double x , double y ,double next,double result)
{
	int error;
	
	error = 0;
	static int nb;
	t_camera_ms cam;
	cam  = cm_init(x, y, next, mat_gener(4));


	if(!is_equal_double(cam.pixel_size, result))
	{
		error++;
	}

	return( error_("camara_cm",nb,&error));
}

void view_transform_tests()
{

	char *name;
	int check;
	t_matrix matrix;
	double ** mat = mat_gener(4).matr ;

	mat[0][0] = -0.50709; mat[0][1] =  0.50709; mat[0][2] =  0.67612; mat[0][3] = -2.36643;
	mat[1][0] =  0.76772; mat[1][1] =  0.60609; mat[1][2] =  0.12122; mat[1][3] = -2.82843;
	mat[2][0] = -0.35857; mat[2][1] =  0.59761; mat[2][2] = -0.71714; mat[2][3] =  0.00000;
	mat[3][0] =  0.00000; mat[3][1] =  0.00000; mat[3][2] =  0.00000; mat[3][3] =  1.00000;

	matrix = mat_gener(4);
	matrix.matr = mat;
	

	check = 0;

	check += lig_view_transform_test(create_point(0, 0, 8), create_point(0, 0, 0), create_vector(0, 1, 0),
			mat_gener_trans(0, 0, -8));
	
	check += lig_view_transform_test(create_point(0, 0, 0), create_point(0, 0, 1), create_vector(0, 1, 0),	
			mat_gener_scal(-1,1, -1));

	check += lig_view_transform_test(create_point(0, 0, 0), create_point(0, 0, -1), create_vector(0, 1, 0),	
			mat_gener_identity(4));

	check += lig_view_transform_test(create_point(1, 3, 2), create_point(4, -2, 8), create_vector(1, 1, 0),	
		matrix);

	if(check == 0)
		printf( COLOR_GREEN" %s: good tests ok\n"COLOR_RESET,"view_trasform");
	

	check = 0;
	check += cm_init_test(200, 125, M_PI/2, 0.01);

	check += cm_init_test(125, 200, M_PI/2, 0.01);

	if(check == 0)
		printf( COLOR_GREEN" %s: good tests ok\n"COLOR_RESET,"cm_init");
}

void	test_view_trasfomr(void)
{
	RUN_TEST(view_transform_tests);

}

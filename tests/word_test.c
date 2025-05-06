#include "tests.h"
#include <stdint.h>
#include <stdio.h>


int test_shade_it(t_ray ray, t_color ret,t_minirt rt)
{
	static int nb;
	int error;
	
	error = 0;
	
	t_color color;
	color  = lig_color_at(&rt,ray);

	if(c_chek_iqual_color(color, ret) == FALSE)
		error++;	
	nb++;
	return( error_("color_at",nb,&error));
}
int test_shade_wor_it(double vaule, t_ray ray, t_color ret,t_minirt rt)
{
	static int nb;
	int error;
	error = 0;
	

	t_color color;
	t_obj_int obj;	
	t_computations comp;

	obj = ray_for_objects(rt.word, ray);
	obj.max = vaule;
	obj.min = vaule;
	comp = lig_prepare_computations(obj, ray);

	color = lig_shade_hit(obj, rt.luz,comp);
	
	if(c_chek_iqual_color(color, ret) == FALSE)
		error++;	
	nb++;
	return( error_("shade_hit",nb,&error));
}

int int_spher(t_matrix ok, t_ray ray,double rot,double resp)
{
	static int nb;
	int error;
	error = 0;


	t_obj_int obj;	
	t_computations comp;
	t_minirt rt;

	start_word_test(&rt,0.1, c_new(0.8,1,0.6));

	obj = ray_for_objects(rt.word, ray);
	printf("obj %f \n",obj.max);
	if(obj.max != INT_MAX)
		error++;
	nb++;
	return( error_("aaaaaaaaaa",nb,&error));
}


int test_shade_true(double vaule, t_ray ray, int tr,t_minirt rt)
{
	static int nb;
	int error;
	error = 0;
	

	t_color color;
	t_obj_int obj;	
	t_computations comp;

	obj = ray_for_objects(rt.word, ray);
	obj.max = vaule;
	obj.min = vaule;
	comp = lig_prepare_computations(obj, ray);

	color = lig_shade_hit(obj, rt.luz,comp);
	
	if(comp.inside != tr)
		error++;	
	nb++;
	return( error_("shade_hit",nb,&error));
}



void word_test()
{
	char *name;
	int check;
	t_matrix matrix;

	t_minirt rt;
	double ** mat = mat_gener(4).matr ;

	start_word_test(&rt,0.1, c_new(0.8,1,0.6));

	check = 0;
	check += test_shade_it( ray_gener(create_point(0, 0, -5), create_vector(0, 1, 0)), c_new(0,0,0),rt);
	check += test_shade_it( ray_gener(create_point(0, 0, -5), create_vector(0, 0, 1)), c_new(0.380661,0.475826,0.285496),rt);
	start_word_test(&rt,1,   c_new(0.8,1,0.6) );
	check += test_shade_it( ray_gener(create_point(0, 0, 0.75), create_vector(0, 0, -1)), c_new(0.8,1,0.6),rt);	
	if(check == 0)
		printf( COLOR_GREEN" %s: good tests ok\n"COLOR_RESET,"at_color");	
	check = 0;

	start_word_test(&rt,0.1, c_new(0.8,1,0.6));

	check += test_shade_wor_it(4 ,ray_gener(create_point(0, 0,
					-5), create_vector(0, 0, 1)), c_new(0.380661,0.475826,0.285496),rt);
	start_word_test(&rt,0.1,c_new(1,1,1));
	rt.luz.point = create_point(0, 0.25, 0);
	check += test_shade_wor_it(0.5 ,ray_gener(create_point(0, 0, 0)
				, create_vector(0, 0, 1)), c_new( 0.904984,0.904984,0.904984),rt);
	check += test_shade_true(0.5 ,ray_gener(create_point(0, 0, -5), create_vector(0, 0, 1)), FALSE,rt);
	check += test_shade_true(0.5 ,ray_gener(create_point(0, 0, 0), create_vector(0, 0, 1)), TRUE,rt);

	if(check == 0)
		printf( COLOR_GREEN" %s: good tests ok\n"COLOR_RESET,"shade_hit");	
	
	t_matrix ok;
	int_spher(ok, ray_gener(create_point(0, 0, -2), create_vector(0, 0, -1)),0.05,INT_MAX);

	int_spher(ok, ray_gener(create_point(0, 0, -2), create_vector(0, 0, 1)),0.05,INT_MAX);

	if(check == 0)
		printf( COLOR_GREEN" %s: good tests ok\n"COLOR_RESET,"double oble");	
	check = 0;




}
void	test_word(void)
{
	RUN_TEST(word_test);

}

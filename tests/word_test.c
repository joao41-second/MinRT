#include "tests.h"


int test_shade_it(t_ray ray, t_color ret,t_minirt rt)
{
	static int nb;
	int error;
	
	error = 0;
	
	t_color color;
	color  = lig_color_at(&rt,ray);
	c_print(color);
	if(c_chek_iqual_color(color, ret) == FALSE)
		error++;	
	nb++;
	return( error_("camara_cm",nb,&error));
}

void word_test()
{
	char *name;
	int check;
	t_matrix matrix;

	t_minirt rt;
	double ** mat = mat_gener(4).matr ;

	start_word_test(&rt,0.2);

	check = 0;
	check += test_shade_it( ray_gener(create_point(0, 0, -5), create_vector(0, 1, 0)), c_new(0,0,0),rt);

	check += test_shade_it( ray_gener(create_point(0, 0, -5), create_vector(0, 0, 1)), c_new(0.38066,0.47583,0.2855),rt);

	start_word_test(&rt,1);
	check += test_shade_it( ray_gener(create_point(0, 0, 0.75), create_vector(0, 0, -1)), c_new(1,0.2,0.5),rt);
	


	if(check == 0)
		printf( COLOR_GREEN" %s: good tests ok\n"COLOR_RESET,"at_color");	


}
void	test_word(void)
{
	RUN_TEST(word_test);

}

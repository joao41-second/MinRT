
#include "./tests.h"
#include <math.h>
#include <stdio.h>



int stripe_ex(t_color a ,t_color b,t_point point,t_color rest)
{
	int error;
	static int nb;	
	error = 0;


	if(c_chek_iqual_color(pat_stripe_at(point, 'x', a, b), rest))
	{
		error++;
	}
	nb++;
	return( error_("camara_cm",nb,&error));
}

void stripe_test()
{

	char *name;
	int check;
	check = 0;

	check +=  stripe_ex(c_new(0,0,0),c_new(1, 0, 0),create_point(0, 0, 0), c_new(0, 0, 0));

	check +=  stripe_ex(c_new(0,0,0),c_new(1, 0, 0),create_point(0, 1, 0), c_new(0, 0, 0));

	check +=  stripe_ex(c_new(0,0,0),c_new(1, 0, 0),create_point(0, 2, 0), c_new(0, 0, 0));

	check +=  stripe_ex(c_new(0,0,0),c_new(1, 0, 0),create_point(0, 0, 0), c_new(0, 0, 0));

	check +=  stripe_ex(c_new(0,0,0),c_new(1, 0, 0),create_point(0, 0, 1), c_new(0, 0, 0));
	
	check +=  stripe_ex(c_new(0,0,0),c_new(1, 0, 0),create_point(0, 0, 2), c_new(0, 0, 0));

	check +=  stripe_ex(c_new(0,0,0),c_new(1, 0, 0),create_point(0, 8, 0), c_new(0, 0, 0));

	check +=  stripe_ex(c_new(0,0,0),c_new(1, 0, 0),create_point(8.9, 0, 0), c_new(0, 0, 0));
	
	check +=  stripe_ex(c_new(0,0,0),c_new(1, 0, 0),create_point(1, 0, 0), c_new(1, 0, 0));

	check +=  stripe_ex(c_new(0,0,0),c_new(1, 0, 0),create_point(-0.1, 0, 0), c_new(1, 0, 0));

	check +=  stripe_ex(c_new(0,0,0),c_new(1, 0, 0),create_point(-1, 0, 0), c_new(1, 0, 0));

	check +=  stripe_ex(c_new(0,0,0),c_new(1, 0, 0),create_point(-1.1, 0, 0), c_new(0, 0, 0));





	if(check == 0)
		printf( COLOR_GREEN" %s: good tests ok\n"COLOR_RESET,"stripe");
	

	check = 0;


	if(check == 0)
		printf( COLOR_GREEN" %s: good tests ok\n"COLOR_RESET,"cm_init");
}

void	stripe(void)
{
	RUN_TEST(stripe_test);

}

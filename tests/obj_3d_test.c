
#include "./tests.h"
#include <math.h>
#include <stdio.h>



int color_get_trinang(t_ray ray,t_minirt *rt_struct,t_color rest)
{
	int error;
	static int nb;	
	error = 0;

	t_color color = lig_color_at(rt_struct,ray);
	if(c_chek_iqual_color(color,rest))
	{
		error++;
	}
	nb++;
	return( error_("camara_cm",nb,&error));
}

void _3d_test()
{

	char *name;
	int check;
	check = 0;

	t_minirt rt_struct ;
	start_word(&rt_struct);
//	t_matrix	ok = lig_view_transform(rt_struct.point,
//			create_point(0, 0, 0), create_vector(0, 1, 0));
//	rt_struct.cam_m = cm_init(WALL_X, WALL_Y, M_PI / 3, ok);

//	rt_struct.cam = cm_ray_for_pixel(rt_struct.cam_m,
//			(double)WALL_X / 2, (double)WALL_Y / 2);
//	rt_struct.rota_y = 0;
//	rt_struct.rota_x = 0;


//	check +=  color_get_trinang(ray_gener((t_point){1,1,-3},(t_vector) {-0.3,-0.3,0.9}), &rt_struct, c_new(1,1,1));





	if(check == 0)
		printf( COLOR_GREEN" %s: good tests ok\n"COLOR_RESET,"stripe");
	

	check = 0;


	if(check == 0)
		printf( COLOR_GREEN" %s: good tests ok\n"COLOR_RESET,"cm_init");
}

void texture_3d (void)
{
	RUN_TEST(_3d_test);

}

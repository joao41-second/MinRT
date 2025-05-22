// #include "tests.h"
// #include <math.h>
// #include <stdio.h>

// int ray_for_object_text( t_ray ray ,double_t resp)
// {
// 	static int nb;	
// 	int error;
// 	t_minirt 	*rt_struct;
// 	t_obj_int	obj;
// 	t_matrix 	ok;
	
// 	error = 0;
// 	rt_struct = ft_malloc(sizeof(t_minirt)*1, NULL);
	
// 	start_word_test(rt_struct,1,c_new(1,1,1));
	
// 	obj = ray_for_objects(rt_struct->word, ray, ray);
// 	printf("int max %f and min %f \n",obj.min,obj.max);
// 	if(!is_equal_double( resp,obj.min))
// 		error++;
// 	nb++;
// 	return( error_("view_trasform",nb,&error));
// }




// void shp_text_intrect()
// {

// 	char *name;
// 	int check;
// 	t_matrix matrix;


// 	matrix = mat_gener(4);
	

// 	check = 0;
// 	printf("wtf\n");

// 	check += ray_for_object_text(ray_gener(create_point(0, 0, -3), create_point(0, 0, 1)), 3);
// 	if(check == 0)
// 		printf( COLOR_GREEN" %s: good tests ok\n"COLOR_RESET,"shp");
	

// 	check = 0;


// //	if(check == 0)
// //		printf( COLOR_GREEN" %s: good tests ok\n"COLOR_RESET,"cm_init");
// }

// void	shp_text(void)
// {

// 	RUN_TEST( shp_text_intrect);

// }

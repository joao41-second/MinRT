
#include "../minRT.h"
#include <math.h>

t_vector lig_normalize(t_sphere sph,t_point p_the_obj) 
{
	t_vector ret;
	t_point obj_point;
	t_point obj_word;

	t_point temp;
	
  	 obj_point  = mat_x_tuple(p_the_obj, sph.inv_transform);
	 obj_word = sub_tuples(obj_point, create_point(0, 0, 0));
	 ret = mat_x_tuple(obj_word, sph.inv_transpose);
	 ret.w = 0;
//	ret = normalize(&ret);
	return (ret);
}

t_vector lig_reflect(t_vector in ,t_vector normal)
{
	t_vector ret;

	ret =  sub_tuples( in, scalar_mult_tuples(normal, 2 * dot_product(in, normal)));
	return (ret);
}


#include "../minRT.h"
#include <math.h>

// t_vector lig_normalize(t_sphere sph,t_point p_the_obj) 
// {
// 	t_vector ret;
// 	t_point obj_point;
// 	t_point obj_word;

// 	t_point temp;
	
//   	 obj_point  = mat_x_tuple(p_the_obj, sph.inv_transform);
// 	 obj_word = sub_tuples(obj_point, create_point(0, 0, 0));
// 	 ret = mat_x_tuple(obj_word, sph.inv_transpose);
// 	 ret.w = 0;
// 	ret = normalize(ret);
// 	return (ret);
// }
t_vector lig_normalize(t_object *obj,t_point p_the_obj) 
{
	t_vector ret;
	t_point obj_point;
	t_point obj_word;

	t_point temp;
	if (obj->type == OBJ_SPHERE) 
    {
        t_sphere *sphere = &obj->u_data.sphere;
        obj_point = mat_x_tuple(p_the_obj, sphere->inv_transform);
        obj_word = sub_tuples(obj_point, create_point(0, 0, 0));
        ret = mat_x_tuple(obj_word, sphere->inv_transpose);
    }
    else if (obj->type == OBJ_PLANE) 
    {
        t_plane *plane = &obj->u_data.plane;
        // For planes, the normal is constant and does not depend on the point
        ret = mat_x_tuple(create_vector(0, 1, 0), plane->inv_transform);
    }
    else if (obj->type == OBJ_TRIANGLE) 
    {
        t_triangle *triangle = &obj->u_data.triangle;
        // For triangles, the normal is calculated using the cross product of two edges
        t_vector edge1 = sub_tuples(triangle->p2, triangle->p1);
        t_vector edge2 = sub_tuples(triangle->p3, triangle->p1);
        ret = normalize(cross_product(edge1, edge2));
    }
	ret = normalize(ret);
	return (ret);
}

t_color lig_lighting(t_mater mat,t_light luz,t_point point,t_vector norm,t_tuple eyev)
{
	t_color ret;
	t_color efectiv;
	t_color amb_c;
	t_tuple luztv;
	double t_luz_dot_normal;
	t_color diffuse;
	t_color sepcular;
	double reflect_dot_eye;
	double fact;
	
	
	efectiv = c_multipl(mat.color,luz.intenstiy );
	luztv = normalize(sub_tuples(luz.point,point));
	amb_c = c_scalar_multipl(efectiv, mat.values.amb);

	t_luz_dot_normal = dot_product(luztv, norm);
	if(t_luz_dot_normal < 0)
	{
		diffuse = c_new(0,0,0);
		sepcular = c_new(0,0,0);
	}
	else
	{
		diffuse = c_scalar_multipl(c_scalar_multipl(efectiv, mat.values.diffuse),t_luz_dot_normal);
	 	reflect_dot_eye  = dot_product(lig_reflect(neg_tuple(luztv),norm),eyev);
		if(reflect_dot_eye <= 0)	
			sepcular = c_new(0,0,0);
		else
		{
			fact  = pow(reflect_dot_eye,mat.values.shininess );
			sepcular = c_scalar_multipl(c_scalar_multipl(luz.intenstiy, mat.values.specular), fact);
		}
	}
	ret = c_adding(sepcular,c_adding(diffuse, amb_c));
	return (ret);
}

t_vector lig_reflect(t_vector in ,t_vector normal)
{
	t_vector ret;

	ret =  sub_tuples( in, scalar_mult_tuples(normal, 2 * dot_product(in, normal)));
	return (ret);
}




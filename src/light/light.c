/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:34:08 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/06 12:56:01 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "../minRT.h"
#include "light_struct.h"
#include <math.h>
#include <stdio.h>

// t_vector	lig_normalize(t_sphere sph, t_point p_the_obj)
// {
// 	t_vector	ret;
// 	t_point		obj_point;
// 	t_point		obj_word;


// 	obj_point = mat_x_tuple(p_the_obj, sph.inv_transform);
	 

// 	obj_word = sub_tuples(obj_point, create_point(0, 0, 0));	
	
// 	ret = mat_x_tuple(obj_word, sph.inv_transpose);	

// 	ret = normalize(create_vector(ret.x, ret.y, ret.z));

// 	return (ret);
// }
void mat_fprint(FILE *file, t_matrix mat)
{
    if (!file)
        return;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fprintf(file, "%f ", mat.matr[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}
t_vector lig_normalize_obj(t_object obj, t_point p_the_obj)
{
    t_vector ret;
    t_point obj_point;
    t_point obj_word;
    FILE *debug_file = fopen("debug_normals.log", "a");

    if (obj.type == OBJ_SPHERE)
    {
        obj_point = mat_x_tuple(p_the_obj, obj.u_data.sphere.inv_transform);
        obj_word = sub_tuples(obj_point, create_tuple(0, 0, 0,0));
        ret = mat_x_tuple(obj_word, obj.u_data.sphere.inv_transpose);
		ret.w = 0;
    }
    else if (obj.type == OBJ_PLANE)
    {
		obj_point = mat_x_tuple(p_the_obj, obj.u_data.plane.inv_transform);
		t_vector obj_normal = create_vector(0, 1, 0);
		ret = mat_x_tuple(obj_normal, obj.u_data.plane.inv_transpose);
		ret.w = 0; 
		ret = normalize(ret);
        // if (debug_file)
        // {
        //     fprintf(debug_file, "Plane Point: (%f, %f, %f)\n", obj_point.x, obj_point.y, obj_point.z);
        //     fprintf(debug_file, "Plane Normal Before Normalize: (%f, %f, %f)\n", ret.x, ret.y, ret.z);
        //     fprintf(debug_file, "Plane Transform:\n");
        //     mat_fprint(debug_file, obj.u_data.plane.transform);
        //     fprintf(debug_file, "Plane Inverse Transform:\n");
        //     mat_fprint(debug_file, obj.u_data.plane.inv_transform);
        //     fprintf(debug_file, "Plane Inverse Transpose:\n");
        //     mat_fprint(debug_file, obj.u_data.plane.inv_transpose);
        // }
    }
	else if (obj.type == OBJ_TRIANGLE)
	{
		obj_point = mat_x_tuple(p_the_obj, obj.u_data.triangle.inv_transform);
		obj_word = sub_tuples(obj_point, create_point(0, 0, 0));
		ret = mat_x_tuple(obj_word, obj.u_data.triangle.inv_transpose);
	}
    else
    {
        ret = create_vector(0, 0, 0);
    }
    // if (debug_file)
    // {
    //     fprintf(debug_file, "Plane Normal After Normalize: (%f, %f, %f)\n", ret.x, ret.y, ret.z);
    //     fclose(debug_file); // Close the debug file
    // }
    return normalize(ret);
}


t_color	lig_lighting(t_mater mat, t_light luz, t_computations comp)
{
	t_color	ret;
	t_color	efectiv;
	t_color	amb_c;
	t_tuple	luztv;
	double	t_luz_dot_normal;
	t_color	diffuse;
	t_color	sepcular;
	double	reflect_dot_eye;
	double	fact;
	
	efectiv = c_multipl(mat.color, luz.intenstiy) ;
	luztv = normalize(sub_tuples(luz.point, comp.point));
//	amb_c = c_scalar_multipl(efectiv, mat.values.amb);

	amb_c = c_multipl(efectiv,c_new(mat.values.amb, mat.values.amb, mat.values.amb));
	t_luz_dot_normal = dot_product( luztv,comp.norm);

	    // // Debugging: Print material properties
		// printf("Material Color: (%f, %f, %f)\n", mat.color.red, mat.color.green, mat.color.blue);
		// printf("Ambient: %f, Diffuse: %f, Specular: %f, Shininess: %f\n",
		// 	   mat.values.amb, mat.values.diffuse, mat.values.specular, mat.values.shininess);
	
			   
	
	if(t_luz_dot_normal == -0)
		t_luz_dot_normal = 0;
	if (t_luz_dot_normal < 0)
	{
		diffuse = c_new(0, 0, 0);
		sepcular = c_new(0, 0, 0);
	}
	else
	{
		diffuse = c_scalar_multipl(efectiv,mat.values.diffuse * t_luz_dot_normal);
		reflect_dot_eye = dot_product(lig_reflect(neg_tuple(luztv),comp.norm), comp.eyev);
		if (reflect_dot_eye <= 0)
			sepcular = c_new(0, 0, 0);
		else
		{
			fact = pow(reflect_dot_eye, mat.values.shininess);
			sepcular = c_scalar_multipl(luz.intenstiy,mat.values.specular* fact);
		}
	
	}
	ret = c_adding(c_adding(  sepcular, amb_c), diffuse);	
	return (ret);
}

t_vector	lig_reflect(t_vector in, t_vector normal)
{
	t_vector	ret;

	ret = sub_tuples(in, scalar_mult_tuples(normal,
				2 * dot_product(in, normal)));
	return (ret);
}

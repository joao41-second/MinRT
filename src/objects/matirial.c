/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matirial.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:10:41 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/07 12:11:09 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../minRT.h"

t_m_values obj_init_values_material(double ambient ,double diffuse, double sepcular ,double shininess)
{
	t_m_values ret;
	ret.amb = ambient;
	ret.diffuse = diffuse;
	ret.specular = sepcular;
	ret.shininess = shininess;
	return(ret);
}

t_mater obj_material_init(t_color intensty,t_m_values values)
{
	t_mater ret;
	ret.values = values;
	ret.color = intensty;
	return(ret);
}


void obj_material_print(t_mater mat)
{
	printf("mat color r %f,g %f,b %f \n",mat.color.red,mat.color.green,mat.color.blue);
	printf(" ambinet %f, diffuse %f , sepcular %f , shininess %f \n",
			mat.values.amb,mat.values.diffuse,mat.values.specular,mat.values.shininess);
}

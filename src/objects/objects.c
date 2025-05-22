/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:45:40 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/07 11:46:28 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

t_mat_calculate obj_mat_calulate_init()
{
	t_mat_calculate ret;
	int x;

	x = -1;
	while (++x < 6)
	{
		ret.mat[x] = mat_gener(4);	
	}

	return (ret);
}

t_img_ *obj_creat_texture(t_canva canva,char *img)
{
	t_img_ *imgg;
	int i = 0;
	int a = 0;
	imgg =  ft_malloc(sizeof(t_img_*)*1, NULL);

	imgg[0].img = mlx_xpm_file_to_image(canva.mlx, img, &i, &a);
	imgg->addr = mlx_get_data_addr(imgg->img, &imgg->bits_per_pixel,&imgg->line_length, &imgg->endian);
	imgg->height = a;
	imgg->width = i;
	printf("open img %d , %d\n",a , i);
	return (imgg);	
}


t_object	*create_object(void *data, t_obj_type type, t_mater mat,t_img_ *img)
{
	t_object	*obj;

	obj = (t_object *)ft_malloc(sizeof(t_object), NULL);
	obj->type = type;
	obj->transform = mat_gener(4);
	obj->inv_transform = mat_gener(4);
	obj->inv_transpose = mat_gener(4);
	obj->matiral = mat;
	obj->mat_calculate = obj_mat_calulate_init();
	if (type == OBJ_SPHERE)
		obj->u_data.sphere = *(t_sphere *)data;
	else if (type == OBJ_PLANE)
		obj->u_data.plane = *(t_plane *)data;
	else if (type == OBJ_TRIANGLE)
        obj->u_data.triangle = *(t_triangle *)data;
	else if (type == OBJ_CYLINDER)
		obj->u_data.cylinder = *(t_cylinder *)data;
	obj->texture = img;
	return (obj);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:09:07 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/30 12:11:28 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minRT.h"
#include "objects.h"
#include <endian.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void obj_add_trinagles( t_object *obj_t , char** file, char** point, t_point *list)
{
	int i;
	int nb_f_c;
	i = -1;
	nb_f_c =-1;
	while (file[++i] != NULL) 
	{
		if( file[i] != NULL && file[i][0] == 'f')
		{
			point = ft_split(file[i], ' ');
			
			obj_set_new_null(point[1],  '/');
			obj_set_new_null(point[2],  '/');
			obj_set_new_null(point[3],  '/');
			ft_pocket_set("main");	
			if(point[4] != NULL)
			{
				obj_set_new_null(point[4],  '/');
				obj_t->triangle[++nb_f_c] = create_triangle(list[ft_atol(point[1])] ,
							list[ft_atol(point[2])], 
							list[ft_atol(point[3])]);
				obj_t->triangle[++nb_f_c] = create_triangle(list[ft_atol(point[4])] ,
							list[ft_atol(point[1])], 
							list[ft_atol(point[3])]);
			}
			else
				obj_t->triangle[++nb_f_c] = create_triangle(list[ft_atol(point[1])] ,
							list[ft_atol(point[2])], 
						list[ft_atol(point[3])]);
			ft_pocket_set("add_obj");		
		}	
	}
	obj_t->u_data.triangle = obj_t->triangle[0];
}



void obj_open_stl_start(t_list_ *word, char *file_name,t_matrix matrix,t_mater mat)
{
	int fd;
	char **point;
	char **file;
	t_triangle new;
	t_object *obj_t;
	int nb_face;
	
	fd = open(file_name, O_RDONLY);
	if(fd < 0)
		return;
	close(fd);
	ft_pocket_new("add_obj");
	file = obj_get_file(file_name, &nb_face);
	nb_face = obj_locate_face(file);
	new = create_triangle((t_point){0,0,0}, (t_point){0,0,0}, (t_point){0,0,0});
	ft_pocket_set("main");		
	obj_t =  create_object(&new, OBJ_SQUARE,mat, NULL);
	obj_t->triangle = ft_malloc(nb_face * sizeof(t_triangle), NULL);
	ft_pocket_set("add_obj");			
	obj_add_trinagles(obj_t, file, point, obj_list_the_pointres(file_name));
	ft_free_all_pocket("add_obj");
	ray_set_transform_obj(obj_t, matrix);
	obj_t->index = nb_face;
	ft_add_node(obj_t, &word);
}

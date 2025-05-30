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

void obj_square_set(t_triangle *triangle,int i,t_point *points)
{
	triangle[i] = create_triangle(points[0],points[1],points[2]);
	triangle[i+1]  = create_triangle(points[3],points[0],points[2]);	
}

t_triangle *obj_cobe_cube(t_point max,t_point min)
{
	t_triangle *triangle;
	t_point *top;
	t_point *low;
	t_point *l1;
		
	triangle = ft_malloc(sizeof(t_triangle)*12,"main");
	lig_print_tuple(max);
	
	lig_print_tuple(min);
	top = obj_create_points(max, (t_point){max.x,min.y,max.z}, (t_point){min.x,min.y,max.z}, (t_point){min.x,max.y,max.z} );

	low = obj_create_points(min, (t_point){min.x,max.y,min.z}, (t_point){max.x,max.y,min.z}, (t_point){max.x,min.y,min.z} );
	obj_square_set(triangle, 0,top);
	obj_square_set(triangle,2, low);
	obj_square_set(triangle,4,  obj_create_points(min, (t_point){max.x,min.y,min.z} , (t_point){max.x,min.y,max.z}, (t_point){min.x,min.y,max.z}));

	obj_square_set(triangle,6,  obj_create_points(max, (t_point){min.x,max.y,max.z} , (t_point){min.x,max.y,min.z}, (t_point){max.x,max.y,min.z}));

	obj_square_set(triangle,8,  obj_create_points(min , (t_point){min.x,max.y,min.z}, (t_point){min.x,max.y,max.z},(t_point){min.x,min.y,max.z}  ));

	obj_square_set(triangle,10,  obj_create_points(max , (t_point){max.x,min.y,max.z}, (t_point){max.x,min.y,min.z},(t_point){max.x,max.y,min.z}  ));

	return (triangle);
}

void obj_add_hit_box( t_object *obj_t , int points, t_point *list)
{
	t_point min;
	t_point max;
	int i;
	
	i = 0;
	max = list[1];
	min = list[1];
	while (++i < points)
	{
		if(max.x < list[i].x)
			max.x = list[i].x;
		if(max.y < list[i].y)
			max.y = list[i].y;
		if(max.z < list[i].z)
			max.z = list[i].z;
		if(min.x > list[i].x)
			min.x = list[i].x;
		if(min.y > list[i].y)
			min.y = list[i].y;
		if(min.z > list[i].z)
			min.z = list[i].z;
	}

	obj_t->hit_box =  obj_cobe_cube(max,min);

	
}


void obj_open_stl_start(t_list_ *word, char *file_name,t_matrix matrix,t_mater mat)
{
	int fd;
	char **point;
	char **file;
	t_triangle new;
	t_object *obj_t;
	int nb_face;
	int nb;
	t_point *point_list;
	nb = 0;	
	fd = open(file_name, O_RDONLY);
	if(fd < 0)
		return;
	close(fd);
	ft_pocket_new("add_obj");
	file = obj_get_file(file_name, &nb_face);
	nb_face = obj_locate_face(file);
	new = create_triangle((t_point){0,0,0}, (t_point){0,0,0}, (t_point){0,0,0});
	ft_pocket_set("main");
	point_list = obj_list_the_pointres(file_name,&nb);

	ft_pocket_set("main");

	obj_t =  create_object(&new, OBJ_SQUARE,mat, NULL);	
	obj_add_hit_box(obj_t, nb,point_list );
	obj_t->triangle = ft_malloc(nb_face * sizeof(t_triangle), NULL);
	ft_pocket_set("add_obj");			
	obj_add_trinagles(obj_t, file, point,point_list );
	ft_free_all_pocket("add_obj");
	ray_set_transform_obj(obj_t, matrix);
	obj_t->index = nb_face;
	ft_add_node(obj_t, &word);
}

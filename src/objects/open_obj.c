/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:09:07 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/25 19:55:01 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minRT.h"
#include "objects.h"
#include <endian.h>
#include <fcntl.h>
#include <stdio.h>

t_point *obj_set_points(char *file_name,int nb)
{
	int fd;
	char *line;
	t_point *list;
	char **split;
	int nb_;

	list = ft_malloc((nb +1)* sizeof(t_point), "main");
	nb_ = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	printf("line %s --%d \n",line,nb);
	while (line != NULL) 
	{
		free(line);
		line = get_next_line(fd);

		if( line != NULL && line[0] == 'v' && line[1] == ' ')
		{ 

			nb_++;
			split = ft_split(line, ' ');
			list[nb_] = create_point(ft_atof(split[1], NULL), ft_atof(split[2], NULL), ft_atof(split[3], NULL));
		}
	}
	close(fd);
	return (list);	
}

t_point  * obj_list_the_pointres(char *file_name)
{
	int fd;
	int nb;
	char *line;
	
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	nb = 0;
	while (line != NULL) 
	{
		free(line);
		line = get_next_line(fd);
		if( line != NULL && line[0] == 'v' && line[1] == ' ' )
			nb++; 
	}
	free(line);
	close(fd);
		
	return (obj_set_points(file_name, nb));
}

void obj_set_new_null(char *str,char null_char)
{
	int i;
	i = -1;
	while (str[++i] != '\0' )
	{
		if(str[i] == null_char)	
		{
			str[i] = '\0';
		}
	}
}

char **obj_get_file(char *name,int *nb)
{
	char **file;
	int fd;
	int i;

	i = -1;
	*nb = 0;
	fd = open(name, O_RDONLY);
	if( fd < 0)
		return NULL;
	ft_pocket_new("len");
	while (ft_add_memory(get_next_line(fd),NULL) != NULL)
		(*nb)++;	
	ft_free_all_pocket("len");
	close(fd);
	fd = open(name, O_RDONLY);
	file = ft_malloc(sizeof(char*) * ((*nb)+1),NULL);
	while (++i < *nb)
	{
		file[i] = ft_add_memory(get_next_line(fd),NULL);
	}
	file[*nb] = NULL;
	return (file);
}

int obj_locate_face(char **file)
{
	int i;
	int nb;
	int len;
	char **split;

	nb = 0;
	i = -1;
	len = 0;

	while (file[++i] != NULL)
	{
		if(file[i][0] == 'f')
		{
			len = 0;
			split = ft_split(file[i], ' ');
			while (split[len] != NULL)
				len++;
			if(len > 4)
				nb++;
			nb++;
		}
	}
	return (nb);
}

void obj_open_stl_start(t_list_ *word, char *file_name,t_matrix matrix,t_mater mat)
{
	int fd;
	char *line;
	char **point;
	char **file;
	t_triangle new;
	t_object *obj_t;
	t_point *list;
	int file_line;
	int nb_face;
	int nb_f_c;
	
	nb_face = 0;
	nb_f_c =-1;
	fd = open(file_name, O_RDONLY);
	if(fd < 0)
		return;
	ft_pocket_new("add_obj");
	file = obj_get_file(file_name, &file_line);
	list = obj_list_the_pointres(file_name);
	nb_face = obj_locate_face(file);
	printf("nb_face %d \n",nb_face);
	line = get_next_line(fd);
	new = create_triangle((t_point){0,0,0}, (t_point){0,0,0}, (t_point){0,0,0});
	ft_pocket_set("main");		
	obj_t =  create_object(&new, OBJ_SQUARE,mat, NULL);
	obj_t->triangle = ft_malloc(nb_face * sizeof(t_triangle), NULL);
	ft_pocket_set("add_obj");		
	while (line != NULL) 
	{
		free(line);
		line = get_next_line(fd);
		if( line != NULL && line[0] == 'f')
		{
			point = ft_split(line, ' ');
			
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
			else{
			
				obj_t->triangle[++nb_f_c] = create_triangle(list[ft_atol(point[1])] ,
							list[ft_atol(point[2])], 
						list[ft_atol(point[3])]);
				}	

			ft_pocket_set("add_obj");		
		}	
	}
	obj_t->u_data.triangle = obj_t->triangle[0];
	ft_free_all_pocket("add_obj");
	ray_set_transform_obj(obj_t, matrix);
	obj_t->index = nb_f_c;
	obj_t->type = OBJ_SQUARE;
	ft_add_node(obj_t, &word);

}

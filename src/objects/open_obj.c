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
#include <unistd.h>

t_point *obj_set_points(char *file_name,int nb)
{
	int fd;
	char *line;
	t_point *list;
	char **split;
	int nb_;

	list = ft_malloc(nb*sizeof(t_point), "main");
	nb_ = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	printf("line %s --%d \n",line,nb);
	while (line != NULL) 
	{
		free(line);
		line = get_next_line(fd);

		if( line != NULL && line[0] == 'v' && nb_ < nb)
		{ 

		//	printf("oi \n");
			nb_++;
			split =ft_split(line, ' ');
			if(split[0] != NULL &&  split[1] != NULL && split[2] != NULL && split[3] != NULL && nb_ < nb)
				list[nb_] = create_point(ft_atof(split[1], NULL), ft_atof(split[2], NULL), ft_atof(split[3], NULL));
		//	lig_print_tuple(list[nb_]);
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
	while (++i < *nb-1)
	{
		file[i] = ft_add_memory(get_next_line(fd),NULL);
	}
	file[*nb] = NULL;

	return (file);
}

int obj_char_in_index( char **str , char ch ,int max)
{
	int i;
	int ret;

	i = -1;
	ret = 0;
	while (++i < max)
	{
		if(str[i][0] == ch)
			ret++;	
	}
	return (ret);
}

void obj_open_stl_start(t_object *word, char *file_name,t_matrix matrix,t_mater mat)
{
	int fd;
	char **point;
	char **file;
	t_object *obj_t;
	t_point *list;
	int len = -1;
	int i;

	i = -1;
	fd = open(file_name, O_RDONLY);
	if(fd < 0)
		return;
	close(fd);
	printf("raiva \n");
	ft_pocket_new("add_obj");
	list = obj_list_the_pointres(file_name);

	
	fd = 0;
	file = obj_get_file(file_name, &fd);
	t_triangle tig = create_triangle( (t_point){0,0,0}, (t_point) {0,0,0},(t_point) {0,0,0});
	obj_t= create_object(&tig, OBJ_SQUARE, mat,NULL);
	obj_t->index = obj_char_in_index(file, 'f',fd-1) *2;
	obj_t->triangle = ft_malloc(sizeof(t_triangle)*(obj_t->index+1), "main");
	printf(" %d nvim",fd);
	while (++len < fd-1)  
	{
		if(  file[len][0] == 'f')
		{
			i++;
			point = ft_split(file[len], ' ');	
			obj_set_new_null(point[1],  '/');
			obj_set_new_null(point[2],  '/');
			obj_set_new_null(point[3],  '/');
			if(point[4] != NULL){

				obj_set_new_null(point[4],  '/');
				if(i < obj_t->index && i++ <obj_t->index)
				{
					obj_t->triangle[i] = create_triangle(list[ft_atol(point[1])], list[ft_atol(point[2])],list[ft_atol(point[3])]);
					obj_t->triangle[++i]  = create_triangle(list[ft_atol(point[4])], list[ft_atol(point[1])], list[ft_atol(point[3])]);
				}
			}
			else if(i < obj_t->index)
			{
				obj_t->triangle[i] = create_triangle(list[ft_atol(point[1])], list[ft_atol(point[2])],list[ft_atol(point[3])]);
			}
		}	
	}
	
	//ft_free_all_pocket("add_obj");
	obj_t->type = OBJ_TRIANGLE;
	ray_set_transform_obj(obj_t,matrix);	
	obj_t->type = OBJ_SQUARE;
	obj_add(word,*obj_t,0);
}

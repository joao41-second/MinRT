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

	list = ft_malloc(nb*sizeof(t_point), NULL);
	nb_ = 0;
	fd = open(file_name, O_RDONLY);
	line = file_name;
	while (line != NULL) 
	{
		line = get_next_line(fd);
		if(line[0] == 'V' && line[1] == ' ')
		{ 	
			nb_++;
			split =ft_split(line, ' ');
			list[nb_] = create_point(ft_atof(split[1], NULL), ft_atof(split[1], NULL), ft_atof(split[1], NULL));
			lig_print_tuple(list[nb_]);
		}
		free(line);
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
	line = file_name;
	nb = 0;
	while (line != NULL) 
	{
		line = get_next_line(fd);
		if(line[0] == 'V' && line[1] == ' ')
			nb++; 
		free(line);
	}
	close(fd);
		
	return (obj_set_points(file_name, nb));
}


void obj_open_stl_start(t_list_ *word, char *file_name,t_matrix *matrix,t_mater mat)
{
	int fd;
	char *line;
	char **point;
	t_triangle new;
	t_object *obj_t;
	
	fd = open(file_name, O_RDONLY);
	if(fd < 0)
		return;
	ft_pocket_new("add_obj");
	ft_pocket_set("add_obj");
	line = get_next_line(fd);
	while (line != NULL) 
	{
		free(line);
		line = get_next_line(fd);
		if(line[0] == 'p')
		{
		
		}	
	}
	ft_free_all_pocket("add_obj");
}

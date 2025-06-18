/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:09:07 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/17 17:44:36 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"
#include "../objects.h"
#include <stdio.h>

char	*obj_texture_xpm(char *str_)
{
	int		i;
	char	*str;

	str = ft_strdup(str_);
	i = ft_strlen(str);
	str[i -1] = 'm';
	str[i -2] = 'p';
	str[i -3] = 'x';
	return (str);
}

void	obj_add_hit_box( t_object *obj_t, int points, t_point *list)
{
	t_point	min;
	t_point	max;
	int		i;	

	i = 0;
	max = list[1];
	min = list[1];
	while (++i < points)
	{
		if (max.x < list[i].x)
			max.x = list[i].x;
		if (max.y < list[i].y)
			max.y = list[i].y;
		if (max.z < list[i].z)
			max.z = list[i].z;
		if (min.x > list[i].x)
			min.x = list[i].x;
		if (min.y > list[i].y)
			min.y = list[i].y;
		if (min.z > list[i].z)
			min.z = list[i].z;
	}
	obj_t->hit_box = obj_cobe_cube(max, min);
}

int	obj_chek_fd(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	close(fd);
	return (TRUE);
}

void	obj_set_all_trianges(char *file_name, t_object *obj_t, char **file)
{
	t_point	*point_list;
	int		nb;	

	ft_pocket_set("main");
	point_list = obj_list_the_pointres(file_name, &nb);
	obj_add_hit_box(obj_t, nb, point_list);
	obj_add_trinagles(obj_t, file, point_list);
	obj_t->u_data.triangle = obj_t->triangle[0];
	ft_pocket_set("add_obj");
}

void	obj_open_stl_start(t_minirt *rt_struct, char *file_name,
		t_matrix matrix, t_mater mat)
{
	char		**file;
	t_triangle	new;
	t_object	*obj_t;
	int			nb_face;

	if (obj_chek_fd(file_name) < 0)
		return ;
	ft_pocket_new("add_obj");
	file = obj_get_file(file_name, &nb_face);
	nb_face = obj_locate_face(file);
	ft_pocket_set("main");
	new = create_triangle((t_point){{0, 0, 0}},
			(t_point){{0, 0, 0}}, (t_point){{0, 0, 0}});
	obj_t = create_object(&new, OBJ_SQUARE,
			mat, obj_creat_texture(rt_struct->canva,
				obj_texture_xpm(file_name)));
	obj_t->triangle = ft_malloc(nb_face * sizeof(t_triangle), "main");
	obj_set_all_trianges(file_name, obj_t, file);
	ray_set_transform_obj(obj_t, matrix);
	obj_t->index = nb_face;
	ft_add_node(obj_t, &rt_struct->word);
}

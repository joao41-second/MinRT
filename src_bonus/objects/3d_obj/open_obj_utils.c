/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_obj_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:09:07 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/17 17:44:23 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"
#include "../objects.h"
#include <stdio.h>

int  spl_nb_3(char *line, int i_[3])
{
	char len[1024];
	int i;
	int index = -1;
	int nb = -1;
	
	
	i = -1;
	while (line [++i] != '\0')
	{
		index++;
		len[index] = line[i];
		if(line[i] == '/' || line[i] == ' ' || line[i] == '\0')
		{
			len[index] = '\0';
			nb++;
			if(nb >= 0)	
				i_[nb] = ft_atoi(len);
			index = -1;
		}	
	}
	return (nb + 1);
	
}

int spl_get_int(const char *line, int vaule[4][3])
{
	char len[1024];
	int i;
	int index = -1;
	int nb = -1;
	
	
	i = -1;
	while (line [++i] != '\0')
	{
		index++;
		len[index] = line[i];
		if(line[i] == ' ' || line[i+1] == '\0')
		{
			len[index] = '\0';
			nb++;
			if(nb-1 >= 0)	
				spl_nb_3(len,vaule[nb-1]);
			index = -1;
		}	
	}

	return (nb + 1);
}



void	obj_set_trinagles(char **file, t_creat3d *create,
		t_object *obj_t, t_point *list)
{
	int len;
	int nbs[4][3];
	 len = spl_get_int(file[create->i],nbs);
	if (len > 4)
	{
		obj_t->triangle[++create->nb_f_c] = create_triangle(list[nbs[0][0]], list[nbs[1][0]],
				list[nbs[2][0]]);
		obj_set_uv(create->uv_list, nbs, &obj_t->triangle[create->nb_f_c], 0);

		obj_t->triangle[++create->nb_f_c] = create_triangle(list[nbs[3]
				[0]], list[nbs[0][0]], list[nbs[2][0]]);
		obj_set_uv(create->uv_list, nbs, &obj_t->triangle[create->nb_f_c], 1);
	}
	else
	{
		obj_t->triangle[++create->nb_f_c] = create_triangle(list[nbs[0][0]], list[nbs[1][0]], list[nbs[2][0]]);
		obj_set_uv(create->uv_list, nbs, &obj_t->triangle[create->nb_f_c], 0);
	}
}

void	obj_add_trinagles( t_object *obj_t, char **file, t_point *list)
{
	t_creat3d		create;

	create.i = -1;
	create.nb_f_c = -1;
	create.uv_list = obj_get_uv(file);
	while (file[++create.i] != NULL)
	{
		if (file[create.i] != NULL && file[create.i][0] == 'f')
		{
			obj_set_trinagles(file, &create, obj_t, list);
		}
	}
	obj_t->u_data.triangle = obj_t->triangle[0];
	obj_t->index = create.nb_f_c;
}

void	obj_square_set(t_triangle *triangle, int i, t_point *points)
{
	triangle[i] = create_triangle(points[0], points[1], points[2]);
	triangle[i + 1] = create_triangle(points[3], points[0], points[2]);
}

t_triangle	*obj_cobe_cube(t_point max, t_point min)
{
	t_triangle	*triangle;
	t_point		*p[3];

	triangle = ft_malloc(sizeof(t_triangle) * 12, "main");
	p[0] = obj_create_points(max,
			(t_point){{max.x, min.y, max.z}}, (t_point){{min.x, min.y, max.z}},
			(t_point){{min.x, max.y, max.z}});
	p[1] = obj_create_points(min,
			(t_point){{min.x, max.y, min.z}}, (t_point){{max.x, max.y, min.z}},
			(t_point){{max.x, min.y, min.z}});
	obj_square_set(triangle, 0, p[0]);
	obj_square_set(triangle, 2, p[1]);
	obj_square_set(triangle, 4, obj_create_points(min,
			(t_point){{max.x, min.y, min.z}}, (t_point){{max.x, min.y, max.z}},
			(t_point){{min.x, min.y, max.z}}));
	obj_square_set(triangle, 6, obj_create_points(max,
			(t_point){{min.x, max.y, max.z}}, (t_point){{min.x, max.y, min.z}},
			(t_point){{max.x, max.y, min.z}}));
	obj_square_set(triangle, 8, obj_create_points(min,
			(t_point){{min.x, max.y, min.z}}, (t_point){{min.x, max.y, max.z}},
			(t_point){{min.x, min.y, max.z}}));
	obj_square_set(triangle, 10, obj_create_points(max,
			(t_point){{max.x, min.y, max.z}}, (t_point){{max.x, min.y, min.z}},
			(t_point){{max.x, max.y, min.z}}));
	return (triangle);
}

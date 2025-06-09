/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:43:20 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/09 14:06:02 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix/matrix.h"
#include "minRT.h"

static int	init_scene(char *scene_file, t_minirt *rt, t_list_ **word_objects)
{
	int		status;
	t_point	luz_pt;

	status = 0;
	if (scene_file)
	{
		status = parser(scene_file, rt, word_objects);
		unified_camera_set_mode(&rt->camera, CAM_MODE_R);
		luz_pt = mat_x_tuple(create_point(0, 0, 0),
				mat_gener_trans(rt->luz.point.x, rt->luz.point.y, \
				rt->luz.point.z));
		rt->word = ft_node_start(*word_objects);
	}
	else
	{
		camera_init(&rt->camera, create_point(0, 1, -10),
			create_vector(0, 0, 1),
			100);
		start_word(rt);
	}
	return (status);
}

int	main(int ac, char **av, char **env)
{
	t_minirt	rt_struct;
	t_matrix	ok ;
	int			status;
	t_list_		*word_objects;
	t_point		luz;

	word_objects = NULL;
	status = 0;
	(void)ac;
	(void)av;
	(void)env;
	ft_start_alloc();
	status = init_scene(av[1], &rt_struct, &word_objects);
	ok = mat_gener_identity(4);
	rt_struct.point = create_point(0, 0, 0);
	ok = lig_view_transform(rt_struct.point,
			create_point(0, 0, 0), create_vector(0, 1, 0));
	rt_struct.rota_y = 0;
	rt_struct.rota_x = 0;
	rt_struct.needs_render = 4;
	rt_struct.menu = 0;
	canva_inicializ(&rt_struct, WALL_X, WALL_Y, c_new(0, 0, 0));
	return (status);
}

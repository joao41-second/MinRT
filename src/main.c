/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:43:20 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/18 14:11:19 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix/matrix.h"
#include "minRT.h"

static int	init_scene(char *scene_file, t_minirt *rt, t_list_ **word_objects)
{
	int			status;
	int			fd;

	status = 0;
	if (scene_file != NULL)
	{
		fd = open(scene_file, O_RDONLY);
		if (fd >= 0)
		{
			status = parser(scene_file, rt, word_objects);
			unified_camera_set_mode(&rt->camera, CAM_MODE_R);
			rt->word = ft_node_start(*word_objects);
			close(fd);
		}
		else
		{
			printf("Error: Cannot open scene file '%s'\n", scene_file);
			exit (-1);
		}
	}
	return (status);
}

int	main(int ac, char **av)
{
	t_minirt	rt_struct;
	int			status;
	t_list_		*word_objects;

	status = 0;
	word_objects = NULL;
	ft_memset(&rt_struct, 0, sizeof(t_minirt));
	ft_memset(&word_objects, 0, sizeof(t_list_));
	ft_start_alloc();
	if (ac >= 2)
		status = init_scene(av[1], &rt_struct, &word_objects);
	else
	{
		camera_init(&rt_struct.camera, create_point(0, 1, -10),
			create_vector(0, 0, 1),
			100);
		start_word(&rt_struct);
	}
	rt_struct.point = create_point(0, 0, 0);
	rt_struct.rota_y = 0;
	rt_struct.rota_x = 0;
	rt_struct.needs_render = 4;
	rt_struct.menu = 0;
	canva_inicializ(&rt_struct, WALL_X, WALL_Y, c_new(0, 0, 0));
	return (status);
}

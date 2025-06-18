/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:43:20 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/17 18:42:34 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix/matrix.h"
#include "minRT.h"
#include "objects/objects.h"

static int	init_scene(char *scene_file, t_minirt *rt)
{
	int		status;

	status = 0;
	rt->rota_y = 0;
	rt->rota_x = 0;
	rt->needs_render = 5;
	if (scene_file)
		status = parser(scene_file, rt);
	else
		start_word(rt);
	return (status);
}

int	main(int ac, char **av, char **env)
{
	t_minirt	rt_struct;
	t_matrix	ok ;
	int			status;

	rt_struct.word = NULL;
	status = 0;
	(void)ac;
	(void)av;
	(void)env;
	ft_start_alloc();
	rt_struct.canva.mlx = ft_add_memory(mlx_init(), NULL);
	rt_struct.luz_index = 0;
	status = init_scene(av[1], &rt_struct);
	rt_struct.word = ft_node_start(rt_struct.word);
	ok = mat_gener_identity(4);
	rt_struct.point = create_point(0, 0, 0);
	ok = lig_view_transform(rt_struct.point,
			create_point(0, 0, 0), create_vector(0, 1, 0));
	rt_struct.cam_m = cm_init(WALL_X, WALL_Y, M_PI / 3, ok);
	rt_struct.cam = cm_ray_for_pixel(rt_struct.cam_m,
			(double)WALL_X / 2, (double)WALL_Y / 2);
	rt_struct.cam_m.calculate = obj_mat_calulate_init();
	canva_inicializ(&rt_struct, WALL_X, WALL_Y, c_new(0, 0, 0));
	return (status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:43:20 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/19 11:16:36 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix/matrix.h"
#include "minRT.h"
#include "objects/objects.h"

static int	init_scene(char *scene_file, t_minirt *rt, int i)
{
	int			status;
	int			fd;

	fd = -1;
	if (i == 2)
		fd = open(scene_file, O_RDONLY);
	status = 0;
	rt->rota_y = 3;
	rt->rota_x = 0;
	rt->needs_render = 1;
	if (fd >= 0)
		status = parser(scene_file, rt);
	else
	{
		ft_free_all(); //TODO  not resolve leaks
		ft_printf("ERROR: not valid argomentes ");
		exit(-2);
	}

	return (status);
}

int	main(int ac, char **av)
{
	t_minirt	rt_struct;
	t_matrix	ok ;
	int			status;

	rt_struct.word = NULL;
	status = 0;
	ft_start_alloc();
	ft_memset(&rt_struct, 0, sizeof(t_minirt));
	
	rt_struct.canva.mlx = mlx_init();
	rt_struct.canva.mlx_wind = mlx_new_window(rt_struct.canva.mlx,
			WALL_X, WALL_Y, "new minRT");
	rt_struct.luz_index = 0;

	status = init_scene(av[1], &rt_struct, ac);

	rt_struct.word = ft_node_start(rt_struct.word);
	ok = mat_gener_identity(4);
	rt_struct.point = create_point(2, -1, 10);
	ok = lig_view_transform(rt_struct.point,
			create_point(0, 0, 0), create_vector(0, 1, 0));
	rt_struct.cam_m = cm_init(WALL_X, WALL_Y, M_PI / 3, ok);
	rt_struct.cam = cm_ray_for_pixel(rt_struct.cam_m,
			(double)WALL_X / 2, (double)WALL_Y / 2);
	rt_struct.cam_m.calculate = obj_mat_calulate_init();
	canva_inicializ(&rt_struct, WALL_X, WALL_Y, c_new(0, 0, 0));
	return (status);
}

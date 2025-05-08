/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:43:20 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/08 15:09:28 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

int	main(int ac, char **av, char **env)
{
	t_minirt	rt_struct;
	t_matrix	ok ;
	int			status;

	status = 0;
	(void)ac;
	(void)av;
	(void)env;
	ft_start_alloc();
	rt_struct.needs_render = 1;
	start_word(&rt_struct);
	ok = mat_gener_identity(4);
	rt_struct.point = create_point(0, 0, 5);
	ok = lig_view_transform(rt_struct.point,
			create_point(0, 1, 0), create_vector(0, 1, 0));
	ok = mat_multip(mat_gener_rota('x', 0.054 * (180 / M_PI)), ok);
	rt_struct.cam_m = cm_init(WALL_X, WALL_Y, M_PI / 2, ok);
	canva_inicializ(&rt_struct, WALL_X, WALL_Y, c_new(0, 0, 0));
	return (status);
}

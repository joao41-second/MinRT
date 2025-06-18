/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:42:15 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/18 09:43:21 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"
#include "../canvas_struct.h"
#include "menu.h"

void	draw_info(t_minirt *rt, int x, int y, char *text)
{
	mlx_string_put(rt->canva.mlx, rt->canva.mlx_wind, x, y,
		create_trgb(1, 255, 255, 2), text);
}

void	draw_group(t_minirt *rt, int *offset, const t_key_info keys[])
{
	int	i;

	i = 0;
	while (keys[i].description)
	{
		ft_line(rt, W_POS, *offset, (char *)keys[i].name);
		ft_line(rt, W_POS + 100, *offset, (char *)keys[i].description);
		*offset -= HEIGHT_POS;
		if (keys[i].separator)
		{
			ft_line(rt, W_POS, *offset, "----------------");
			*offset -= HEIGHT_POS;
		}
		i++;
	}
}

void	draw_menu_lines(t_minirt *rt, int *offset)
{
	ft_line(rt, W_POS, *offset, "Keyboard commands:");
	*offset -= HEIGHT_POS;
	draw_movement(rt, offset);
	draw_camera_arrows(rt, offset);
	draw_menu_toggle(rt, offset);
	draw_plane_ops(rt, offset);
	draw_views(rt, offset);
	draw_lighting(rt, offset);
	draw_quality_and_misc(rt, offset);
	ft_line(rt, W_POS, *offset, "Press 'TAB' to close menu");
}

void	ft_menu(t_minirt *rt)
{
	int	offset;

	offset = WALL_Y - HEIGHT_POS * 2;
	if (rt->menu)
		draw_menu_lines(rt, &offset);
	else
		ft_line(rt, W_POS, offset, "Press 'TAB' for menu");
}

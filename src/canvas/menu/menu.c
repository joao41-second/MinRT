/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:42:15 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/22 11:48:47 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../canvas_struct.h"
#include "menu.h"

void	ft_line(t_minirt *rt, int x, int y, char *text)
{
	mlx_string_put(rt->canva.mlx, rt->canva.mlx_wind, x, y, WHITE, text);
}

void	draw_info(t_minirt *rt, int x, int y, char *text)
{
	mlx_string_put(rt->canva.mlx, rt->canva.mlx_wind, x, y,
		create_trgb(1, 255, 255, 2), text);
}

void	draw_menu_lines(t_minirt *rt, int *offset)
{
	int	i;

	i = 0;
	ft_line(rt, W_POS, *offset, "Keyboard commands:");
	*offset -= HEIGHT_POS;
	while (g_key_info[i].description)
	{
		ft_line(rt, W_POS, *offset, (char *)g_key_info[i].name);
		ft_line(rt, W_POS + 100, *offset, (char *)g_key_info[i].description);
		*offset -= HEIGHT_POS;
		if (g_key_info[i].separator)
		{
			ft_line(rt, W_POS, *offset, "----------------");
			*offset -= HEIGHT_POS;
		}
		i++;
	}
	ft_line(rt, W_POS, *offset, "Press 'TAB' to close menu");
}

void	draw_camera_info(t_minirt *rt)
{
	char	*camera_mode;
	char	cam_info[128];
	char	luz_info[64];

	if (rt->camera.mode == CAM_MODE_R)
		camera_mode = "Camera Rei";
	else
		camera_mode = "Camera Joao";
	draw_info(rt, 10, 30, camera_mode);
	snprintf(cam_info, sizeof(cam_info), "cam cord: %f %f %f dir: %f %f %f",
		rt->camera.origin.x, rt->camera.origin.y, rt->camera.origin.z,
		rt->camera.direction.x, rt->camera.direction.y, rt->camera.direction.z);
	draw_info(rt, 10, 10, cam_info);
	snprintf(luz_info, sizeof(luz_info), "luz cord: %f %f %f",
		rt->luz.point.x, rt->luz.point.y, rt->luz.point.z);
	draw_info(rt, 20, 20, luz_info);
}

void	ft_menu(t_minirt *rt)
{
	int	offset;

	offset = WALL_Y - HEIGHT_POS * 2;
	if (rt->menu)
		draw_menu_lines(rt, &offset);
	else
		ft_line(rt, W_POS, offset, "Press 'TAB' for menu");
	draw_camera_info(rt);
}

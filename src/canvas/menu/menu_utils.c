/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:45:25 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/09 13:37:44 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"
#include "menu.h"

void	draw_plane_ops(t_minirt *rt, int *offset)
{
	static const t_key_info	keys[] = {
	{KEY_Z, "Z", "Rotate Z-axis", 0},
	{KEY_X, "X", "Rotate X-axis", 0},
	{KEY_Y, "Y", "Rotate Y-axis", 0},
	{KEY_R, "R", "Reset plane", 1},
	{0, NULL, NULL, 0}
	};

	draw_group(rt, offset, keys);
}

void	draw_views(t_minirt *rt, int *offset)
{
	static const t_key_info	keys[] = {
	{NUMPAD_1, "Numpad 1", "Front view", 0},
	{NUMPAD_4, "Numpad 4", "Right view", 0},
	{NUMPAD_7, "Numpad 7", "Top view", 0},
	{NUMPAD_2, "Numpad 2", "Back view", 0},
	{NUMPAD_5, "Numpad 5", "Left view", 0},
	{NUMPAD_8, "Numpad 8", "Bottom view", 1},
	{0, NULL, NULL, 0}
	};

	draw_group(rt, offset, keys);
}

void	draw_lighting(t_minirt *rt, int *offset)
{
	static const t_key_info	keys[] = {
	{KEY_O, "O", "Move light right", 0},
	{KEY_P, "P", "Move light left", 0},
	{KEY_I, "I", "Move light up", 0},
	{KEY_K, "K", "Move light down", 0},
	{KEY_L, "L", "Move light forward", 0},
	{KEY_J, "J", "Move light backward", 1},
	{KEY_SPACE, "Space", "Reset light", 1},
	{0, NULL, NULL, 0}
	};

	draw_group(rt, offset, keys);
}

void	draw_quality_and_misc(t_minirt *rt, int *offset)
{
	static const t_key_info	keys[] = {
	{KEY_M, "M", "Toggle mode", 0},
	{NUMKEY_9, "Num9", "Quality Down", 0},
	{NUMKEY_8, "Num8", "Quality Up", 1},
	{0, NULL, NULL, 0}
	};

	draw_group(rt, offset, keys);
}

void	ft_line(t_minirt *rt, int x, int y, char *text)
{
	mlx_string_put(rt->canva.mlx, rt->canva.mlx_wind, x, y, WHITE, text);
}

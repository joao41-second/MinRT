/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:45:25 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/09 13:49:23 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"
#include "menu.h"

void	draw_movement(t_minirt *rt, int *offset)
{
	static const t_key_info	keys[] = {
	{KEY_W, "W", "Move forward", 0},
	{KEY_S, "S", "Move backward", 1},
	{0, NULL, NULL, 0}
	};

	draw_group(rt, offset, keys);
}

void	draw_camera_arrows(t_minirt *rt, int *offset)
{
	static const t_key_info	keys[] = {
	{KEY_UP, "Up Arrow", "Move camera up", 0},
	{KEY_DOWN, "Down Arrow", "Move camera down", 0},
	{KEY_LEFT, "Left Arrow", "Move camera left", 0},
	{KEY_RIGHT, "Right Arrow", "Move camera right", 1},
	{0, NULL, NULL, 0}
	};

	draw_group(rt, offset, keys);
}

void	draw_menu_toggle(t_minirt *rt, int *offset)
{
	static const t_key_info	keys[] = {
	{KEY_ESC, "Esc", "Exit program", 0},
	{KEY_TAB, "Tab", "Toggle menu", 1},
	{0, NULL, NULL, 0}
	};

	draw_group(rt, offset, keys);
}

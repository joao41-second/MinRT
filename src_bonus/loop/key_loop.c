/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:32:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/15 13:14:07 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void	muve_cam(int key, t_minirt *rt_struct)
{
	if (key == KEY_W)
	{
		rt_struct->point.z -= 0.1;
	}
	if (key == KEY_S)
	{
		rt_struct->point.z += 0.1;
	}
	if (key == KEY_D)
	{
		rt_struct->point.x -= 0.1;
	}
	if (key == KEY_A)
	{
		rt_struct->point.x += 0.1;
	}
	if (key == KEY_UP)
	{
		rt_struct->point.y -= 0.1;
	}
	if (key == KEY_DOWN)
	{
		rt_struct->point.y += 0.1;
	}
}

void	rota_cam(int key, t_minirt *rt_struct)
{
	if (key == KEY_E)
	{
		rt_struct->rota_x += 0.1;
	}
	if (key == KEY_Q)
	{
		rt_struct->rota_x -= 0.1;
	}
	if (key == KEY_K)
	{
		rt_struct->rota_y += 0.1;
	}
	if (key == KEY_J)
	{
		rt_struct->rota_y -= 0.1;
	}
}

void	pixle_range(int key, t_minirt *rt_struct)
{
	if (key == NUMPAD_1)
	{
		rt_struct->needs_render++;
	}
	if (key == NUMPAD_2)
	{
		rt_struct->needs_render--;
	}
	if (rt_struct->needs_render <= 1)
		rt_struct->needs_render = 1;
}

void	key_loop(int key, t_minirt *rt_struct)
{
	(void)key;
	(void)rt_struct;
	if (key == KEY_ESC)
	{
		mlx_loop_end(rt_struct->canva.mlx);
	}
	muve_cam(key, rt_struct);
	rota_cam(key, rt_struct);
	pixle_range(key, rt_struct);
}

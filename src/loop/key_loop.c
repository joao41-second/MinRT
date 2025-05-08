/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:32:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/07 11:23:15 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void muve_cam(int key,t_minirt *rt_struct)
{
	if(key == KEY_W )
	{
		rt_struct->point.x += 0.1;
	}
	if(key == KEY_S )
	{
		rt_struct->point.x -= 0.1;
	}
	if(key == KEY_D )
	{
		rt_struct->point.y += 0.1;
	}
	if(key == KEY_A )
	{
		rt_struct->point.y -= 0.1;
	}
}

void	key_loop(int key, t_minirt *rt_struct)
{
	(void)key;
	(void)rt_struct;
	if (key == KEY_ESC)
	{
		mlx_loop_end(rt_struct->canva.mlx);
	}
	if (key == KEY_O)
	{
		rt_struct->luz.point.x+=0.1;
	}
	if (key == KEY_L)
	{
		rt_struct->luz.point.x-=0.1;
	}
	muve_cam(key,rt_struct);
}

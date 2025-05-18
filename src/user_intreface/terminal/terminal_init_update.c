/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_init_update.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:26:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/18 23:10:29 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../camera/keys.h"
#include "treminal.h"
#include "../../canvas/canvas.h"
#include "../../minRT.h"
#include <stdio.h>

void trem_init()
{
 // start list the camands
}

void term_change_color(t_user_in data)
{
	int x;
	int y;
	int color;
	
	x = 0;
	y = 0;
	while ( ++y < 10)
	{
		x = -1;
		while (++x < WALL_X)
		{
		//color = my_mlx_pixel_retunr(&data.canvas->canva,x , WALL_Y -y);
	//	my_mlx_pixel_put(&data.canvas->canva, 10,  10, 10);
		
		}	
	}
}

void termainl_update(int key,t_user_in data)
{
	static int stat = 0;
	
	
	if(stat == 0 && key == KEY_R)
	{
		stat = 1;
	}
	printf("ola %d\n",stat);
	if(stat == 1)
	{	
		 term_change_color(data);
	}

	if(key == KEY_SPACE)
	{
		stat = 0;
	}	
}

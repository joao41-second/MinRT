/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_init_update.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:26:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/21 13:28:04 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../camera/keys.h"
#include "../../canvas/canvas.h"
#include "../../minRT.h"
#include "termianl_stuct.h"

void trem_init(t_user_in *data)
{
	ft_add_node (cc_add_new_object(),&data->term );
	data->term = ft_node_start(data->term);
}

void term_change_color(t_user_in data,char *str,int nb_line, int neg_color)
{
	int x;
	int y;
	int color;
	
	x = 0;
	y = 0;
	while ( ++y < SIZE_LINE)
	{
		x = 0;
		while (++x < WALL_X - (20))
		{
			color = my_mlx_pixel_retunr(&data.canvas->canva,x , WALL_Y -(y + (SIZE_LINE *nb_line)) );
			my_mlx_pixel_put(&data.canvas->canva, x, WALL_Y -(y +(SIZE_LINE *nb_line)) , color - neg_color);	
		}	
	}

	mlx_string_put(data.canvas->mlx, data.canvas->mlx_wind,0, WALL_Y- (SIZE_LINE *nb_line ), create_trgb(1, 255, 255, 2), str);
}

int termainl_status(int key)
{
	static int stat;
	if(stat == 1 && (  key == KEY_ENTER))
	{
		stat = 0;
		return(0);
	}
	
	if(stat == 0 && (key == 't' || key == KEY_ENTER))
	{
		stat = 1;
		return(10);
	}
	return (stat);
}

void termainl_update(int key,t_user_in data)
{
	static char str[1056];
	static int buffer = 0;	
	int status;
	
	status = termainl_status(key);
	if(status == 10 && key != 't')
	{
		buffer = 0;
		str[0] = '\0';
		return;
	}
	if(status == 1)
	{
		if(key == KEY_TAB)
		{
			ter_tab_logic(data, str);
		}

		printf("key %d \n",key);
		if((key != 't' || key != KEY_ENTER  )&& key != 0)
		{
			str[buffer] = key;
			str[buffer+1] = '\0';
			buffer++;
		}

		 term_change_color(data,str,0,10);
		 
	}

}

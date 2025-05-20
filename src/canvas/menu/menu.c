/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:42:15 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/20 12:04:16 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../canvas_struct.h"
#include "menu.h"
#include <stdio.h>


void ft_menu(t_minirt *minirt)
{
    int i = 0;
    int y_offset = WALL_Y - HEIGHT_POS * 2;

    if (minirt->menu)
    {
        mlx_string_put(minirt->canva.mlx, minirt->canva.mlx_wind, W_POS, y_offset, WHITE, "Keyboard commands:");
        y_offset -= HEIGHT_POS;
        while (g_key_info[i].description)
        {
            mlx_string_put(minirt->canva.mlx, minirt->canva.mlx_wind, W_POS, y_offset, WHITE, g_key_info[i].name);
            mlx_string_put(minirt->canva.mlx, minirt->canva.mlx_wind, W_POS + 100, y_offset, WHITE, g_key_info[i].description);
            y_offset -= HEIGHT_POS;
            if (g_key_info[i].separator)
            {
                mlx_string_put(minirt->canva.mlx, minirt->canva.mlx_wind, W_POS, y_offset, WHITE, "----------------");
                y_offset -= HEIGHT_POS;
            }
            i++;
        }
        mlx_string_put(minirt->canva.mlx, minirt->canva.mlx_wind, W_POS, y_offset, WHITE, "Press 'TAB' to close menu");
    }
    else
        mlx_string_put(minirt->canva.mlx, minirt->canva.mlx_wind, W_POS, y_offset, WHITE, "Press 'TAB' for menu");
}

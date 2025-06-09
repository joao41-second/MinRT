/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:42:21 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/09 12:53:16 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

// # include "../../minRT.h"

# define W_POS 10
# define WIN_H 800
# define HEIGHT_POS 20
# define WHITE 0xFFFFFF
# define MENU_WIDTH 200
# define MENU_HEIGHT 300
# define MENU_X 10
# define MENU_Y 10

void	draw_group(t_minirt *rt, int *offset, const t_key_info keys[]);
void	draw_movement(t_minirt *rt, int *offset);
void	draw_camera_arrows(t_minirt *rt, int *offset);
void	draw_menu_toggle(t_minirt *rt, int *offset);
void	draw_plane_ops(t_minirt *rt, int *offset);
void	draw_views(t_minirt *rt, int *offset);
void	draw_lighting(t_minirt *rt, int *offset);
void	draw_quality_and_misc(t_minirt *rt, int *offset);
void	ft_line(t_minirt *rt, int x, int y, char *text);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:38:04 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/19 11:07:36 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AXIS_H
#define AXIS_H
#define AXIS_SIZE 400
#define AXIS_OFFSET 60
#define AXIS_THICKNESS 2
#define COLOR_X 0x00FF0000  
#define COLOR_Y 0x0000FF00  
#define COLOR_Z 0x000000FF 
#define CUBE_SIZE 0.3 
/**
 * Line drawing data structure
 */
typedef struct s_line {
	int x0, y0;
	int x1, y1;
	int dx, dy;
	int sx, sy;
	int err;
} t_line;


#endif
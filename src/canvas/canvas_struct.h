/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:51:11 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/18 08:53:29 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_STRUCT_H
# define CANVAS_STRUCT_H

typedef struct s_canva 
{
	void *mlx;
	void *mlx_wind;
	void *canva;

} t_canva;

typedef union s_color
{
	double red;
	double green;
	double blue;
	int color[3];
} t_color; 



#endif

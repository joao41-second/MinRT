/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:51:11 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/18 15:34:57 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_STRUCT_H
# define CANVAS_STRUCT_H

typedef struct s_img_
{
	int			width;
	int			height;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*img;
}				t_img_;

typedef struct s_canva
{
	void		*mlx;
	void		*mlx_wind;
	t_img_		canva;

}				t_canva;

typedef union s_color
{
	struct
	{
		double	red;
		double	green;
		double	blue;
	};
	int			color[3];
}				t_color;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:30:27 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/19 15:35:55 by rerodrig         ###   ########.fr       */
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
	double			color[3];
}				t_color;

#endif

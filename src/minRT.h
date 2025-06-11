/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minRT.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:27:02 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/04 14:29:15 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MINRT_H
#ifdef MINRT_H

# define TRUE 0
# define FALSE 1

# define WALL_X 1000
# define WALL_Y 750
# define WALL_Z 1.0
# define WALL_SIZE 1.0
# define CUBE 64

# include "../libft/ft_free/ft_free.h"
# include "../libft/ft_get_next_line/get_next_line_bonus.h"
# include "../libft/ft_libft/libft.h"
# include "../libft/ft_list/list.h"
# include "../libft/ft_list/lsit_struct.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/minilibx-linux/mlx.h"
# include "../libft/minilibx-linux/mlx_int.h"
# include "./Pattern/pattern.h"
# include "./camara_m/camara_m.h"
# include "./camera/camera.h"
# include "./canvas/canvas.h"
# include "./light/light.h"
# include "./loop/loop.h"
# include "./matrix/matrix.h"
# include "./miniRT_struct.h"
# include "./objects/objects.h"
# include "./ray/ray.h"
# include "./tuples/tuples.h"
# include <asm-generic/errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	start_word(t_minirt *rt_struct);
void	draw_navigator(t_minirt *rt_struct);
void	print_list_(t_list_ *list);
void	draw_cube_labels(t_minirt *rt_struct);

void	start_word_test(t_minirt *rt_struct, double ambinet, t_color color);

void	obj_open_stl_start(t_minirt *rt_struct, char *file_name,
			t_matrix matrix, t_mater mat);
#endif

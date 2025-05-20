/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minRT.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:27:02 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/20 13:00:33 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MINRT_H
#ifdef MINRT_H

# define TRUE 0
# define FALSE 1

# define WALL_X 1000
# define WALL_Y 900
# define WALL_Z 1.0
# define WALL_SIZE 1.0

# include "../libft/ft_free/ft_free.h"
# include "../libft/ft_get_next_line/get_next_line_bonus.h"
# include "../libft/ft_libft/libft.h"
# include "../libft/ft_list/list.h"
# include "../libft/ft_list/lsit_struct.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/minilibx-linux/mlx.h"
# include "../libft/minilibx-linux/mlx_int.h"

# include "./tuples/tuples.h"
# include "./matrix/matrix.h"
# include "./ray/ray.h"
# include "./camara_m/camara_m.h"
# include "./canvas/canvas.h"
# include "./light/light.h"
# include "./loop/loop.h"
# include "./miniRT_struct.h"
# include "./objects/objects.h"
# include "./camera/camera.h"
# include "./patterns/pattern.h"

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

void start_word(t_minirt  *rt_struct);
void draw_navigator(t_minirt *rt_struct);
void print_list_(t_list_ *list);
void draw_cube_labels(t_minirt *rt_struct);
void ft_menu(t_minirt *minirt);

void	start_word_test(t_minirt *rt_struct, double ambinet, t_color color);
#endif

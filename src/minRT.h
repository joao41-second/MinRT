/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minRT.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:27:02 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/18 10:44:05 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MINRT_H
#ifdef MINRT_H

# define TRUE 0
# define FALSE 1

# define WALL_X 400.0
# define WALL_Y 400.0
# define WALL_Z 10.0
# define WALL_SIZE 7.0
# define HALF WALL_Y/2 
# define PIXEL_SIZE WALL_SIZE/WALL_X;

# include "../libft/ft_libft/libft.h"
# include "../libft/ft_list/list.h"
# include "../libft/ft_free/ft_free.h"
# include "../libft/ft_get_next_line/get_next_line_bonus.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/ft_list/lsit_struct.h"
# include "../libft/minilibx-linux/mlx.h"
# include "../libft/minilibx-linux/mlx_int.h"


# include "./tuples/tuples.h"
# include "./canvas/canvas.h"
# include "./loop/loop.h"
# include "./miniRT_struct.h"
# include "./matrix/matrix.h"
# include "./objects/objects.h"
# include "./ray/ray.h"
# include "./light/light.h"
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


void start_word(t_minirt  *rt_struct);
#endif

/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minRT.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:27:02 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/26 11:11:49 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#define MINRT_H
#ifdef MINRT_H

# define TRUE 0
# define FALSE 1

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
# include "../libft/ft_free/ft_free.h"
# include "../libft/ft_get_next_line/get_next_line_bonus.h"
# include "../libft/ft_libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/minilibx-linux/mlx.h"
# include "../libft/minilibx-linux/mlx_int.h"
# include "./miniRT_struct.h"
# include "./loop/loop.h"
# include "./canvas/canvas.h"
# include "./tuples/tuples.h"
// # include "./utils/utils.h"
# include "./parser/parser.h"

#endif

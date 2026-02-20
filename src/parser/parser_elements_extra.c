/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_elements_utils_extra.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/18 11:52:45 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "../objects/objects.h"

void	parse_3d_object(char *line, t_minirt *data, int fd)
{
	double		val[6];
	t_mater		mat2;
	char		*filename;
	char		*start;

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], (t_range){-DBL_MAX, DBL_MAX}, fd))
		return ;
	while (*line && ft_isspace(*line))
		line++;
	start = line;
	while (*line && !ft_isspace(*line) && *line != '\n')
		line++;
	filename = ft_substr(start, 0, line - start);
	if (!filename)
		return ;
	mat2 = obj_material_init(c_new(0.8, 0.8, 0.8), c_new(-1, -1, -1),
			obj_init_values_material(0.1, 0.6, 0.3, 100), 0.0);
	printf("ok %s \n",filename);
	obj_open_stl_start(data, filename,
		mat_multip(mat_gener_scal(1, 1, 1),
			mat_gener_trans(val[0], val[1], val[2])), mat2);
}

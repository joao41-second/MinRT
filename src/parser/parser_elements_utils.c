/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_elements_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/18 11:51:19 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "../objects/objects.h"

t_mater	get_sphere_mat(double *val, char **line)
{
	t_color		colors[2];
	int			has_pattern;

	has_pattern = parse_pattern(line, &colors[0], &colors[1]);
	if (has_pattern)
		return (obj_material_init(colors[0], colors[1],
				obj_init_values_material(0.9, 0.9, 0.9, 100), val[7]));
	else
		return (obj_material_init(
				c_new(val[4] / 255.0, val[5] / 255.0, val[6] / 255.0),
				c_new(-1, -1, -1), obj_init_values_material(0.5, 0.5, 0.1, 1),
				val[7]));
}

t_mater	get_plane_mat(double *val, t_color col_a, t_color col_b, int has_pat)
{
	t_color	base_color;

	base_color = c_new(val[6] / 255.0, val[7] / 255.0, val[8] / 255.0);
	if (has_pat)
		return (obj_material_init(col_a, col_b,
				obj_init_values_material(0.9, 0.6, 0.3, 100), val[9]));
	else
		return (obj_material_init(base_color, c_new(-1, -1, -1),
				obj_init_values_material(0.9, 0.6, 0.3, 100), val[9]));
}

t_mater	get_cylinder_mat(double *val, t_color col_a, t_color col_b, int has_pat)
{
	t_color	base_color;

	base_color = c_new(val[8] / 255.0, val[9] / 255.0, val[10] / 255.0);
	if (has_pat)
		return (obj_material_init(col_a, col_b,
				obj_init_values_material(0.1, 0.6, 0.3, 100), val[11]));
	else
		return (obj_material_init(base_color, c_new(-1, -1, -1),
				obj_init_values_material(0.1, 0.6, 0.3, 100), val[11]));
}

char	*extract_pattern_type(char **line)
{
	char	*start;

	start = *line;
	while (**line && !ft_isspace(**line))
		(*line)++;
	return (ft_substr(start, 0, *line - start));
}

int	parse_checkered_colors(char **line, double *val, t_color *pattern_a,
	t_color *pattern_b)
{
	if (!parse_rgb(line, &val[0], (t_range){0.0, 255.0}, -1) ||
		!parse_rgb(line, &val[3], (t_range){0.0, 255.0}, -1))
		return (0);
	*pattern_a = c_new(val[0] / 255.0, val[1] / 255.0, val[2] / 255.0);
	*pattern_b = c_new(val[3] / 255.0, val[4] / 255.0, val[5] / 255.0);
	return (1);
}

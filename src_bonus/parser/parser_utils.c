/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/17 18:35:29 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

int	parse_value(char **line, double *v, t_range range, int fd)
{
	char	*end;

	*v = ft_atof(*line, &end);
	if (*line == end || *v < range.min || *v > range.max)
	{
		printf("ERROR: Out of range (%.2f - %.2f)\n", range.min, range.max);
		*line = ft_add_memory(get_next_line(fd), NULL);
		return (0);
	}
	*line = end;
	while (**line && ft_isspace(**line))
		(*line)++;
	return (1);
}

int	check_comma(char **line, int fd)
{
	if (**line != ',')
	{
		printf("ERROR: Expected ',' but found '%c'\n", **line);
		*line = ft_add_memory(get_next_line(fd), NULL);
		return (0);
	}
	(*line)++;
	return (1);
}

int	parse_rgb(char **line, double rgb[3], t_range range, int fd)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!parse_value(line, &rgb[i], range, fd) || rgb[i] != (int)rgb[i])
		{
			printf("ERROR: Invalid RGB value, '%s'\n", *line);
			*line = ft_add_memory(get_next_line(fd), NULL);
			return (0);
		}
		while (**line && ft_isspace(**line))
			(*line)++;
		if (i < 2 && !check_comma(line, fd))
			return (0);
		i++;
	}
	return (1);
}

int	parse_vector(char **ptr, double vec[3], t_range range, int fd)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!parse_value(ptr, &vec[i], range, fd))
			return (0);
		if (i < 2 && !check_comma(ptr, fd))
			return (0);
		i++;
	}
	return (1);
}

int	parse_pattern(char **line, t_color *pattern_a, t_color *pattern_b)
{
	double	val[6];
	char	*pattern_type;
	int		result;

	while (**line && ft_isspace(**line))
		(*line)++;
	if (!**line || **line == '\n')
		return (0);
	pattern_type = extract_pattern_type(line);
	result = 0;
	if (ft_strncmp(pattern_type, "checkered", 10) == 0)
		result = parse_checkered_colors(line, val, pattern_a, pattern_b);
	free(pattern_type);
	return (result);
}

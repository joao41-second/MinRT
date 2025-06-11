/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/22 22:53:22 by rerodrig         ###   ########.fr       */
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

// void	add_object(t_scene *scene, t_obj_type type, void *data)
// {
// 	t_object	*new_obj;
// 	t_object	*tmp;

// 	new_obj = ft_malloc(sizeof(t_object), NULL);
// 	ft_memset(new_obj, 0, sizeof(t_object));
// 	new_obj->type = type;
// 	new_obj->next = NULL;
// 	if (type == SPHERE)
// 		new_obj->u_data.sphere = *(t_sphere *)data;
// 	else if (type == PLANE)
// 		new_obj->u_data.plane = *(t_plane *)data;
// 	else if (type == CYLINDER)
// 		new_obj->u_data.cylinder = *(t_cylinder *)data;
// 	printf("Adding object: %p\n", new_obj);
// 	if (!scene->objects)
// 	{
// 		scene->objects = new_obj;
// 		return ;
// 	}
// 	tmp = scene->objects;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	tmp->next = new_obj;
// }

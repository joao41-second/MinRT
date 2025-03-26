/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/26 08:04:43 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void	parse_ambient(char *line, t_minirt *data, char *ptr, int fd)
{
	double intensity, r, g, b;
    char *end;

    // Skip leading whitespace
    while (*ptr && ft_isspace(*ptr))
        ptr++;

    // Parse intensity (0-1)
    intensity = ft_atof(ptr, &end);
    if (ptr == end || intensity < 0 || intensity > 1)
    {
        free(line);
        line = get_next_line(fd);
        return;
    }
    ptr = end;
    // Skip whitespace
    while (*ptr && ft_isspace(*ptr))
        ptr++;
    // Parse R,G,B values
    r = ft_atof(ptr, &end);
    if (ptr == end || r < 0 || r > 255)
    {
        free(line);
        line = get_next_line(fd);
        return;
    }
    ptr = end;
    // Ensure ',' separator
    if (*ptr++ != ',')
    {
        free(line);
        line = get_next_line(fd);
        return;
    }

    g = ft_atof(ptr, &end);
    if (ptr == end || g < 0 || g > 255)
    {
        free(line);
        line = get_next_line(fd);
        return;
    }
    ptr = end;
    // Ensure ',' separator
    if (*ptr++ != ',')
    {
        free(line);
        line = get_next_line(fd);
        return;
    }

    b = ft_atof(ptr, &end);
    if (ptr == end || b < 0 || b > 255)
    {
        free(line);
        line = get_next_line(fd);
        return;
    }
    ptr = end;
    // Skip trailing whitespace
    while (*ptr && ft_isspace(*ptr))
        ptr++;
    // Store ambient light values in the scene
    data->scene.world.ambient.red = r * intensity;
    data->scene.world.ambient.green = g * intensity;
    data->scene.world.ambient.blue = b * intensity;

    //! DEBUG
    printf("TOKEN AMBIENT -> Intensity: %.2f, Color: (%.0f, %.0f, %.0f)\n",
           intensity, r, g, b);
    // Ensure input ends cleanly
    if (*ptr != '\0' && *ptr != '\n')
    {
        free(line);
        line = get_next_line(fd);
        return;
    }
}

void	parse_camera(char *line, t_minirt *data)
{
}

void	parse_light(char *line, t_minirt *data)
{
}

void	tokenizer(const char *line, t_minirt data, t_token_map *token_map, t_token *type)
{
	int	i;
    
	i = 0;
	while (token_map[i].key != NULL)
	{
		if (strncmp(line, token_map[i].key, strlen(token_map[i].key)) == 0)
		{
            type = &token_map[i].value;
            line += ft_strlen(token_map[i].key);
            break;
        }
		i++;
	}
	
}

int	parser(const char *file, t_minirt *data)
{
	int			fd;
	char		*line;
	char		*ptr;
	t_token		type;
	t_token_map	token_map[COUNT] = {
	{"A", AMBIENT},
	{"C", CAMERA},
	{"L", LIGHT},
	{"sp", SPHERE},
	{"pl", PLANE},
	{"cy", CYLINDER},
	{"#", COMMENT},
	{"\n", NEWLINE},
	{NULL, ERROR}
	};
	char		*token_names[COUNT] = {
		"AMBIENT ",
		"CAMERA  ",
		"LIGHT   ",
		"SPHERE  ",
		"PLANE   ",
		"CYLINDER",
		"COMMENT ",
		"NEWLINE ",
		"ERROR   ",
	};

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error file");
		return (-1);
	}
	line = get_next_line(fd);
    ptr = ft_malloc(ft_strlen(line),"main");
	while (line)
	{
        tokenizer(line, *data, token_map, &type);
		if (type == AMBIENT)
			parse_ambient(line, data, ptr, fd);
		else if (type == CAMERA)
			parse_camera(line, data);
		else if (type == LIGHT)
			parse_light(line, data);
		else if (type == SPHERE)
			parse_sphere(line, data);
		else if (type == PLANE)
			parse_plane(line, data);
		else if (type == CYLINDER)
			parse_cylinder(line, data);
		else if (type == COMMENT || type == NEWLINE)
			printf("TOKEN %s -> %s\n", token_names[type], line);
		else
			printf("ERROR: UNKNOWN ELEMENT.\n");
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

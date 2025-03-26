/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/26 15:44:54 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minRT.h"
#include <float.h>

static int parse_value(char **line, double *v, double min, double max, int fd)
{
    char *end;
    
    *v = ft_atof(*line, &end);
    if (*line == end || *v < min || *v > max)
    {
        printf("ERROR: Number or out of range (%.2f - %.2f)\n", min, max);
        *line = ft_add_memory(get_next_line(fd), NULL);
        return (0);
    }
    *line = end;
    while (**line && ft_isspace(**line))
        (*line)++;
    
    return (1);
}

static int check_comma(char **line, int fd)
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

static int parse_rgb(char **line, double rgb[3],double min, double max, int fd)
{
    int i;

    i = 0;
    while (i < 3)
    {
        if (!parse_value(line, &rgb[i], min, max, fd) || rgb[i] != (int)rgb[i])
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


void parse_ambient(char *line, t_minirt *data, int fd)
{
    double intensity, rgb[3];

    while (*line && ft_isspace(*line))
        line++;
    if (!parse_value(&line, &intensity, 0.0, 1.0, fd) || !parse_rgb(&line, rgb, 0.0 ,255.0,  fd))
        return;
    data->scene.world.ambient.red = (rgb[0] / 255.0) * intensity;
    data->scene.world.ambient.green = (rgb[1] / 255.0) * intensity;
    data->scene.world.ambient.blue = (rgb[2] / 255.0) * intensity;

    printf("TOKEN AMBIENT -> Intensity: %.2f, Color: (%.0f, %.0f, %.0f)\n",
           intensity, rgb[0], rgb[1], rgb[2]);
}




static int parse_vector(char **ptr, double vec[3], double min, double max, int fd)
{
    int i = 0;
    while (i < 3)
    {
        if (!parse_value(ptr, &vec[i], min, max, fd))
            return (0);
        if (i < 2 && !check_comma(ptr, fd))
            return (0);
        i++;
    }
    return (1);
}



void parse_camera(char *line, t_minirt *data, int fd)
{
    double fov, pos[3], dir[3];

    while (*line && ft_isspace(*line))
        line++;
    if (!parse_vector(&line, pos, -DBL_MAX, DBL_MAX, fd) || !parse_vector(&line, dir, -1.0, 1.0, fd) || !parse_value(&line, &fov, 0.0, 180.0, fd))
        return;
    data->scene.world.camera.fov = fov;
    data->scene.world.camera.pos.x = pos[0];
    data->scene.world.camera.pos.y = pos[1];
    data->scene.world.camera.pos.z = pos[2];
    data->scene.world.camera.dir.x = dir[0];
    data->scene.world.camera.dir.y = dir[1];
    data->scene.world.camera.dir.z = dir[2];

    printf("TOKEN CAMERA -> FOV: %.2f, Position: (%.0f, %.0f, %.0f), Direction: (%.0f, %.0f, %.0f)\n",
           fov, pos[0], pos[1], pos[2], dir[0], dir[1], dir[2]);
}

void parse_light(char *line, t_minirt *data, int fd)
{
    double brightness, pos[3], rgb[3];

    while (*line && ft_isspace(*line))
        line++;
    if (!parse_vector(&line, pos, -DBL_MAX, DBL_MAX, fd) || !parse_value(&line, &brightness, 0.0, 1.0, fd) || !parse_rgb(&line, rgb, 0.0 ,255.0,  fd))
        return;
    data->scene.world.light.brightness = brightness;
    data->scene.world.light.pos.x = pos[0];
    data->scene.world.light.pos.y = pos[1];
    data->scene.world.light.pos.z = pos[2];
    data->scene.world.light.color.red = (rgb[0] / 255.0) * brightness;
    data->scene.world.light.color.green = (rgb[1] / 255.0) * brightness;
    data->scene.world.light.color.blue = (rgb[2] / 255.0) * brightness;

    printf("TOKEN LIGHT -> Brightness: %.2f, Position: (%.0f, %.0f, %.0f), Color: (%.0f, %.0f, %.0f)\n",
           brightness, pos[0], pos[1], pos[2], rgb[0], rgb[1], rgb[2]);
}


char *tokenizer(char *line, t_minirt data, t_token_map *token_map, t_token *type)
{
    int i = 0;

    while (token_map[i].key != NULL)
    {
        if (strncmp(line, token_map[i].key, strlen(token_map[i].key)) == 0)
        {
            *type = token_map[i].value;
            line += ft_strlen(token_map[i].key);
            break;
        }
        i++;
    }
    return line;
}

int parser(const char *file, t_minirt *data)
{
    int fd;
    char *line;
    t_token type;
    t_token_map token_map[COUNT] = {
        {"A", AMBIENT}, {"C", CAMERA}, {"L", LIGHT}, {"sp", SPHERE},
        {"pl", PLANE}, {"cy", CYLINDER}, {"#", COMMENT}, {"\n", NEWLINE},
        {NULL, ERROR}
    };
    char *token_names[COUNT] = {
        "AMBIENT ", "CAMERA  ", "LIGHT   ", "SPHERE  ",
        "PLANE   ", "CYLINDER", "COMMENT ", "NEWLINE ", "ERROR   "
    };

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("Error file");
        return (-1);
    }
    ft_pocket_new("parser");
    line = ft_add_memory(get_next_line(fd), NULL);
    while (line)
    {
        line = tokenizer(line, *data, token_map, &type);
        if (type == AMBIENT)
            parse_ambient(line, data, fd);
        else if (type == CAMERA)
            parse_camera(line, data, fd);
        else if (type == LIGHT)
            parse_light(line, data, fd);
        else if (type == SPHERE)
            parse_sphere(line, data);
        else if (type == PLANE)
            parse_plane(line, data);
        else if (type == CYLINDER)
            parse_cylinder(line, data);
        else if (type == COMMENT || type == NEWLINE)
            printf("\n");
        else
            printf("ERROR: UNKNOWN ELEMENT.\n");
        line = ft_add_memory(get_next_line(fd), NULL);
    }
    close(fd);
    return (0);
}
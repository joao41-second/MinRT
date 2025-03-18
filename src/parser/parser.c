/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/18 17:18:50 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minRT.h"

// int parse_ambient(char *line, t_scene *scene)
// {

//     (void)scene;
//     ft_printf("TOKEN AMBIENT         -> %s", line);
//     return 0;

// }
// int parse_camera(char *line, t_scene *scene)
// {

// }
// int parse_light(char *line, t_scene *scene)
// {

// }
// int parse_sphere(char *line, t_scene *scene)
// {

// }
// int parse_plane(char *line, t_scene *scene)
// {

// }
// int parse_cylinder(char *line, t_scene *scene)
// {

// }
// int parse_comment(char *line, t_scene *scene)
// {

// }

t_token tokenizer(const char *line, t_token_map *token_map)
{
    int i = 0;
    while (token_map[i].key != NULL)
    {
        if (strncmp(line, token_map[i].key, strlen(token_map[i].key)) == 0)
            return token_map[i].value;
        i++;
    }
    return ERROR;
}

int parser(const char *file, t_minirt *data)
{
    int         fd;
    char        *line;
    t_token     type;
    t_token_map token_map[COUNT] = {
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
    char *token_names[COUNT] = {
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
        return -1;
    }
    line = get_next_line(fd);
    while (line)
    {
        type = tokenizer(line, token_map);
        if (type == AMBIENT)
            parse_ambient(line, &data);
        else if (type == CAMERA)
            parse_camera(line, &data);
        else if (type == LIGHT)
            parse_light(line, &data);
        else if (type == SPHERE)
            parse_sphere(line, &data);
        else if (type == PLANE)
            parse_plane(line, &data);
        else if (type == CYLINDER)
            parse_cylinder(line, &data);
        else if (type == COMMENT || type == NEWLINE)
            printf("TOKEN %s -> %s\n", token_names[type], line);
        else
            printf("ERROR: UNKNOWN ELEMENT.\n");

        free(line);
        line = get_next_line(fd);
    }
    
    close(fd);

    return 0;

}






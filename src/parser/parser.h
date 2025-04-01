/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/27 03:35:15 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../miniRT_struct.h"
# include "./parser_struct.h"

# define DBL_MAX 1.7976931348623158e+308

int			parser(const char *file, t_minirt *data);
void		parse_ambient(char *line, t_minirt *data, int fd);
void		parse_camera(char *line, t_minirt *data, int fd);
void		parse_light(char *line, t_minirt *data, int fd);
void		parse_sphere(char *line, t_minirt *data, int fd);
void		parse_plane(char *line, t_minirt *data, int fd);
void		parse_cylinder(char *line, t_minirt *data, int fd);
void		parse_comment(char *line, t_minirt *data);
char		*tokenizer(char *line, const t_token_map *token_map, t_token *type);
int			parse_value(char **line, double *v, t_range range, int fd);
int			check_comma(char **line, int fd);
int			parse_rgb(char **line, double rgb[3], t_range range, int fd);
int			parse_vector(char **ptr, double vec[3], t_range range, int fd);
void		add_object(t_scene *scene, t_obj_type type, void *data);

#endif
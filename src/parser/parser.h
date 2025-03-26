/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/26 02:09:17 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../miniRT_struct.h"
# include "./parser_struct.h"

int			parser(const char *file, t_minirt *data);
void		parse_ambient(char *line, t_minirt *data, char *ptr, int fd);
void		parse_camera(char *line, t_minirt *data);
void		parse_light(char *line, t_minirt *data);
void		parse_sphere(char *line, t_minirt *data);
void		parse_plane(char *line, t_minirt *data);
void		parse_cylinder(char *line, t_minirt *data);
void		parse_comment(char *line, t_minirt *data);
void	tokenizer(const char *line, t_minirt data, t_token_map *token_map, t_token *type);

#endif
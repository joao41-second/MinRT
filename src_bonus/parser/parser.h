/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/18 11:49:45 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../miniRT_struct.h"
# include "./parser_struct.h"

# define DBL_MAX 1.7976931348623158e+308

typedef struct s_parser_ctx
{
	t_minirt	*data;
	int			fd;
	t_list_		**word_objects;
}	t_parser_ctx;

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

void		parse_3d_object(char *line, t_minirt *data, int fd);
int			parse_pattern(char **line, t_color *pattern_a, t_color *pattern_b);
t_mater		get_sphere_mat(double *val, char **line);
t_mater		get_plane_mat(double *val, t_color color_a, t_color color_b,
				int has_pattern);
t_mater		get_cylinder_mat(double *val, t_color color_a, t_color color_b,
				int has_pattern);
char		*extract_pattern_type(char **line);
int			parse_checkered_colors(char **line, double *val, t_color *pattern_a,
				t_color *pattern_b);

t_img_		*load_texture_image(char *filename, t_minirt *data);
char		*parse_file_path(char **line);
char		*parse_texture_file(char **line);
#endif
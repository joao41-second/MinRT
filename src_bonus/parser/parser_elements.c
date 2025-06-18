/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/18 08:48:29 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "../objects/objects.h"

void	parse_light(char *line, t_minirt *data, int fd)
{
	double			val[7];
	const t_range	range_pos = {-DBL_MAX, DBL_MAX};
	const t_range	range_bri = {0.0, 1.0};
	const t_range	range_rgb = {0.0, 255.0};

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], range_pos, fd) || \
		!parse_value(&line, &val[3], range_bri, fd) || \
		!parse_rgb(&line, &val[4], range_rgb, fd))
		return ;
	if (data->luz_index >= 100)
		return ;
	data->luz[data->luz_index].brightness = val[3];
	data->luz[data->luz_index].point.x = val[0];
	data->luz[data->luz_index].point.y = val[1];
	data->luz[data->luz_index].point.z = val[2];
	data->luz[data->luz_index].intenstiy.red = (val[4] / 255.0) * val[3];
	data->luz[data->luz_index].intenstiy.green = (val[5] / 255.0) * val[3];
	data->luz[data->luz_index].intenstiy.blue = (val[6] / 255.0) * val[3];
	data->luz[data->luz_index] = ligth_init(
			data->luz[data->luz_index].intenstiy, create_point(val[0], val[1], \
			val[2]));
	data->luz_index++;
}

void	parse_sphere(char *line, t_minirt *data, int fd)
{
	double		val[7];
	t_object	*obj_sphere;
	char		*texture_file;
	t_img_		*texture_img;
	t_sphere	sph;

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], (t_range){-DBL_MAX, DBL_MAX}, fd) ||
		!parse_value(&line, &val[3], (t_range){0.0, DBL_MAX}, fd) ||
		!parse_rgb(&line, &val[4], (t_range){0.0, 255.0}, fd))
		return ;
	texture_file = parse_texture_file(&line);
	texture_img = load_texture_image(texture_file, data);
	sph = sphere(create_point(0, 0, 0), val[3]);
	obj_sphere = create_object(&sph,
			OBJ_SPHERE, get_sphere_mat(val, &line), texture_img);
	ray_set_transform_obj(obj_sphere, mat_multip(
			mat_gener_scal(1, 1, 1), mat_gener_trans(val[0], val[1], val[2])));
	if (texture_file)
		free(texture_file);
	ft_add_node(obj_sphere, &data->word);
}

void	parse_plane(char *line, t_minirt *data, int fd)
{
	double		val[9];
	t_color		colors[2];
	t_object	*obj_plane;
	int			has_pattern;
	t_plane		plane;

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], (t_range){-DBL_MAX, DBL_MAX}, fd) ||
		!parse_vector(&line, &val[3], (t_range){-1.0, 1.0}, fd) ||
		!parse_rgb(&line, &val[6], (t_range){0.0, 255.0}, fd))
		return ;
	has_pattern = parse_pattern(&line, &colors[0], &colors[1]);
	plane = create_plane_parser(
			create_point(val[0], val[1], val[2]),
			normalize(create_vector(val[3], val[4], val[5])));
	obj_plane = create_object(&plane,
			OBJ_PLANE, get_plane_mat(val, colors[0], colors[1], has_pattern),
			NULL);
	ray_set_transform_obj(obj_plane, mat_multip(mat_gener_scal(1, 1, 1),
			mat_gener_trans(0, 0, 0)));
	ft_add_node(obj_plane, &data->word);
}

void	parse_cylinder(char *line, t_minirt *data, int fd)
{
	double		val[11];
	t_color		colors[2];
	t_object	*obj_cylinder;
	int			has_pattern;
	t_cylinder	cyl;

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], (t_range){-DBL_MAX, DBL_MAX}, fd) ||
		!parse_vector(&line, &val[3], (t_range){-1.0, 1.0}, fd) ||
		!parse_value(&line, &val[6], (t_range){0.0, DBL_MAX}, fd) ||
		!parse_value(&line, &val[7], (t_range){0.0, DBL_MAX}, fd) ||
		!parse_rgb(&line, &val[8], (t_range){0.0, 255.0}, fd))
		return ;
	has_pattern = parse_pattern(&line, &colors[0], &colors[1]);
	cyl = create_cylinder(
			create_point(val[0], val[1], val[2]),
			create_vector(val[3], val[4], val[5]), val[6], val[7]);
	obj_cylinder = create_object(&cyl,
			OBJ_CYLINDER, get_cylinder_mat(val, colors[0], has_pattern), NULL);
	ray_set_transform_obj(obj_cylinder, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_cylinder, &data->word);
}

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
	obj_open_stl_start(data, filename,
		mat_multip(mat_gener_scal(1, 1, 1),
			mat_gener_trans(val[0], val[1], val[2])), mat2);
}

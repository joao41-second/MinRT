/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/18 14:10:02 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "../objects/objects.h"

void	parse_camera(char *line, t_minirt *data, int fd)
{
	double			val[7];
	const t_range	range_pos = {-DBL_MAX, DBL_MAX};
	const t_range	range_dir = {-1.0, 1.0};
	const t_range	range_fov = {0.0, 180.0};

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], range_pos, fd) || \
		!parse_vector(&line, &val[3], range_dir, fd) || \
		!parse_value(&line, &val[6], range_fov, fd))
		return ;
	camera_init(&data->camera, create_point(val[0], val[1], val[2]),
		create_vector(val[3], val[4], val[5]), val[6]);
}

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
	data->luz.brightness = val[3];
	data->luz.point.x = val[0];
	data->luz.point.y = val[1];
	data->luz.point.z = val[2];
	data->luz.intenstiy.red = (val[4] / 255.0) * val[3];
	data->luz.intenstiy.green = (val[5] / 255.0) * val[3];
	data->luz.intenstiy.blue = (val[6] / 255.0) * val[3];
}

void	parse_sphere(char *line, int fd, t_list_ **word_objects)
{
	double			val[7];
	t_mater			mat1;
	t_sphere		sph;
	t_object		*obj_sphere;

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], (t_range){-DBL_MAX, DBL_MAX}, fd) || \
		!parse_value(&line, &val[3], (t_range){0.0, DBL_MAX}, fd) || \
		!parse_rgb(&line, &val[4], (t_range){0.0, 255.0}, fd))
		return ;
	sph = sphere(create_point(0, 0, 0), val[3]);
	mat1 = obj_material_init(c_new(val[4] / 255.0, val[5] / 255.0, \
		val[6] / 255.0), obj_init_values_material(0.1, 0.6, 0.3, 100));
	obj_sphere = create_object(&sph, OBJ_SPHERE, mat1);
	ray_set_transform_obj(obj_sphere, mat_multip(mat_gener_scal(1, 1, 1), \
		mat_gener_trans(val[0], val[1], val[2])));
	ft_add_node(obj_sphere, word_objects);
}

void	parse_plane(char *line, int fd, t_list_ **word_objects)
{
	double		val[9];
	t_plane		plane;
	t_object	*obj_plane;
	t_mater		mat2;

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], (t_range){-DBL_MAX, DBL_MAX}, fd) ||
		!parse_vector(&line, &val[3], (t_range){-1.0, 1.0}, fd) ||
		!parse_rgb(&line, &val[6], (t_range){0.0, 255.0}, fd))
		return ;
	mat2 = obj_material_init(
			c_new(val[6] / 255.0, val[7] / 255.0, val[8] / 255.0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));
	plane = create_plane_parser(
			create_point(val[0], val[1], val[2]),
			normalize(create_vector(val[3], val[4], val[5])));
	obj_plane = create_object(&plane, OBJ_PLANE, mat2);
	plane.normal = create_vector(val[3], val[4], val[5]);
	ray_set_transform_obj(obj_plane, mat_multip(mat_gener_scal(1, 1, 1),
			mat_gener_trans(0, 0, 0)));
	ft_add_node(obj_plane, word_objects);
}

void	parse_cylinder(char *line, int fd, t_list_ **objects)
{
	double		val[11];
	t_cylinder	cylinder;
	t_object	*obj_cylinder;
	t_mater		mat1;

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], (t_range){-DBL_MAX, DBL_MAX}, fd) ||
		!parse_vector(&line, &val[3], (t_range){-1.0, 1.0}, fd) ||
		!parse_value(&line, &val[6], (t_range){0.0, DBL_MAX}, fd) ||
		!parse_value(&line, &val[7], (t_range){0.0, DBL_MAX}, fd) ||
		!parse_rgb(&line, &val[8], (t_range){0.0, 255.0}, fd))
		return ;
	cylinder = create_cylinder(create_point(val[0], val[1], val[2]),
			create_vector(val[3], val[4], val[5]), val[6], val[7]);
	mat1 = obj_material_init(
			c_new(val[8] / 255.0, val[9] / 255.0, val[10] / 255.0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));
	obj_cylinder = create_object(&cylinder, OBJ_CYLINDER, mat1);
	cylinder.center = create_vector(val[0], val[1], val[2]);
	ray_set_transform_obj(obj_cylinder, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_cylinder, objects);
}

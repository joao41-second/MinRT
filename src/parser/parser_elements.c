/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/25 14:51:04 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "../objects/objects.h"

// Group fov, pos, and dir
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
	// data->camera.fov = val[6];
	// data->camera.origin.x = val[0];
	// data->camera.origin.y = val[1];
	// data->camera.origin.z = val[2];
	// data->camera.direction.x = val[3];
	// data->camera.direction.y = val[4];
	// data->camera.direction.z = val[5];
	camera_init(&data->camera, create_point(val[0],val[1], val[2]),
		create_vector(val[3], val[4], val[5]), val[6]);
	// unified_camera_set_mode(&rt_struct.camera, CAM_MODE_J);
	printf("TOKEN CAMERA -> FOV: %.2f, Position: (%.0f, %.0f, %.0f), \
		Direction: (%.0f, %.0f, %.0f)\n",
		val[6], val[0], val[1], val[2], val[3], val[4], val[5]);
}

// Group brightness, pos, and rgb
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
	printf("TOKEN LIGHT -> Brightness: %.2f, Position: (%.0f, %.0f, %.0f), \
		Color: (%.0f, %.0f, %.0f)\n",
		val[3], val[0], val[1], val[2], val[4], val[5], val[6]);
}

// Group diameter, pos, and rgb
void	parse_sphere(char *line, t_minirt *data, int fd, t_list_ **word_objects)
{
	double			val[7];
	t_mater		mat1;
	t_sphere		sph;
	t_object	*obj_sphere;

	const t_range	range_pos = {-DBL_MAX, DBL_MAX};
	const t_range	range_dia = {0.0, DBL_MAX};
	const t_range	range_rgb = {0.0, 255.0};
	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], range_pos, fd) || \
		!parse_value(&line, &val[3], range_dia, fd) || \
		!parse_rgb(&line, &val[4], range_rgb, fd))
		return ;
	sph =  sphere(create_point(0,0,0), val[3]);
	mat1 = obj_material_init(c_new(val[4] / 255.0, val[5] / 255.0, val[6] / 255.0),
		obj_init_values_material(0.1, 0.6, 0.3, 100));
	// sphere.diameter = val[3];
	// (t_point){val[0], val[1], val[2]};
	// sphere.color = (t_color){val[4] / 255.0, val[5] / 255.0, val[6] / 255.0};
	obj_sphere = create_object(&sph, OBJ_SPHERE, mat1);
	// add_object(&data->scene, OBJ_SPHERE, &sphere);
	ray_set_transform_obj(obj_sphere, mat_multip(mat_gener_scal(1, 1, 1), mat_gener_trans(val[0], val[1], val[2])));

	ft_add_node(obj_sphere, word_objects);
	printf("TOKEN SPHERE -> Center: (%.1f, %.1f, %.1f), \
		Diameter: %.1f, Color: (%.0f, %.0f, %.0f)\n",
		val[0], val[1], val[2], val[3], val[4], val[5], val[6]);
}

// Group  pos, normal, rgb
void	parse_plane(char *line, t_minirt *data, int fd, t_list_ **word_objects)
{
	double			val[9];
	t_plane			plane;
	t_object		*obj_plane;
	t_mater			mat2;
	const t_range	range_pos = {-DBL_MAX, DBL_MAX};
	const t_range	range_nor = {-1.0, 1.0};
	const t_range	range_rgb = {0.0, 255.0};

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], range_pos, fd) || \
		!parse_vector(&line, &val[3], range_nor, fd) || \
		!parse_rgb(&line, &val[6], range_rgb, fd))
		return ;
	mat2 = obj_material_init(c_new(val[6] / 255.0, val[7] / 255.0, val[8] / 255.0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));
	plane = create_plane(create_point(val[0], 0, 0), create_point(val[1], 0, 0),
			create_point(0, 0, val[2]));
	obj_plane = create_object(&plane, OBJ_PLANE, mat2);
	// plane.point = (t_vector){val[0], val[1], val[2]};
	plane.normal = (t_vector){val[3], val[4], val[5]};
	// plane.color = (t_color){val[6] / 255.0, val[7] / 255.0, val[8] / 255.0};
	// add_object(&data->scene, OBJ_PLANE, &plane);
	ft_add_node(obj_plane, word_objects);
	printf("TOKEN PLANE -> Point: (%.1f, %.1f, %.1f), \
		Normal: (%.1f, %.1f, %.1f), Color: (%.0f, %.0f, %.0f)\n",
		val[0], val[1], val[2], val[3], val[4], val[5],
		val[6], val[7], val[8]);
}

//Group pos, axis, diameter, height, and rgb
void	parse_cylinder(char *line, t_minirt *data, int fd, t_list_ **word_objects)
{
	double			val[11];
	t_cylinder		cylinder;
	t_object	*obj_cylinder;
	t_mater		mat1;
	const t_range	ranges[4] = {{-DBL_MAX, DBL_MAX}, {-1.0, 1.0},
	{0.0, DBL_MAX}, {0.0, 255.0}
	};

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], ranges[0], fd) || \
		!parse_vector(&line, &val[3], ranges[1], fd) || \
		!parse_value(&line, &val[6], ranges[2], fd) || \
		!parse_value(&line, &val[7], ranges[2], fd) || \
		!parse_rgb(&line, &val[8], ranges[3], fd))
		return ;
	cylinder = create_cylinder((t_point){val[0], val[1], val[2]},
			(t_vector){val[3], val[4], val[5]}, val[6], val[7]);
	mat1 = obj_material_init(c_new(val[8] / 255.0, val[9] / 255.0, val[10] / 255.0),
			obj_init_values_material(0.1, 0.6, 0.3, 100));
	obj_cylinder = create_object(&cylinder, OBJ_CYLINDER, mat1);

	cylinder.center = (t_vector){val[0], val[1], val[2]};
	// cylinder.axis = (t_vector){val[3], val[4], val[5]};
	// cylinder.diameter = val[6];
	// cylinder.height = val[7];
	// cylinder.color = (t_color){val[8] / 255.0, val[9] / 255.0, val[10] / 255.0};
	// add_object(&data->scene, OBJ_CYLINDER, &cylinder);
	
	ray_set_transform_obj(obj_cylinder, mat_gener_scal(1, 1, 1));
	ft_add_node(obj_cylinder, word_objects);
	printf("TOKEN CYLINDER -> Center: (%.1f, %.1f, %.1f), \
		Axis: (%.1f, %.1f, %.1f), Diameter: %.1f, Height: %.1f, \
		Color: (%.0f, %.0f, %.0f)\n", val[0], val[1], val[2],
		val[3], val[4], val[5], val[6], val[7],
		val[8], val[9], val[10]);
}

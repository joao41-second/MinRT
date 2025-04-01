/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/27 03:15:38 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

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
	data->scene.world.camera.fov = val[6];
	data->scene.world.camera.pos.x = val[0];
	data->scene.world.camera.pos.y = val[1];
	data->scene.world.camera.pos.z = val[2];
	data->scene.world.camera.dir.x = val[3];
	data->scene.world.camera.dir.y = val[4];
	data->scene.world.camera.dir.z = val[5];
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
	data->scene.world.light.brightness = val[3];
	data->scene.world.light.pos.x = val[0];
	data->scene.world.light.pos.y = val[1];
	data->scene.world.light.pos.z = val[2];
	data->scene.world.light.color.red = (val[4] / 255.0) * val[3];
	data->scene.world.light.color.green = (val[5] / 255.0) * val[3];
	data->scene.world.light.color.blue = (val[6] / 255.0) * val[3];
	printf("TOKEN LIGHT -> Brightness: %.2f, Position: (%.0f, %.0f, %.0f), \
		Color: (%.0f, %.0f, %.0f)\n",
		val[3], val[0], val[1], val[2], val[4], val[5], val[6]);
}

// Group diameter, pos, and rgb
void	parse_sphere(char *line, t_minirt *data, int fd)
{
	double			val[7];
	t_sphere		sphere;
	const t_range	range_pos = {-DBL_MAX, DBL_MAX};
	const t_range	range_dia = {0.0, DBL_MAX};
	const t_range	range_rgb = {0.0, 255.0};

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], range_pos, fd) || \
		!parse_value(&line, &val[3], range_dia, fd) || \
		!parse_rgb(&line, &val[4], range_rgb, fd))
		return ;
	sphere.center = (t_vector){val[0], val[1], val[2]};
	sphere.diameter = val[3];
	sphere.color = (t_color){val[4] / 255.0, val[5] / 255.0, val[6] / 255.0};
	add_object(&data->scene, OBJ_SPHERE, &sphere);
	printf("TOKEN SPHERE -> Center: (%.1f, %.1f, %.1f), \
		Diameter: %.1f, Color: (%.0f, %.0f, %.0f)\n",
		val[0], val[1], val[2], val[3], val[4], val[5], val[6]);
}

// Group  pos, normal, rgb
void	parse_plane(char *line, t_minirt *data, int fd)
{
	double			val[9];
	t_plane			plane;
	const t_range	range_pos = {-DBL_MAX, DBL_MAX};
	const t_range	range_nor = {-1.0, 1.0};
	const t_range	range_rgb = {0.0, 255.0};

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_vector(&line, &val[0], range_pos, fd) || \
		!parse_vector(&line, &val[3], range_nor, fd) || \
		!parse_rgb(&line, &val[6], range_rgb, fd))
		return ;
	plane.point = (t_vector){val[0], val[1], val[2]};
	plane.normal = (t_vector){val[3], val[4], val[5]};
	plane.color = (t_color){val[6] / 255.0, val[7] / 255.0, val[8] / 255.0};
	add_object(&data->scene, OBJ_PLANE, &plane);
	printf("TOKEN PLANE -> Point: (%.1f, %.1f, %.1f), \
		Normal: (%.1f, %.1f, %.1f), Color: (%.0f, %.0f, %.0f)\n",
		val[0], val[1], val[2], val[3], val[4], val[5],
		val[6], val[7], val[8]);
}

//Group pos, axis, diameter, height, and rgb
void	parse_cylinder(char *line, t_minirt *data, int fd)
{
	double			val[11];
	t_cylinder		cylinder;
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
	cylinder.center = (t_vector){val[0], val[1], val[2]};
	cylinder.axis = (t_vector){val[3], val[4], val[5]};
	cylinder.diameter = val[6];
	cylinder.height = val[7];
	cylinder.color = (t_color){val[8] / 255.0, val[9] / 255.0, val[10] / 255.0};
	add_object(&data->scene, OBJ_CYLINDER, &cylinder);
	printf("TOKEN CYLINDER -> Center: (%.1f, %.1f, %.1f), \
		Axis: (%.1f, %.1f, %.1f), Diameter: %.1f, Height: %.1f, \
		Color: (%.0f, %.0f, %.0f)\n", val[0], val[1], val[2],
		val[3], val[4], val[5], val[6], val[7],
		val[8], val[9], val[10]);
}

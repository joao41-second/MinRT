/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/18 14:47:35 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void	parse_ambient(char *line, t_minirt *data, int fd)
{
	double			val[4];
	const t_range	range_int = {0.0, 1.0};
	const t_range	range_rgb = {0.0, 255.0};

	while (*line && ft_isspace(*line))
		line++;
	if (!parse_value(&line, &val[0], range_int, fd) || \
		!parse_rgb(&line, &val[1], range_rgb, fd))
		return ;
	data->scene.world.ambient.red = (val[1] / 255.0) * val[0];
	data->scene.world.ambient.green = (val[2] / 255.0) * val[0];
	data->scene.world.ambient.blue = (val[3] / 255.0) * val[0];
}

char	*tokenizer(char *line, const t_token_map *token_map, t_token *type)
{
	int	i;

	i = 0;
	while (token_map[i].key != NULL)
	{
		if (strncmp(line, token_map[i].key, strlen(token_map[i].key)) == 0)
		{
			*type = token_map[i].value;
			line += ft_strlen(token_map[i].key);
			break ;
		}
		i++;
	}
	return (line);
}

static void	parse_handler(t_token type, char *line, t_parser_ctx *ctx)
{
	if (type == AMBIENT)
		parse_ambient(line, ctx->data, ctx->fd);
	else if (type == CAMERA)
		parse_camera(line, ctx->data, ctx->fd);
	else if (type == LIGHT)
		parse_light(line, ctx->data, ctx->fd);
	else if (type == SPHERE)
		parse_sphere(line, ctx->fd, ctx->word_objects);
	else if (type == PLANE)
		parse_plane(line, ctx->fd, ctx->word_objects);
	else if (type == CYLINDER)
		parse_cylinder(line, ctx->fd, ctx->word_objects);
	else if (type == COMMENT || type == NEWLINE)
		;
	else
		ft_printf("ERROR: UNKNOWN ELEMENT.\n");
}

int	parser(const char *file, t_minirt *data, t_list_ **word_objects)
{
	char				*line;
	t_token				type;
	t_parser_ctx		ctx;
	const int			fd = open(file, O_RDONLY);
	const t_token_map	token_map[COUNT] = {
	{"A", AMBIENT}, {"C", CAMERA}, {"L", LIGHT},
	{"sp", SPHERE}, {"pl", PLANE}, {"cy", CYLINDER},
	{"#", COMMENT}, {"\n", NEWLINE}, {NULL, ERROR},
	};

	type = ERROR;
	if (fd == -1)
		return (perror("Error file"), -1);
	ctx.data = data;
	ctx.fd = fd;
	ctx.word_objects = word_objects;
	line = ft_add_memory(get_next_line(fd), NULL);
	while (line)
	{
		line = tokenizer(line, token_map, &type);
		parse_handler(type, line, &ctx);
		line = ft_add_memory(get_next_line(fd), NULL);
	}
	close(fd);
	return (0);
}

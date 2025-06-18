/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/18 08:47:24 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "../objects/objects.h"

t_img_	*load_texture_image(char *filename, t_minirt *data)
{
	t_img_	*img;

	if (!filename)
		return (NULL);
	img = malloc(sizeof(t_img_));
	if (!img)
		return (NULL);
	img->img = mlx_xpm_file_to_image(data->canva.mlx, filename, &img->width,
			&img->height);
	if (!img->img)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

char	*parse_file_path(char **line)
{
	char	*start;

	while (**line && ft_isspace(**line))
		(*line)++;
	if (!**line || **line == '\n')
		return (NULL);
	start = *line;
	while (**line && !ft_isspace(**line) && **line != '\n')
		(*line)++;
	return (ft_substr(start, 0, *line - start));
}

char	*parse_texture_file(char **line)
{
	char	*start;
	char	*texture_type;

	while (**line && ft_isspace(**line))
		(*line)++;
	if (!**line || **line == '\n')
		return (NULL);
	start = *line;
	while (**line && !ft_isspace(**line))
		(*line)++;
	texture_type = ft_substr(start, 0, *line - start);
	if (ft_strncmp(texture_type, "bumpmap", 7) == 0)
	{
		free(texture_type);
		return (parse_file_path(line));
	}
	free(texture_type);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_open_uv_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:41:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 12:27:53 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"
#include <stdio.h>
#include <strings.h>

t_uv	*obj_get_uv(char **file)
{
	int		i;
	int		i_;
	int		nb;
	int		nb_;
	t_uv	*points;
	char	**split;

	i = -1;
	nb = 0;
	ft_pocket_set("main");
	while (file[++i] != NULL)
		if (file[i][0] == 'v' && file[i][1] == 't' && file[i][2] == ' ')
			nb++;
	points = ft_malloc((nb + 1) * sizeof(t_uv), NULL);
	i = -1;
	nb_ = nb;
	nb = -1;
	while (file[++i] != NULL)
	{
		if (file[i][0] == 'v' && file[i][1] == 't' && file[i][2] == ' ')
		{
			i_ = -1;
			split = ft_split(file[i], ' ');
			while (split[++i_] != NULL)
				;
			if (i_ >= 2)
			{
				points[++nb].u = ft_atof(split[1], NULL);
				points[nb].v = ft_atof(split[2], NULL);
				points[nb].index = -1;
			}
		}
	}
	nb = -1;
	return (ft_pocket_set("main"), points);
}

void	obj_set_uv(t_uv *uvs, char ***line, t_triangle *tri, int fl, int index)
{
	tri->uv2.index = index;
	tri->uv3.index = index;
	tri->uv1.index = index;
	if (fl == 0)
	{
		tri->uv1 = uvs[ft_atoi(line[0][1]) - 1];
		tri->uv2 = uvs[ft_atoi(line[1][1]) - 1];
		tri->uv3 = uvs[ft_atoi(line[2][1]) - 1];
	}
	if (fl == 1)
	{
		tri->uv1 = uvs[ft_atoi(line[3][1]) - 1];
		tri->uv2 = uvs[ft_atoi(line[0][1]) - 1];
		tri->uv3 = uvs[ft_atoi(line[2][1]) - 1];
	}
}

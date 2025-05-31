/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_open_uv_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:41:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/31 12:24:16 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minRT.h"
#include <stdio.h>


t_uv *obj_get_uv(char **file)
{
	int i;
	int nb;
	t_uv *points;
	char **split;

	i=-1;
	nb = 0;
	ft_pocket_set("main");
	while (file[++i] != NULL)
		if(file[i][0] == 'v' && file[i][1] == 't')
			nb++;	
	points = ft_malloc(nb*2*sizeof(float), NULL);	
	i=-1;
	nb = -1;
	ft_pocket_set("add_obj");
	while (file[++i] != NULL)
	{
		if(file[i][0] == 'v' && file[i][1] == 't')
		{
			split = ft_split(file[i], ' ');
			points[++nb].u = ft_atof(split[1], NULL);
			points[nb].v = ft_atof(split[2], NULL);	
		}	
	}
	return ( ft_pocket_set("main"),points);
}




void obj_set_uv(t_uv *uvs,char ***line ,t_triangle *tri,int fl)
{
	if(fl == 0)
	{
	tri->uv1 = uvs[ft_atol(line[0][2])];
	tri->uv2 = uvs[ft_atol(line[1][2])];
	tri->uv3 = uvs[ft_atol(line[2][2])];
	}
	if(fl == 1)
	{
	tri->uv1 = uvs[ft_atol(line[3][2])];
	tri->uv2 = uvs[ft_atol(line[0][2])];
	tri->uv3 = uvs[ft_atol(line[2][2])];
	}
}




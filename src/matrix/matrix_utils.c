/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:11:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/19 10:54:23 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"


void mat_get_file(char *file,t_matrix mat)
{
	char *line;
	int fd;
	int *list;
	char **nb_char;
	int i;
	int y;

	fd = open(file,O_RDONLY);
	if(fd < 0)
		return;
	ft_pocket_new("get");
	line = ft_add_memory(get_next_line(fd), NULL);

	y = -1;
	while (line != NULL && ++y < mat.size) 
	{
		i = -1;
		nb_char = ft_split(line, '|');
		while (nb_char[++i] != NULL && i < mat.size)
		 mat.matr[y][i] = ft_atoi(nb_char[i]);
		line = ft_add_memory(get_next_line(fd), NULL);
	}
	close(fd);
	ft_free_all_pocket("get");
}


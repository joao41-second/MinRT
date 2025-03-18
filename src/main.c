/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:19:42 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/18 15:56:28 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"
#include "miniRT_struct.h"

int	main(int ac, char **av, char **env)
{
	t_minirt	rt_struct;

	(void)ac;
	(void)av;
	ft_start_alloc();
	canva_inicializ(&rt_struct, 200, 100, c_new(0, 0, 0));
	return (0);
}

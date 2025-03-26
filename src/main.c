/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:27:43 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/26 01:30:41 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

int	main(int ac, char **av, char **env)
{
	t_minirt	rt_struct;
	int			status;

	(void)ac;
	ft_start_alloc();
	status = parser(av[1], &rt_struct);
	canva_inicializ(&rt_struct, 200, 100, c_new(0, 0, 0));

	return (status);
}

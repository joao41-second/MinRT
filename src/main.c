/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:19:42 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/20 13:08:13 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minRT.h"
#include "miniRT_struct.h"

int	main(int ac, char **av, char **env)
{
	t_minirt	rt_struct;
	int			status;

	(void)ac;
	status = parser(av[1], &rt_struct);
	ft_start_alloc();
	canva_inicializ(&rt_struct, 200, 100, c_new(0, 0, 0));

	return (status);
}

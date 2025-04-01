/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:27:43 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/27 03:24:45 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

// canva_inicializ(&rt_struct, 200, 100, c_new(0, 0, 0));
int	main(int ac, char **av, char **env)
{
	t_minirt	*rt_struct;
	int			status;

	(void)ac;
	ft_start_alloc();
	rt_struct = (t_minirt *)ft_malloc(sizeof(t_minirt), NULL);
	status = parser(av[1], rt_struct);
	ft_free_all();
	return (status);
}

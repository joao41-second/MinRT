/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:32:02 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/01 12:02:58 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

// canva_inicializ(&rt_struct, 200, 100, c_new(0, 0, 0));
int	main(int ac, char **av, char **env)
{
	t_minirt	*rt_struct;
	int			status;

	status = 0;
	(void)ac;
	(void)av;
	(void)env;
	ft_start_alloc();
	rt_struct = (t_minirt *)ft_malloc(sizeof(t_minirt), NULL);
	status = parser(av[1], rt_struct);
	ft_free_all();
	return (status);
}

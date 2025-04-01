/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:32:02 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/01 11:32:03 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

int	main(int ac, char **av, char **env)
{
	int			status;

	status = 0;
	(void)ac;
	(void)av;
	(void)env;
	ft_start_alloc();
	ft_free_all();
	return (status);
}

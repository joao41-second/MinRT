/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/18 15:51:54 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include <fcntl.h>

void	main_loop(t_minirt *rt_struct)
{

	ray_canva(create_point(0, -2, 0), rt_struct);

	canva_update(rt_struct);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/08 17:48:06 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include <time.h>

void	loop(t_minirt *rt_struct)
{

    	
	clock_t inicio = clock();
	ray_canva( rt_struct);
	clock_t fim = clock();
	rt_struct->c_ray.direction = normalize(rt_struct->c_ray.direction);
    	double tempo_exec = (double)(fim - inicio) / CLOCKS_PER_SEC; // Converte para segundos
//    	printf("Tempo de execução: %.6f segundos\n", tempo_exec);
  	canva_update(rt_struct);

};

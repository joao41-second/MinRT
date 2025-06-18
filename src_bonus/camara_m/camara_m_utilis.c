/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camara_m_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:57:50 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 16:58:10 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void	cm_update(t_camera_ms *cam)
{
	mat_set_inv(&cam->inv_tranform_matrix, cam->tranform_matrix);
}

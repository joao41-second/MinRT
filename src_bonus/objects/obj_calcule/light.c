/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:42:58 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 15:32:17 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"
#include "../objects.h"

t_light	ligth_init(t_color intensty, t_point point)
{
	t_light	ret;

	ret.intenstiy = intensty;
	ret.point = point;
	return (ret);
}

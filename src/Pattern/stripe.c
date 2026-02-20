/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:53:33 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 16:55:45 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minRT.h"

t_color	pat_stripe_at(t_point point, char axi, t_color a, t_color b)
{
	int	i;

	i = 0;
	if (axi == 'z')
		i = 2;
	if (axi == 'y')
		i = 1;
	if (axi == 'x')
		i = 0;
	if ((int)floor(point.val[i]) % 2 == 0)
		return (a);
	else
		return (b);
}

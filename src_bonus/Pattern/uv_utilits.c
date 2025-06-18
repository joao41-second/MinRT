/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_utilits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:39:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 16:51:45 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minRT.h"
#include <math.h>
#include <stdio.h>
#include <strings.h>

t_uv	uv_add(t_uv a, t_uv b)
{
	t_uv	uv;

	uv.u = a.u + b.u;
	uv.v = a.v + b.v;
	return (uv);
}

t_uv	uv_sacl(t_uv a, float b)
{
	t_uv	uv;

	uv.u = a.u * b;
	uv.v = a.v * b;
	return (uv);
}

void	pat_set_dp_trinagle(t_point edge0, t_point edge1,
		t_point edge2, float *dp)
{
	dp[0] = dot_product(edge0, edge0);
	dp[1] = dot_product(edge1, edge0);
	dp[2] = dot_product(edge1, edge1);
	dp[3] = dot_product(edge2, edge0);
	dp[4] = dot_product(edge2, edge1);
}

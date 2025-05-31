/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:59:26 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/31 13:19:06 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
#define PATTERN_H
#include "../miniRT_struct.h"

t_color pat_stripe_at(t_point point,char axi,t_color a, t_color b);

t_color pat_pixe_at(t_point point,t_img_ *img);


t_color pat_pixe_at_triang(t_point point,t_img_ *img,t_triangle *trinange);
#endif

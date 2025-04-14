/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:32:34 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/14 17:48:17 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H
# include "../miniRT_struct.h"

void	 loop(t_minirt *rt_struct);


void mouse(t_minirt *rt_struct);

void key_loop(int key, t_minirt *rt_structj);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:32:34 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 14:57:22 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H
# include "../miniRT_struct.h"

void	 loop(t_minirt *rt_struct);

void mouse(t_minirt *rt_struct);

void key_loop(int key, t_minirt *rt_struct);
#endif

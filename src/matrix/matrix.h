/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:44:00 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/19 10:13:02 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX
#define MATRIX

typedef struct s_matrix
{
	int size;
	double ** matr;
} t_matrix;



t_matrix mat_gener(int x);


void mat_print(const t_matrix matrix);


t_matrix mat_multip(t_matrix mat1,t_matrix mat2);


void mat_get_file(char *file,t_matrix matrix);
#endif

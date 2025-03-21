/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:44:00 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/21 12:40:54 by jperpct          ###   ########.fr       */
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

t_matrix mat_gener_identity(int x);

void mat_trans(t_matrix *mat);

double mat_det2x2(t_matrix mat);

double mat_det(t_matrix mat);

double mat_cof(t_matrix mat,int line,int column);

t_matrix mat_the_cof(t_matrix mat);

t_matrix mat_inv(t_matrix mat);

void mat_matsh_matrix(t_matrix *mat,char math,double nb);



t_matrix mat_sub(t_matrix mat,int line,int column);

void mat_free(t_matrix *matrix);

t_matrix mat_multip(t_matrix mat1,t_matrix mat2);

void mat_print(const t_matrix matrix);

void mat_get_file(char *file,t_matrix matrix);

void mat_clean();

t_matrix mat_cp(t_matrix mat);

//----------------utils--------------//

t_matrix mat_exet(t_matrix mat1, t_matrix mat2,double f(const void*, const void*,const void*,const void*));

//_____________exet_func____________//

double mat_copy(int *y,int*x,t_matrix *mat1,t_matrix *mat2);

double mat_mult_matrix(int *y,int*x,t_matrix *mat1,t_matrix *mat2);

double mat_transposing(int *y,int*x,t_matrix *mat1,t_matrix *mat2);

t_matrix mat_matrix_signal(int size);

#endif

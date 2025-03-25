/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:44:00 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/25 12:38:05 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

#include "../tuples/tuples.h"

#define IDENTI 50
#define TRANS 40
#define SCAL 30
#define ROTA 20
#define HEARING 10

typedef struct s_matrix
{
	int		size;
	int		flag;
	double	**matr;
}			t_matrix;

typedef union s_shearing
{
	struct {
		double x_y;
		double x_z;
		double y_x;
		double y_z;
		double z_x;
		double z_y;
	};
	double all[6];
} t_hearing;

typedef t_matrix t_scaling;
typedef t_matrix t_translation;
typedef t_matrix t_identiy;
typedef t_matrix t_rotation;
typedef t_matrix t_mat_hearing;

/**
 * @brief this funncion generate the new matrix
 *
 * @param x size the matrix ex: 2 generate matrix 2X2 
 * @return matrix inicialized all nb 0
 */
t_matrix	mat_gener(int x);

t_identiy	mat_gener_identity(int x);

t_translation	mat_gener_trans(double x,double y, double z);

t_scaling	mat_gener_scal(double x,double y, double z);

t_rotation 	mat_gener_rota(char axis,double deg);

t_mat_hearing 	mat_gener_hearing(t_hearing values);

void		mat_trans(t_matrix *mat);

double		mat_det2x2(t_matrix mat);

double		mat_det(t_matrix mat);

double		mat_cof(t_matrix mat, int line, int column);

t_point mat_x_tuple(t_tuple point,t_matrix mat);


t_matrix	mat_the_cof(t_matrix mat);

t_matrix	mat_inv(t_matrix mat);

void		mat_matsh_matrix(t_matrix *mat, char math, double nb);

t_matrix	mat_sub(t_matrix mat, int line, int column);

void		mat_free(t_matrix *matrix);

t_matrix	mat_multip(t_matrix mat1, t_matrix mat2);

void		mat_print(const t_matrix matrix);

void		mat_get_file(char *file, t_matrix matrix);

void		mat_clean(void);

t_matrix	mat_cp(t_matrix mat);

//----------------utils--------------//

t_matrix	mat_exet(t_matrix mat1, t_matrix mat2, double f( int *,
					 int *, t_matrix *, t_matrix *));

//_____________exet_func____________//

double		mat_copy(int *y, int *x, t_matrix *mat1, t_matrix *mat2);

double		mat_mult_matrix(int *y, int *x, t_matrix *mat1, t_matrix *mat2);

double		mat_transposing(int *y, int *x, t_matrix *mat1, t_matrix *mat2);

t_matrix	mat_matrix_signal(int size);

#endif

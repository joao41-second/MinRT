/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:44:00 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/16 12:22:46 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "../tuples/tuples.h"

# define IDENTI 50
# define TRANS 40
# define SCAL 30
# define ROTA 20
# define SHEARING 10

typedef struct s_matrix
{
	int				size;
	int				flag;
	double			**matr;
}					t_matrix;

typedef union s_shearing
{
	struct
	{
		double		x_y;
		double		x_z;
		double		y_x;
		double		y_z;
		double		z_x;
		double		z_y;
	};
	double			all[6];
}					t_shearing;

typedef t_matrix	t_scaling;
typedef t_matrix	t_translation;
typedef t_matrix	t_identiy;
typedef t_matrix	t_rotation;
typedef t_matrix	t_mat_shearing;

/**
 * @brief this function generate the new matrix
 *
 * @param x size the matrix ex: 2 generate matrix 2X2 
 * @return matrix inicialized all nb 0
 */
t_matrix			mat_gener(int x);

/**
 * @brief this function generate the new matrix the form
 *  \1,0,0,0\
 *  \0,1,0,0\
 *  \0,0,1,0\
 *  \0,0,0,1\
 *
 * @param x  size the matrix
 * @return matrix inicialized
 */
t_identiy			mat_gener_identity(int x);

/**
 * @brief this function generate the matrix the type translation
 *  \1,0,0,x\
 *  \0,1,0,y\
 *  \0,0,1,z\
 *  \0,0,0,1\
 *
 * @param x double the point
 * @param y double the point
 * @param z double the point
 * @return matrix inicialized
 */
t_translation		mat_gener_trans(double x, double y, double z);

/**
 * @brief this function generate the matrix the type scaling
 *  \x,0,0,0\
 *  \0,y,0,0\
 *  \0,0,z,0\
 *  \0,0,0,1\
 *
 * @param x 
 * @param y 
 * @param z 
 * @return matrix inicialized
 */
t_scaling			mat_gener_scal(double x, double y, double z);

/**
 * @brief this function generate the new matrix the type rotation
 *  \1, 0   ,   0    ,0\
 *  \0,cos r, -sin r ,0\
 *  \0,sin r,  cos r ,0\
 *  \0, 0,      0    ,1\
 *  not iqual all axis
 * @param axis axis the rotation
 * @param deg value in angele the 0 to 360 
 * @return matriz inicialized
 */
t_rotation			mat_gener_rota(char axis, double deg);

/**
 * @brief this function generate the new matrix the type shearing 
 *  \1,x_y,x_z,0\
 *  \y_x,1,y_z,0\
 *  \z_x,z_y,1,0\
 *  \0,0,0,1\
 *
 * @param values struct the values the z_y etc..
 * @return matrix inicialized
 */
t_mat_shearing		mat_gener_shearing(t_shearing values);

void				mat_trans(t_matrix *mat);

double				mat_det2x2(t_matrix mat);

double				mat_det(t_matrix mat);

double				mat_cof(t_matrix mat, int line, int column);

t_point				mat_x_tuple(t_tuple point, t_matrix mat);

t_matrix			mat_the_cof(t_matrix mat);

t_matrix			mat_inv(t_matrix mat);

void				mat_matsh_matrix(t_matrix *mat, char math, double nb);

t_matrix			mat_sub(t_matrix mat, int line, int column);

void				mat_free(t_matrix *matrix);

t_matrix			mat_multip(t_matrix mat1, t_matrix mat2);

void				mat_print(const t_matrix matrix);

void				mat_get_file(char *file, t_matrix matrix);

void				mat_clean(void);

t_matrix			mat_cp(t_matrix mat);

t_shearing			mat_inicialaiz_sh(void);
//----------------utils--------------//

t_matrix			mat_exet(t_matrix mat1, t_matrix mat2, double f(int *,
							int *, t_matrix *, t_matrix *));

//_____________exet_func____________//

double				mat_copy(int *y, int *x, t_matrix *mat1, t_matrix *mat2);

double				mat_mult_matrix(int *y, int *x, t_matrix *mat1,
						t_matrix *mat2);

double				mat_transposing(int *y, int *x, t_matrix *mat1,
						t_matrix *mat2);

t_matrix			mat_matrix_signal(int size);

void				mat_not_neg_zero(t_matrix *mat);

int					mat_iqual(t_matrix mat1, t_matrix mat2);
void	mat_set_trans(t_matrix *ret,double x, double y, double z);
void	mat_set_multip(t_matrix *resolt,t_matrix mat1, t_matrix mat2);

void	mat_set_view_transform(t_matrix *mat_,t_tuple form, t_tuple to, t_tuple up);
#endif

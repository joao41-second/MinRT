/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:21:05 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/17 14:10:22 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STRUCT_H
# define PARSER_STRUCT_H

typedef enum e_token
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	COMMENT,
	NEWLINE,
	OBJECT,
	ERROR,
	COUNT
}	t_token;

typedef struct s_token_map
{
	char		*key;
	t_token		value;
}	t_token_map;

typedef struct s_range
{
	double	min;
	double	max;
}	t_range;
#endif
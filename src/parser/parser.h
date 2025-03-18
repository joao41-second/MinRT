/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/18 17:04:25 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PARSER_H
# define PARSER_H

# include "../miniRT_struct.h"


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
    ERROR,
    COUNT
} t_token;

typedef struct s_token_map
{
    char        *key;
    t_token     value;
} t_token_map;


# endif
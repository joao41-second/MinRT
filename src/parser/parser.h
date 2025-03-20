/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/20 12:56:30 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PARSER_H
# define PARSER_H

# include "../miniRT_struct.h"

int         parser(const char *file, t_minirt *data);
void        parse_ambient(char *line, t_minirt *data, char *ptr, int fd);


# endif
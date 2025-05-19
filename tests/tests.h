/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:45:05 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/19 14:51:59 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TESTS_H
# define TESTS_H
// #define UNITY_INCLUDE_DOUBLE
#include "unity/unity.h"
#include "../src/minRT.h"
#include <time.h>


#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_WHITE   "\x1b[37m"
#define LOOP_ITERATIONS 100

int error_(char *name,int nb, int *error);
// void	test_tuples(void); void	test_ft_atof(void);

// void	test_ligth(void);

// void	test_view_trasfomr(void);

// void	test_word(void);

// void	shp_text(void);

// void	test_planes(void);
void	test_triangle(void);
void	test_cylinder(void);

#endif /* TESTS_H */

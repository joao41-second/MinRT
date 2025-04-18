/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray_for_objects.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:00:00 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/17 10:00:00 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void test_ray_for_objects(void)
{
    // Initialize the word list using start_word
    t_minirt rt_struct;
    start_word(&rt_struct);

    // Debugging: Print the word list
    printf("Debug: Printing word list\n");
    print_list_(rt_struct.word);

    // Define a ray
    t_ray ray = ray_gener(create_point(0, 0, 0), create_vector(0, 0, -1));

    // Call ray_for_objects
    t_obj_int result = ray_for_objects(rt_struct.word, ray);

    // Debugging: Print result details
    printf("Debug: Result min = %f, max = %f\n", result.min, result.max);
    if (result.ints != NULL) {
        printf("Debug: Intersections list is not NULL\n");
    } else {
        printf("Debug: Intersections list is NULL\n");
    }

    // Assertions
    printf("Testing ray_for_objects:\n");
    TEST_ASSERT_NOT_NULL(result.ints);
    TEST_ASSERT_TRUE(result.min != INT_MAX);
    TEST_ASSERT_TRUE(result.max != INT_MAX);

    // Clean up
    // ft_free_list(objects);
}
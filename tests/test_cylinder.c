/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:39:09 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/19 14:49:19 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void test_cylinder_normal(void)
{
    t_cylinder cylinder;
    t_object obj;
    t_vector n1, n2, n3;

    cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));

    n1 = cylinder_normal_at(obj.u_data.cylinder, create_point(1, 0, 0));
    printf("Debug: Input point: (%f, %f, %f)\n", 1.0, 0.0, 0.0);
    printf("Debug: Calculated normal: (%f, %f, %f)\n", n1.x, n1.y, n1.z);
    n2 = cylinder_normal_at(obj.u_data.cylinder, create_point(0, 0, -1));
    printf("Debug: Input point: (%f, %f, %f)\n", 0.0, 0.0, -1.0);
    printf("Debug: Calculated normal: (%f, %f, %f)\n", n2.x, n2.y, n2.z);
    n3 = cylinder_normal_at(obj.u_data.cylinder, create_point(0.5, 0, 0.5));
    printf("Debug: Input point: (%f, %f, %f)\n", 0.5, 0.0, 0.5);
    printf("Debug: Calculated normal: (%f, %f, %f)\n", n3.x, n3.y, n3.z);

    TEST_ASSERT_TRUE(is_equal_tuple(n1, create_vector(1, 0, 0)));
    TEST_ASSERT_TRUE(is_equal_tuple(n2, create_vector(0, 0, -1)));
    TEST_ASSERT_TRUE(is_equal_tuple(n3, create_vector(0.5, 0, 0.5)));
}

void test_cylinder_intersection(void)
{
    t_cylinder cylinder;
    t_object obj;
    t_ray r;
    t_intersection xs;

    cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));

    r = ray_gener(create_point(1, 0, -5), create_vector(0, 0, 1));
    printf("Debug: Ray origin: (%f, %f, %f), direction: (%f, %f, %f)\n", r.origin.x, r.origin.y, r.origin.z, r.direction.x, r.direction.y, r.direction.z);
    xs = ray_int_object(r, obj);
    printf("Debug: Intersection t[0]: %f, t[1]: %f\n", xs.t[0], xs.t[1]);
    printf("Debug: Intersection object: %p\n", &xs.object);

    TEST_ASSERT_EQUAL_FLOAT(5, xs.t[0]);
    // TEST_ASSERT_EQUAL_PTR(&obj, &xs.object);

    r = ray_gener(create_point(0, 0, -5), create_vector(0, 0, 1));
    printf("Debug: Ray origin: (%f, %f, %f), direction: (%f, %f, %f)\n", r.origin.x, r.origin.y, r.origin.z, r.direction.x, r.direction.y, r.direction.z);
    xs = ray_int_object(r, obj);
    printf("Debug: Intersection t[0]: %f, t[1]: %f\n", xs.t[0], xs.t[1]);
    printf("Debug: Intersection object: %p\n", &xs.object);

    TEST_ASSERT_EQUAL_FLOAT(4, xs.t[0]);
    // TEST_ASSERT_EQUAL_PTR(&obj,&xs.object);
}
void test_lig_normalize_cylinder(void)
{
    t_cylinder cylinder;
    t_object obj;
    t_point point;
    t_vector normal;

    cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));

    point = create_point(0, 1, 0);
    normal = lig_normalize(obj, point);
    printf("Debug: Normal at point (%f, %f, %f): (%f, %f, %f)\n", point.x, point.y, point.z, normal.x, normal.y, normal.z);

    TEST_ASSERT_TRUE(is_equal_tuple(normal, create_vector(0, 1, 0)));
}

void test_ray_misses_cylinder_1(void)
{
    t_cylinder cylinder;
    t_ray r;
    t_intersection xs;

    cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    t_object obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
    r = ray_gener(create_point(1, 0, 0), normalize(create_vector(0, 1, 0)));
    xs = ray_int_object(r, obj);

    TEST_ASSERT_NULL(&xs);
}


void test_ray_misses_cylinder_2(void)
{
    t_cylinder cylinder;
    t_ray r;
    t_intersection xs;

    cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    t_object obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
    r = ray_gener(create_point(0, 0, 0), normalize(create_vector(0, 1, 0)));
    xs = ray_int_object(r, obj);

    TEST_ASSERT_NULL(&xs);
}

void test_ray_misses_cylinder_3(void)
{
    t_cylinder cylinder;
    t_ray r;
    t_intersection xs;

 cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    t_object obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
    r = ray_gener(create_point(0, 0, -5), normalize(create_vector(1, 1, 1)));
    xs = ray_int_object(r, obj);

    TEST_ASSERT_NULL(&xs);
}

void test_normal_vector_on_cylinder_1(void)
{
    t_cylinder cylinder;
    t_vector n;

 cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    t_object obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
    n = cylinder_normal_at(cylinder, create_point(1, 0, 0));

    TEST_ASSERT_EQUAL_FLOAT(1, n.x);
    TEST_ASSERT_EQUAL_FLOAT(0, n.y);
    TEST_ASSERT_EQUAL_FLOAT(0, n.z);
}

void test_normal_vector_on_cylinder_2(void)
{
    t_cylinder cylinder;
    t_vector n;

 cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    t_object obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
    n = cylinder_normal_at(cylinder, create_point(0, 5, -1));

    TEST_ASSERT_EQUAL_FLOAT(0, n.x);
    TEST_ASSERT_EQUAL_FLOAT(0, n.y);
    TEST_ASSERT_EQUAL_FLOAT(-1, n.z);
}

void test_normal_vector_on_cylinder_3(void)
{
    t_cylinder cylinder;
    t_vector n;

 cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    t_object obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
    n = cylinder_normal_at(cylinder, create_point(0, -2, 1));

    TEST_ASSERT_EQUAL_FLOAT(0, n.x);
    TEST_ASSERT_EQUAL_FLOAT(0, n.y);
    TEST_ASSERT_EQUAL_FLOAT(1, n.z);
}

void test_normal_vector_on_cylinder_4(void)
{
    t_cylinder cylinder;
    t_vector n;

    cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    t_object obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
    n = cylinder_normal_at(cylinder, create_point(-1, 1, 0));

    TEST_ASSERT_EQUAL_FLOAT(-1, n.x);
    TEST_ASSERT_EQUAL_FLOAT(0, n.y);
    TEST_ASSERT_EQUAL_FLOAT(0, n.z);
}

void test_default_min_max_for_cylinder(void)
{
    t_cylinder cylinder;

 cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    t_object obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));

    TEST_ASSERT_EQUAL_FLOAT(-INFINITY, cylinder.minimum);
    TEST_ASSERT_EQUAL_FLOAT(INFINITY, cylinder.maximum);
}

void test_default_closed_value_is_false(void)
{
    t_cylinder cylinder;

 cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    t_object obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));

    TEST_ASSERT_FALSE(cylinder.closed);
}

void test_capped_cylinder_intersections(void)
{
    t_cylinder cylinder;
    t_object obj;
    t_ray r;
    t_intersection xs;

    cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    cylinder.closed = TRUE;
    obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));

    r = ray_gener(create_point(0, 3, 0), create_vector(0, -1, 0));
    xs = ray_int_object(r, obj);
    TEST_ASSERT_EQUAL_FLOAT(1, xs.t[0]);

    r = ray_gener(create_point(0, -1, 0), create_vector(0, 1, 0));
    xs = ray_int_object(r, obj);
    TEST_ASSERT_EQUAL_FLOAT(1, xs.t[0]);
}

void test_capped_cylinder_normals(void)
{
    t_cylinder cylinder;
    t_object obj;
    t_vector n;

    cylinder = create_cylinder(create_point(0, 0, 0), create_vector(0, 1, 0), 1, 2);
    cylinder.closed = TRUE;
    obj = *create_object(&cylinder, OBJ_CYLINDER, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));

    n = cylinder_normal_at(cylinder, create_point(0, 2, 0));
    TEST_ASSERT_EQUAL_FLOAT(0, n.x);
    TEST_ASSERT_EQUAL_FLOAT(1, n.y);
    TEST_ASSERT_EQUAL_FLOAT(0, n.z);

    n = cylinder_normal_at(cylinder, create_point(0, -2, 0));
    TEST_ASSERT_EQUAL_FLOAT(0, n.x);
    TEST_ASSERT_EQUAL_FLOAT(-1, n.y);
    TEST_ASSERT_EQUAL_FLOAT(0, n.z);
}

void test_cylinder(void)
{
    RUN_TEST(test_cylinder_normal);
    RUN_TEST(test_cylinder_intersection);
    RUN_TEST(test_lig_normalize_cylinder);
    RUN_TEST(test_ray_misses_cylinder_1);
    RUN_TEST(test_ray_misses_cylinder_2);
    RUN_TEST(test_ray_misses_cylinder_3);
    RUN_TEST(test_normal_vector_on_cylinder_1);
    RUN_TEST(test_normal_vector_on_cylinder_2);
    RUN_TEST(test_normal_vector_on_cylinder_3);
    RUN_TEST(test_normal_vector_on_cylinder_4);
    RUN_TEST(test_default_min_max_for_cylinder);
    RUN_TEST(test_default_closed_value_is_false);
    RUN_TEST(test_capped_cylinder_intersections);
    RUN_TEST(test_capped_cylinder_normals);
}
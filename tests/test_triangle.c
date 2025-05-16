#include "tests.h"



void test_triangle_creation(void)
{
    t_triangle triangle;

    triangle = create_triangle(create_point(0, 1, 0), create_point(-1, 0, 0), create_point(1, 0, 0));

    TEST_ASSERT_TRUE(is_equal_tuple(triangle.p1, create_point(0, 1, 0)));
    TEST_ASSERT_TRUE(is_equal_tuple(triangle.p2, create_point(-1, 0, 0)));
    TEST_ASSERT_TRUE(is_equal_tuple(triangle.p3, create_point(1, 0, 0)));

    TEST_ASSERT_TRUE(is_equal_tuple(triangle.edge1, create_vector(-1, -1, 0)));
    TEST_ASSERT_TRUE(is_equal_tuple(triangle.edge2, create_vector(1, -1, 0)));
    TEST_ASSERT_TRUE(is_equal_tuple(triangle.normal, create_vector(0, 0, -1)));
}

void test_triangle_normal(void)
{
    t_triangle triangle;
    t_vector n1, n2, n3;

    triangle = create_triangle(create_point(0, 1, 0), create_point(-1, 0, 0), create_point(1, 0, 0));

    n1 = triangle_normal_at(triangle);
    n2 = triangle_normal_at(triangle);
    n3 = triangle_normal_at(triangle);

    TEST_ASSERT_TRUE(is_equal_tuple(n1, triangle.normal));
    TEST_ASSERT_TRUE(is_equal_tuple(n2, triangle.normal));
    TEST_ASSERT_TRUE(is_equal_tuple(n3, triangle.normal));
}

void test_triangle_ray_intersections(void)
{
    t_triangle triangle;
    t_object obj_triangle;
    t_ray r;
    t_intersection xs;

    triangle = create_triangle(create_point(0, 1, 0), create_point(-1, 0, 0), create_point(1, 0, 0));
    obj_triangle.u_data.triangle = triangle;
    obj_triangle.type = OBJ_TRIANGLE;

    // Ray parallel to the triangle
    r = ray_gener(create_point(0, -1, -2), create_vector(0, 1, 0));
    xs = ray_int_triangle(r, obj_triangle);
    TEST_ASSERT_EQUAL_FLOAT(0.0, xs.inter);

    // Ray misses the p1-p3 edge
    r = ray_gener(create_point(1, 1, -2), create_vector(0, 0, 1));
    xs = ray_int_triangle(r, obj_triangle);
    TEST_ASSERT_EQUAL_FLOAT(0.0, xs.inter);

    // Ray misses the p1-p2 edge
    r = ray_gener(create_point(-1, 1, -2), create_vector(0, 0, 1));
    xs = ray_int_triangle(r, obj_triangle);
    TEST_ASSERT_EQUAL_FLOAT(0.0, xs.inter);

    // Ray misses the p2-p3 edge
    r = ray_gener(create_point(0, -1, -2), create_vector(0, 0, 1));
    xs = ray_int_triangle(r, obj_triangle);
    TEST_ASSERT_EQUAL_FLOAT(0.0, xs.inter);

    // Ray strikes the triangle
    r = ray_gener(create_point(0, 0.5, -2), create_vector(0, 0, 1));
    xs = ray_int_triangle(r, obj_triangle);
    TEST_ASSERT_EQUAL_FLOAT(1.0, xs.inter);
    TEST_ASSERT_EQUAL_FLOAT(2.0, xs.t[0]);
}

void test_triangle(void)
{
    RUN_TEST(test_triangle_creation);
    RUN_TEST(test_triangle_normal);
    RUN_TEST(test_triangle_ray_intersections);
}
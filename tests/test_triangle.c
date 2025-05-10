#include "tests.h"

void test_triangle_normal(void)
{
    t_triangle triangle;
    t_object obj;
    t_vector n1, n2, n3;

    triangle = create_triangle(create_point(0, 1, 0), create_point(-1, 0, 0), create_point(1, 0, 0));
    obj = *create_object(&triangle, OBJ_TRIANGLE, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));

    n1 = triangle_normal_at(obj.u_data.triangle);
    n2 = triangle_normal_at(obj.u_data.triangle);
    n3 = triangle_normal_at(obj.u_data.triangle);

    TEST_ASSERT_TRUE(is_equal_tuple(n1, obj.u_data.triangle.normal));
    TEST_ASSERT_TRUE(is_equal_tuple(n2, obj.u_data.triangle.normal));
    TEST_ASSERT_TRUE(is_equal_tuple(n3, obj.u_data.triangle.normal));

}

void test_triangle_intersection(void)
{
    t_triangle triangle;
    t_object obj;
    t_ray r;
    t_intersection xs;

    triangle = create_triangle(create_point(0, 1, 0), create_point(-1, 0, 0), create_point(1, 0, 0));
    obj = *create_object(&triangle, OBJ_TRIANGLE, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));

    r = ray_gener(create_point(0, 0,-2), create_vector(0, 0, 1));
    xs = ray_int_object(r, obj);

    printf("Debug: Ray origin: (%f, %f, %f)\n", r.origin.x, r.origin.y, r.origin.z);
    printf("Debug: Ray direction: (%f, %f, %f)\n", r.direction.x, r.direction.y, r.direction.z);
    printf("Debug: Intersection count: %f\n", xs.inter);
    printf("Debug: Intersection t[0]: %f\n", xs.t[0]);
    printf("Debug: Intersection object: %p\n", &xs.object);
    // printf("Debug: det: %f, u: %f, v: %f, t: %f\n", det, u, v, t);
    printf("Debug: Triangle edges: edge1(%f, %f, %f), edge2(%f, %f, %f)\n", obj.u_data.triangle.edge1.x, obj.u_data.triangle.edge1.y, obj.u_data.triangle.edge1.z, obj.u_data.triangle.edge2.x, obj.u_data.triangle.edge2.y, obj.u_data.triangle.edge2.z);
    printf("Debug: Ray origin: (%f, %f, %f), direction: (%f, %f, %f)\n", r.origin.x, r.origin.y, r.origin.z, r.direction.x, r.direction.y, r.direction.z);

    TEST_ASSERT_EQUAL_FLOAT(1.0, xs.inter);
    TEST_ASSERT_EQUAL_FLOAT(2, xs.t[0]);
    TEST_ASSERT_EQUAL_PTR(&obj, xs.object);

    // r = ray_gener(create_point(0, -1, -2), create_vector(0, 0, 1));
    // xs = ray_int_object(r, obj);

    // TEST_ASSERT_EQUAL_FLOAT(0.0, xs.inter);
}
void test_lig_normalize_triangle(void)
{
    t_triangle triangle;
    t_object *obj;
    t_vector normal;

    triangle = create_triangle(create_point(0, 1, 0), create_point(-1, 0, 0), create_point(1, 0, 0));
    obj = create_object(&triangle, OBJ_TRIANGLE, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));

    normal = lig_normalize(*obj, create_point(0, 0.5, 0));
    TEST_ASSERT_TRUE(is_equal_tuple(normal, obj->u_data.triangle.normal));

    normal = lig_normalize(*obj, create_point(-0.5, 0.75, 0));
    TEST_ASSERT_TRUE(is_equal_tuple(normal, obj->u_data.triangle.normal));

    normal = lig_normalize(*obj, create_point(0.5, 0.25, 0));
    TEST_ASSERT_TRUE(is_equal_tuple(normal, obj->u_data.triangle.normal));
}
void test_triangle(void)
{
    RUN_TEST(test_triangle_normal);
    RUN_TEST(test_triangle_intersection);
    RUN_TEST(test_lig_normalize_triangle);
}
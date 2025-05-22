// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test_planes.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/17 13:39:09 by rerodrig          #+#    #+#             */
// /*   Updated: 2025/05/12 11:34:50 by rerodrig         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */



// #include "tests.h"
// #include <stdio.h>

// /* The normal of a plane is constant everywhere */
// void test_planes_constant_normal(void)
// {
//     t_plane     plane;
//     t_object    *obj;
//     t_vector    n1;
//     t_vector    n2;
//     t_vector    n3;

//     plane = create_plane(create_point(0, 0, 0));
//     obj = create_object(&plane, OBJ_PLANE, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
//     n1 = plane_normal_at(&obj->u_data.plane, create_point(0, 0, 0));
//     n2 = plane_normal_at(&obj->u_data.plane, create_point(10, 0, -10));
//     n3 = plane_normal_at(&obj->u_data.plane, create_point(-5, 0, 150));

//     TEST_ASSERT_TRUE(is_equal_tuple(n1, create_vector(0, 1, 0)));
//     TEST_ASSERT_TRUE(is_equal_tuple(n2, create_vector(0, 1, 0)));
//     TEST_ASSERT_TRUE(is_equal_tuple(n3, create_vector(0, 1, 0)));
// }

// /* Intersect with a ray parallel to the plane */
// void test_planes_intersect_a_ray_parallel(void)
// {
//     t_plane     plane;
//     t_object    obj;
//     t_ray       r;
//     t_intersection xs;

//     plane = create_plane(create_point(0, 0, 0));
//     obj = *create_object(&plane, OBJ_PLANE, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
//     r = ray_gener(create_point(0, 10, 0), create_vector(0, 0, 1));
//     xs = ray_int_object(r, obj);

//     TEST_ASSERT_EQUAL_INT(0, xs.inter);
//     TEST_ASSERT_EQUAL_FLOAT(-1, xs.t[0]);
//     TEST_ASSERT_EQUAL_FLOAT(-1, xs.t[1]);
//     TEST_ASSERT_NULL(xs.object);
// }

// void test_planes_intersect_a_coplanar(void)
// {
//     t_plane     plane;
//     t_object    obj;
//     t_ray       r;
//     t_intersection xs;

//     plane = create_plane(create_point(0, 0, 0));
//     obj = *create_object(&plane, OBJ_PLANE, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
//     r = ray_gener(create_point(0, 0, 0), create_vector(0, 0, 1));
//     xs = ray_int_object(r, obj);

//     TEST_ASSERT_EQUAL_INT(0, xs.inter);
//     TEST_ASSERT_EQUAL_FLOAT(-1, xs.t[0]);
//     TEST_ASSERT_EQUAL_FLOAT(-1, xs.t[1]);
//     TEST_ASSERT_NULL(xs.object);
// }
// // void test_planes_intersect_a_local(void)
// // {
// //     t_plane     plane;
// //     t_object    obj;
// //     t_ray       r;
// //     t_intersection xs;

// //     plane = create_plane(create_point(0, 0, 0));
// //     obj = *create_object(&plane, OBJ_PLANE, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
// //     r = ray_gener(create_point(0, 0, 0), create_vector(0, 0, 1));
// //     xs = ray_int_object(r, obj);

// //     TEST_ASSERT_EQUAL_INT(0, xs.inter);
// //     TEST_ASSERT_EQUAL_FLOAT(-1, xs.t[0]);
// //     TEST_ASSERT_EQUAL_FLOAT(-1, xs.t[1]);
// //     TEST_ASSERT_NULL(xs.object);
// // }

// void test_planes_intersect_from_above(void)
// {
//     t_plane     plane;
//     t_object    obj;
//     t_ray       r;
//     t_intersection xs;

//     plane = create_plane(create_point(0, 0, 0));
//     obj = *create_object(&plane, OBJ_PLANE, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
//     r = ray_gener(create_point(0, 1, 0), create_vector(0, -1, 0));
//     xs = ray_int_object(r, obj);

//     printf("Debug: Object pointer: %p\n", &obj);
//     printf("Debug: Intersection object: %p\n", &xs.object);
//     printf("Debug: Intersection t0: %f\n", xs.t[0]);
//     printf("Debug: Intersection t1: %f\n", xs.t[1]);
//     TEST_ASSERT_EQUAL_INT(1, xs.inter);
//     TEST_ASSERT_EQUAL_FLOAT(1, xs.t[0]);
//     TEST_ASSERT_EQUAL_FLOAT(-1, xs.t[1]);

// }

// void test_planes_intersect_from_below(void)
// {
//     t_plane     plane;
//     t_object    obj;
//     t_ray       r;
//     t_intersection xs;

//     plane = create_plane(create_point(0, 0, 0));
//     obj = *create_object(&plane, OBJ_PLANE, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
//     r = ray_gener(create_point(0, -1, 0), create_vector(0, 1, 0));
//     xs = ray_int_object(r, obj);

//     printf("Debug: Object pointer: %p\n", &obj);
//     printf("Debug: Intersection object: %p\n", &xs.object);
//     printf("Debug: Intersection t0: %f\n", xs.t[0]);
//     printf("Debug: Intersection t1: %f\n", xs.t[1]);

//     TEST_ASSERT_EQUAL_INT(1, xs.inter);
//     TEST_ASSERT_EQUAL_FLOAT(1, xs.t[0]);
//     TEST_ASSERT_EQUAL_FLOAT(-1, xs.t[1]);

// }

// void test_lig_normalize_plane(void)
// {
//     t_plane plane;
//     t_object *obj;
//     t_vector normal;

//     plane = create_plane(create_point(0, 0, 0));
//     obj = create_object(&plane, OBJ_PLANE, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));

//     normal = lig_normalize(*obj, create_point(0, 0, 0));
//     TEST_ASSERT_TRUE(is_equal_tuple(normal, create_vector(0, 1, 0)));

//     normal = lig_normalize(*obj, create_point(10, 0, -10));
//     TEST_ASSERT_TRUE(is_equal_tuple(normal, create_vector(0, 1, 0)));

//     normal = lig_normalize(*obj, create_point(-5, 0, 150));
//     TEST_ASSERT_TRUE(is_equal_tuple(normal, create_vector(0, 1, 0)));
// }
// void test_camera_plane_interaction(void)
// {
//     t_plane plane;
//     t_object *obj;
//     t_camera_ms cam;

//     // Initialize plane and camera
//     plane = create_plane(create_point(0, 0, 0));
//     obj = create_object(&plane, OBJ_PLANE, obj_material_init(c_new(1, 1, 1), obj_init_values_material(0.5, 0.6, 0.3, 100)));
//     camera_init(&cam, create_point(0, 0, 10), create_vector(0, 0, -1), DEFAULT_FOV);

//     // Simulate camera movement
//     cam.origin = create_point(0, 0, 100);
//     camera_update_view(&cam);

//     // Check if the plane is rendered correctly
//     t_vector normal = lig_normalize(*obj, create_point(0, 0, 0));
//     TEST_ASSERT_TRUE(is_equal_tuple(normal, create_vector(0, 1, 0)));

//     printf("Camera origin: (%f, %f, %f)\n", cam.origin.x, cam.origin.y, cam.origin.z);
//     printf("Plane center: (%f, %f, %f)\n", plane.center.x, plane.center.y, plane.center.z);
// }


// void	test_planes(void)
// {
// 	RUN_TEST(test_planes_constant_normal);
//     RUN_TEST(test_planes_intersect_a_ray_parallel);
//     RUN_TEST(test_planes_intersect_a_coplanar);
//     RUN_TEST(test_planes_intersect_from_above);
//     RUN_TEST(test_planes_intersect_from_below);
//     RUN_TEST(test_lig_normalize_plane);
//     RUN_TEST(test_camera_plane_interaction);
// }
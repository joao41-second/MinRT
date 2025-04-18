/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:48:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/18 12:28:22 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minRT.h"
#include "camera.h"

/**
 * Initializes the camera with default parameters and updates its view.
 * Sets the camera's origin, direction, aspect ratio, field of view (FOV),
 * width, and height based on the provided dimensions. The camera's view
 * is updated to reflect these initial settings.
 *
 * @param cam Pointer to the camera structure to be initialized.
 * @param width The width of the camera's viewport.
 * @param height The height of the camera's viewport.
 */
void camera_init(t_camera *cam)
{
    cam->origin = create_point(2,0, 0);
    cam->direction = create_vector(-1, 0, 0);
    cam->aspect_ratio = (double)WALL_X/WALL_Y;
    cam->fov = 60.0;
    camera_update_view(cam);
}
/**
 * Rotates the camera based on the given delta values for x and y.
 * The rotation is adjusted by a predefined mouse sensitivity factor.
 * After updating the camera's direction, the camera's view is updated
 * to reflect the new orientation.
 *
 * @param camera Pointer to the camera structure to be rotated.
 * @param dx Change in the x-direction for rotation.
 * @param dy Change in the y-direction for rotation.
 */
void camera_rotate(t_camera *camera, double dx, double dy)
{
    double sensitivity = MOUSE_SENSITIVITY;
    
    dx *= sensitivity;
    dy *= sensitivity;
    camera->direction.x += dx;
    camera->direction.y += dy;
    camera_update_view(camera);
}

/**
 * Updates the camera's view and inverse view matrices based on its current
 * position and direction. It calculates the forward, right, and true up
 * vectors to construct the view matrix using the camera's origin and
 * direction. The inverse of the view matrix is also computed for further
 * transformations.
 *
 * @param cam Pointer to the camera structure whose view matrices are to be updated.
 */
void camera_update_view(t_camera *cam)
{
    t_vector up = create_vector(0, 1, 0);
    t_vector forward = normalize(cam->direction);
    t_vector right = normalize(cross_product(forward, up));
    t_vector true_up = cross_product(right, forward);
    
    cam->view_matrix = mat_lookat(cam->origin, 
                                  add_tuples(cam->origin, forward), 
                                  true_up);
    cam->inv_view_matrix = mat_inv(cam->view_matrix);
    
    
}
/**
 * Generates a ray from the camera's origin through a specified pixel
 * on the viewport. The ray direction is calculated based on the camera's
 * field of view, aspect ratio, and the normalized device coordinates
 * (NDC) of the pixel. The direction is transformed by the inverse view
 * matrix to account for the camera's orientation.
 *
 * @param cam Pointer to the camera structure.
 * @param x The x-coordinate of the pixel on the viewport.
 * @param y The y-coordinate of the pixel on the viewport.
 * @return A ray originating from the camera and passing through the specified pixel.
 */
t_ray camera_generate_ray(t_camera *cam, double x, double y)
{
    double scale = tan(cam->fov * 0.5 * M_PI / 180.0); // FOV in radians
    double aspect_ratio = cam->aspect_ratio;
    double xndc = (2.0 * (x + 0.5) / WALL_X - 1.0) * aspect_ratio * scale;
    double yndc = (1.0 - 2.0 * (y + 0.5) / WALL_Y) * scale;
    t_vector ray_dir = create_vector(xndc, yndc, 1.0);
    
    ray_dir = normalize(mat_x_tuple(ray_dir, cam->inv_view_matrix));
    return ray_gener(cam->origin, ray_dir);
}

/**
 * Moves the camera's position based on the specified keycode input.
 * The camera can move forward, backward, left, or right, depending on
 * the key pressed. The movement is determined by the camera's current
 * direction and a predefined movement speed. After moving, the camera's
 * view is updated to reflect the new position.
 *
 * @param cam Pointer to the camera structure to be moved.
 * @param keycode The keycode representing the direction of movement.
 */
void camera_move(t_camera *cam, int keycode)
{
    t_vector forward = normalize(cam->direction); // Forward direction
    t_vector right = cross_product(forward, create_vector(0, 1, 0)); // Right direction
    t_vector up = create_vector(0, 1, 0); // Up direction (Y-axis)

    if (keycode == KEY_UP) // Move forward
        cam->origin = add_tuples(cam->origin, scalar_mult_tuples(forward, MOVE_SPEED));
    else if (keycode == KEY_DOWN) // Move backward
        cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(forward, MOVE_SPEED));
    else if (keycode == KEY_LEFT) // Move left
        cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(right, MOVE_SPEED));
    else if (keycode == KEY_RIGHT) // Move right
        cam->origin = add_tuples(cam->origin, scalar_mult_tuples(right, MOVE_SPEED));
    else if (keycode == KEY_W) // Move up
        cam->origin = add_tuples(cam->origin, scalar_mult_tuples(up, MOVE_SPEED));
    else if (keycode == KEY_S) // Move down
        cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(up, MOVE_SPEED));

    camera_update_view(cam); // Update the camera's view matrix
}

/**
 * Constructs a view matrix using the LookAt method, which defines a 
 * camera's orientation and position in 3D space. The function computes 
 * the forward, right, and true up vectors to create a rotation matrix, 
 * and combines it with a translation matrix to form the final view matrix.
 *
 * @param eye The position of the camera in world coordinates.
 * @param center The point the camera is looking at.
 * @param up The up direction vector, typically (0, 1, 0).
 * @return A view matrix representing the camera's transformation.
 */
t_matrix mat_lookat(t_point eye, t_point center, t_vector up)
{
    t_vector f = normalize(sub_tuples(center, eye));
    t_vector s = normalize(cross_product(f, up));
    t_vector u = cross_product(s, f);

    t_matrix rotation = mat_gener_identity(4);
    rotation.matr[0][0] = s.x;
    rotation.matr[0][1] = s.y;
    rotation.matr[0][2] = s.z;
    rotation.matr[1][0] = u.x;
    rotation.matr[1][1] = u.y;
    rotation.matr[1][2] = u.z;
    rotation.matr[2][0] = -f.x;
    rotation.matr[2][1] = -f.y;
    rotation.matr[2][2] = -f.z;
    t_matrix translation = mat_gener_trans(-eye.x, -eye.y, -eye.z);
    t_matrix view_matrix = mat_multip(rotation, translation);
    return view_matrix;
}

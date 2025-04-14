/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_navigator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:14:21 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/14 18:15:04 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minRT.h"
#include <math.h>

#define AXIS_SIZE 400
#define AXIS_OFFSET 60
#define AXIS_THICKNESS 2

// Define colors for each axis
#define COLOR_X 0x00FF0000  // Red for X axis
#define COLOR_Y 0x0000FF00  // Green for Y axis
#define COLOR_Z 0x000000FF  // Blue for Z axis

/**
 * Line drawing data structure
 */
typedef struct s_line {
    int x0, y0;
    int x1, y1;
    int dx, dy;
    int sx, sy;
    int err;
} t_line;

/**
 * Draw a pixel with bounds checking
 */
static void draw_pixel(t_img_ *img, int x, int y, int color)
{
    if (x < 0 || y < 0 || x >= WALL_X || y >= WALL_Y)
        return;
    
    char *dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

/**
 * Draw a line using Bresenham's algorithm
 */
static void draw_line(t_img_ *img, int x0, int y0, int x1, int y1, int color)
{
    t_line line;
    
    line.x0 = x0;
    line.y0 = y0;
    line.x1 = x1;
    line.y1 = y1;
    
    line.dx = abs(line.x1 - line.x0);
    line.dy = -abs(line.y1 - line.y0);
    line.sx = line.x0 < line.x1 ? 1 : -1;
    line.sy = line.y0 < line.y1 ? 1 : -1;
    line.err = line.dx + line.dy;
    
    while (1)
    {
        draw_pixel(img, line.x0, line.y0, color);
        
        if (line.x0 == line.x1 && line.y0 == line.y1)
            break;
            
        int e2 = 2 * line.err;
        if (e2 >= line.dy)
        {
            if (line.x0 == line.x1)
                break;
            line.err += line.dy;
            line.x0 += line.sx;
        }
        if (e2 <= line.dx)
        {
            if (line.y0 == line.y1)
                break;
            line.err += line.dx;
            line.y0 += line.sy;
        }
    }
}

/**
 * Draw a thick line
 */
static void draw_thick_line(t_img_ *img, int x0, int y0, int x1, int y1, int color, int thickness)
{
    for (int i = 0; i < thickness; i++)
    {
        for (int j = 0; j < thickness; j++)
        {
            draw_line(img, x0+i, y0+j, x1+i, y1+j, color);
        }
    }
}

/**
 * Transform a point using the camera's view matrix
 * This is the key function that makes the axis rotate with the camera
 */
static void transform_point(t_camera *cam, float x, float y, float z, float *outX, float *outY, float *outZ)
{
    // Note: Using matrix access pattern from the mat_lookat function
    *outX = x * cam->view_matrix.matr[0][0] + 
            y * cam->view_matrix.matr[0][1] + 
            z * cam->view_matrix.matr[0][2];
            
    *outY = x * cam->view_matrix.matr[1][0] + 
            y * cam->view_matrix.matr[1][1] + 
            z * cam->view_matrix.matr[1][2];
            
    *outZ = x * cam->view_matrix.matr[2][0] + 
            y * cam->view_matrix.matr[2][1] + 
            z * cam->view_matrix.matr[2][2];
}

/**
 * Project a 3D point to screen coordinates
 */
static void project_point(t_camera *cam, float x, float y, float z, int *screenX, int *screenY)
{
    float rotX, rotY, rotZ;
    
    // Transform point using camera's view matrix
    transform_point(cam, x, y, z, &rotX, &rotY, &rotZ);
    
    // Apply perspective
    float perspective = 5.0 + rotZ;
    if (perspective < 0.1) perspective = 0.1;
    float scale = AXIS_SIZE / perspective;
    
    // Project to screen coordinates (bottom-right corner)
    *screenX = WALL_X - AXIS_OFFSET + rotX * scale;
    *screenY = WALL_Y - AXIS_OFFSET - rotY * scale;
}

/**
 * Draw the axis cube navigator with the Blender-style orientation indicator
 */
void draw_axis_navigator(t_minirt *rt_struct)
{
    // Base position for axis
    int originX, originY;
    int endX, endY;
    
    // Project the origin point
    project_point(&rt_struct->scene.world.camera, 0, 0, 0, &originX, &originY);
    
    // Draw X axis (red)
    project_point(&rt_struct->scene.world.camera, 1, 0, 0, &endX, &endY);
    draw_thick_line(&rt_struct->canva.canva, originX, originY, endX, endY, COLOR_X, AXIS_THICKNESS);
    
    // Draw Y axis (green)
    project_point(&rt_struct->scene.world.camera, 0, 1, 0, &endX, &endY);
    draw_thick_line(&rt_struct->canva.canva, originX, originY, endX, endY, COLOR_Y, AXIS_THICKNESS);
    
    // Draw Z axis (blue)
    project_point(&rt_struct->scene.world.camera, 0, 0, 1, &endX, &endY);
    draw_thick_line(&rt_struct->canva.canva, originX, originY, endX, endY, COLOR_Z, AXIS_THICKNESS);
    
    // Draw negative axes (paler colors)
    project_point(&rt_struct->scene.world.camera, -0.5, 0, 0, &endX, &endY);
    draw_thick_line(&rt_struct->canva.canva, originX, originY, endX, endY, 0x00AA3333, 1);
    
    project_point(&rt_struct->scene.world.camera, 0, -0.5, 0, &endX, &endY);
    draw_thick_line(&rt_struct->canva.canva, originX, originY, endX, endY, 0x0033AA33, 1);
    
    project_point(&rt_struct->scene.world.camera, 0, 0, -0.5, &endX, &endY);
    draw_thick_line(&rt_struct->canva.canva, originX, originY, endX, endY, 0x003333AA, 1);
    
    // Add labels with mlx_string_put (will be called after image is flushed to window)
    int labelX, labelY;
    
    // X axis label
    project_point(&rt_struct->scene.world.camera, 1.2, 0, 0, &labelX, &labelY);
    mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, 
                  labelX, labelY, COLOR_X, "X");
                  
    // Y axis label
    project_point(&rt_struct->scene.world.camera, 0, 1.2, 0, &labelX, &labelY);
    mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, 
                  labelX, labelY, COLOR_Y, "Y");
                  
    // Z axis label
    project_point(&rt_struct->scene.world.camera, 0, 0, 1.2, &labelX, &labelY);
    mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, 
                  labelX, labelY, COLOR_Z, "Z");
                  
    // Negative axis labels (only if they're pointing toward camera)
    float nx, ny, nz;
    transform_point(&rt_struct->scene.world.camera, -1, 0, 0, &nx, &ny, &nz);
    if (nz > 0) {
        project_point(&rt_struct->scene.world.camera, -1.2, 0, 0, &labelX, &labelY);
        mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, 
                      labelX, labelY, 0x00AA3333, "-X");
    }
    
    transform_point(&rt_struct->scene.world.camera, 0, -1, 0, &nx, &ny, &nz);
    if (nz > 0) {
        project_point(&rt_struct->scene.world.camera, 0, -1.2, 0, &labelX, &labelY);
        mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, 
                      labelX, labelY, 0x0033AA33, "-Y");
    }
    
    transform_point(&rt_struct->scene.world.camera, 0, 0, -1, &nx, &ny, &nz);
    if (nz > 0) {
        project_point(&rt_struct->scene.world.camera, 0, 0, -1.2, &labelX, &labelY);
        mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, 
                      labelX, labelY, 0x003333AA, "-Z");
    }
}

/**
 * Draw a 3D cube around the axis to create a more robust orientation indicator
 */
void draw_orientation_cube(t_minirt *rt_struct)
{
    // Cube vertices (small cube around origin)
    float cube_size = 0.3;
    float vertices[8][3] = {
        {-cube_size, -cube_size, -cube_size},
        {cube_size, -cube_size, -cube_size},
        {cube_size, cube_size, -cube_size},
        {-cube_size, cube_size, -cube_size},
        {-cube_size, -cube_size, cube_size},
        {cube_size, -cube_size, cube_size},
        {cube_size, cube_size, cube_size},
        {-cube_size, cube_size, cube_size}
    };
    
    // Cube edges
    int edges[12][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0},  // bottom face
        {4, 5}, {5, 6}, {6, 7}, {7, 4},  // top face
        {0, 4}, {1, 5}, {2, 6}, {3, 7}   // connecting edges
    };
    
    // Project and draw each edge
    for (int i = 0; i < 12; i++) {
        int x1, y1, x2, y2;
        project_point(&rt_struct->scene.world.camera, 
                     vertices[edges[i][0]][0], vertices[edges[i][0]][1], vertices[edges[i][0]][2],
                     &x1, &y1);
        project_point(&rt_struct->scene.world.camera, 
                     vertices[edges[i][1]][0], vertices[edges[i][1]][1], vertices[edges[i][1]][2],
                     &x2, &y2);
        
        // Color based on which face this edge belongs to
        int color = 0x00888888;  // Default gray
        
        // Check if this edge is on a primary axis-aligned face
        if (i < 4) color = 0x003333AA;  // Z- face (darker blue)
        else if (i < 8) color = 0x000000FF;  // Z+ face (blue)
        else if (i == 8 || i == 11) color = 0x0033AA33;  // Y- face (darker green)
        else if (i == 9 || i == 10) color = 0x00AA3333;  // X- face (darker red)
        
        draw_line(&rt_struct->canva.canva, x1, y1, x2, y2, color);
    }
}

/**
 * Main function to draw the complete navigator
 * This should be called in your canva_loop function
 */
void draw_navigator(t_minirt *rt_struct)
{
    // Draw the axis lines
    draw_axis_navigator(rt_struct);
    
    // Draw the orientation cube
    draw_orientation_cube(rt_struct);
}
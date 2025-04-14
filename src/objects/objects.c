/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:45:40 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/14 01:16:29 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

t_object *create_object(void *data, t_obj_type type)
{
    t_object *obj = (t_object *)malloc(sizeof(t_object));
    if (!obj)
    {
        ft_printf("Error: Failed to allocate");
        exit(EXIT_FAILURE);
    }
    obj->type = type;
    obj->next = NULL;

    if (type == OBJ_SPHERE)
        obj->u_data.sphere = *(t_sphere *)data; 
    else if (type == OBJ_PLANE)
        obj->u_data.plane = *(t_plane *)data;
    else if (type == OBJ_TRIANGLE)
        obj->u_data.triangle = *(t_triangle *)data;
    else
    {
        ft_printf( "Error: Unknown type\n");
        exit(EXIT_FAILURE);
    }

    return obj;
}

t_object *create_axis(t_point position, double length, t_color color) {
    t_axis *axis = malloc(sizeof(t_axis));
    if (!axis) {
        perror("Failed to allocate memory for axis");
        return NULL;
    }
    axis->position = position;
    axis->length = length;
    axis->color = color;

    t_object *object = malloc(sizeof(t_object));
    if (!object) {
        perror("Failed to allocate memory for object");
        free(axis);
        return NULL;
    }
    object->type = OBJ_AXIS;
    object->u_data.axis = *axis;
    object->next = NULL;
    return object;
}
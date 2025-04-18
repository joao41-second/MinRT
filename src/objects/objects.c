/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:45:40 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/04 19:46:26 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

t_object *create_object(void *data, t_obj_type type)
{
    t_object *obj = (t_object *)ft_malloc(sizeof(t_object), NULL);
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
    else
    {
        ft_printf( "Error: Unknown type\n");
        exit(EXIT_FAILURE);
    }

    return obj;
}
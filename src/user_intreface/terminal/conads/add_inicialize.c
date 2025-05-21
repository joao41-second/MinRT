/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_inicialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:03:22 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/21 13:08:39 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minRT.h"
#include "../termianl_stuct.h"

t_element *cc_add_new_object_elemnt_type()
{
	t_element *element;
	element = ft_malloc(sizeof(t_element)*1, NULL);
	element->standard_element = NULL;
	element->opcion = NULL;
	ft_add_node(ft_strdup("SPHER"),&element->opcion );
	ft_add_node(ft_strdup("PLAN"),&element->opcion );
	ft_add_node(ft_strdup("TRIANG"),&element->opcion );
	element->opcion = ft_node_start(element->opcion);
	return (element);
}

t_comand *cc_add_new_object()
{
	t_comand *add_obj;
	add_obj =  ft_malloc(1*sizeof(t_comand), NULL);
	add_obj->name = "add";
	add_obj->func = NULL;
	ft_add_node(cc_add_new_object_elemnt_type(), &add_obj->element);
	add_obj->element = ft_node_start(add_obj->element);
	return (add_obj);
}

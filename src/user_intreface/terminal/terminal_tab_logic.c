/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_tab_logic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:12:42 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/21 13:27:08 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"
#include "termianl_stuct.h"

void ter_tab_logic(t_user_in data, char *str)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = 0;

	if(len == 0)
		while (data.term != NULL)
		{
			i++;
			term_change_color(data, data.term->content, 1, 20);
			data.term = data.term->next;			
		}

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:14:12 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/21 21:19:45 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../camera/keys.h"
#include "../../canvas/canvas.h"
#include "../../minRT.h"
#include "termianl_stuct.h"

void ter_exec_standar(t_comand *command)
{

}

void ter_exec(t_user_in *data,char *str)
{
	t_list_ *command;
	t_comand *command_contatn;

	command = data->term;
	while (command != NULL)
	{
		command_contatn = command->content;
		if(ft_strncmp(str, command_contatn->name, ft_strlen( command_contatn->name)) == 0)
			 (command_contatn->exec)(data,
					 command_contatn->viod1,
					 command_contatn->viod2,
					 command_contatn->viod3);

		command = command->next;
	}
}


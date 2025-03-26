/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:10:57 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/26 11:13:56 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minRT.h"

static double	parse_fraction(const char *str, int *i)
{
	double	fraction;
	double	result;

	fraction = 0.1;
	result = 0.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(str[*i]))
		{
			result += fraction * (str[*i] - '0');
			fraction *= 0.1;
			(*i)++;
		}
	}
	return (result);
}

static double	parse_integer(const char *str, int *i)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(str[*i]))
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

double	ft_atof(const char *str, char **endptr)
{
	int		i;
	int		sign;
	double	result;

	result = 0.0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = parse_integer(str, &i);
	result += parse_fraction(str, &i);
	if (endptr)
		*endptr = (char *)&str[i];
	return (result * sign);
}

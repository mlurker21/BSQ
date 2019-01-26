/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:12:33 by fhagrave          #+#    #+#             */
/*   Updated: 2018/08/27 18:27:37 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_atoi_mod(char *str, char *symb)
{
	int index;
	int result;

	result = 0;
	index = 0;
	if (str[0] == '-')
		error_msg();
	while (str[index] >= '0' && str[index] <= '9')
	{
		result *= 10;
		result += str[index] - '0';
		index++;
	}
	symb[0] = str[index++];
	symb[1] = str[index++];
	symb[2] = str[index];
	if (result == 0)
		error_msg();
	return (result);
}

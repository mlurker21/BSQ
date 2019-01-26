/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:00:27 by fhagrave          #+#    #+#             */
/*   Updated: 2018/09/09 21:00:28 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(char data)
{
	t_list *tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->next = NULL;
		tmp->data = data;
	}
	return (tmp);
}

void	ft_list_push_back(t_list **begin_list, char data)
{
	t_list *tmp;

	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_elem(data);
}

int		ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = begin_list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

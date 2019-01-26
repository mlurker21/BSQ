/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 22:15:11 by fhagrave          #+#    #+#             */
/*   Updated: 2018/09/09 22:15:16 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	create_table(int width, int length, int *arrayof01)
{
	int **table;
	int i;

	g_size[1] = 0;
	g_size[2] = 0;
	g_size[3] = 0;
	table = (int**)malloc(sizeof(int*) * length);
	i = 0;
	if (table)
	{
		while (i < length)
		{
			table[i] = (int*)malloc(sizeof(int) * width);
			i++;
		}
		fill_table1(table, arrayof01, width);
		fill_table2(table, arrayof01, length, width);
		fill_table3(table, arrayof01, length, width);
	}
}

int		*convert_to_0_1(void)
{
	int *arrayof01;
	int i;

	i = 0;
	arrayof01 = (int*)malloc(sizeof(int) * g_size[0]);
	if (arrayof01)
	{
		while (i < g_size[0])
		{
			if (g_array[i] == g_array_symb[0])
				arrayof01[i] = 1;
			else if (g_array[i] == g_array_symb[1])
				arrayof01[i] = 0;
			else if (g_array[i] == '\n')
				arrayof01[i] = 2;
			else
				error_msg();
			i++;
		}
	}
	return (arrayof01);
}

void	fun1(int fd_x, int len)
{
	char c;

	g_begin = NULL;
	read(fd_x, &c, 1);
	g_begin = ft_create_elem(c);
	if (fd_x == 0)
		while (len)
		{
			read(0, &c, 1);
			ft_list_push_back(&g_begin, c);
			if (c == '\n')
				len--;
		}
	else
	{
		while (read(fd_x, &c, 1))
			ft_list_push_back(&g_begin, c);
	}
	g_size[0] = ft_list_size(g_begin);
	g_array = NULL;
	g_array = (char*)malloc(sizeof(char) * g_size[0]);
}

void	fun2(int *length, int *width, int *fail)
{
	t_list	*tmp;
	int		i;
	int		width1;

	i = 0;
	width1 = 0;
	tmp = g_begin;
	if (g_array)
		while (i++ < (g_size[0]))
		{
			g_array[i - 1] = tmp->data;
			tmp = tmp->next;
			width1++;
			if (g_array[i - 1] == '\n')
			{
				(*length)++;
				if (*(width) == 0)
					*(width) = width1;
				else if (*(width) != width1)
					*fail = 1;
				width1 = 0;
			}
		}
	(*width)--;
	free(g_begin);
}

void	fun3(int width, int length)
{
	int *arr;
	int i;

	arr = convert_to_0_1();
	create_table(width, length, arr);
	draw_map(g_size[1], g_size[2], g_size[3], width);
	i = 0;
	while (i < g_size[0])
	{
		ft_putchar(g_array[i]);
		i++;
	}
}

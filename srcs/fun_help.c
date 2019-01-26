/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:58:08 by mlurker           #+#    #+#             */
/*   Updated: 2018/09/12 19:58:10 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		minimum(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (c <= b && c <= a)
		return (c);
	else
		return (b);
}

void	draw_map(int max, int i_max, int j_max, int width)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (max == 0)
	{
		ft_putstr_err("No solution\n");
		exit(1);
	}
	else
	{
		while (i < max)
		{
			while (j < max)
			{
				g_array[(i_max - i) * (width + 1) + (j_max - j)] =
				g_array_symb[2];
				j++;
			}
			j = 0;
			i++;
		}
	}
}

void	fill_table1(int **table, int *arrayof01, int width)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < width)
	{
		table[0][i] = arrayof01[i];
		if (table[0][j] > g_size[1])
		{
			g_size[1] = table[0][j];
			g_size[2] = 0;
			g_size[3] = j;
		}
		i++;
	}
}

void	fill_table2(int **table, int *arrayof01, int length, int width)
{
	int i;

	i = 1;
	while (i < length)
	{
		table[i][0] = arrayof01[(width + 1) * (i)];
		if (table[i][0] > g_size[1])
		{
			g_size[1] = table[i][0];
			g_size[2] = i;
			g_size[3] = 0;
		}
		i++;
	}
}

void	fill_table3(int **table, int *arrayof01, int length, int width)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < length)
	{
		while (j < width)
		{
			if (arrayof01[i * (width + 1) + j] == 0)
				table[i][j] = 0;
			else
				table[i][j] = minimum(table[i][j - 1], table[i - 1][j],
					table[i - 1][j - 1]) + 1;
			if (table[i][j] > g_size[1])
			{
				g_size[1] = table[i][j];
				g_size[2] = i;
				g_size[3] = j;
			}
			j++;
		}
		j = 1;
		i++;
	}
}

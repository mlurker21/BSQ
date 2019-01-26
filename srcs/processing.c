/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:53:39 by mlurker           #+#    #+#             */
/*   Updated: 2018/09/12 19:53:47 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	processing(int fd_x)
{
	int width;
	int length;
	int len;
	int fail;

	width = 0;
	length = 0;
	len = 0;
	fail = 0;
	len = read_first_line(fd_x);
	fun1(fd_x, len);
	fun2(&length, &width, &fail);
	if (len != length)
		error_msg();
	if (fail == 1 || (width < 1 || length < 1))
		error_msg();
	fun3(width, length);
}

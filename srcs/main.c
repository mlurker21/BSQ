/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:12:47 by fhagrave          #+#    #+#             */
/*   Updated: 2018/09/09 20:19:04 by kmedhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	error_msg(void)
{
	ft_putstr_err("map error\n");
	exit(1);
}

int		read_first_line(int fd_x)
{
	char	c;
	char	buff[15];
	int		i;
	int		len;

	i = 0;
	len = 0;
	read(fd_x, &c, 1);
	buff[i] = c;
	while (c != '\n' && i < 15)
	{
		i++;
		read(fd_x, &c, 1);
		buff[i] = c;
	}
	if (i < 15)
		len = ft_atoi_mod(buff, g_array_symb);
	else
		error_msg();
	return (len);
}

void	error(char *argv)
{
	write(2, "BSQ: ", 5);
	write(2, argv, ft_strlen(argv));
	write(2, ": ", 2);
	if (errno == 21)
		write(2, "Is a directory\n", 15);
	else if (errno == 2)
		write(2, "No such file or directory\n", 26);
	else if (errno == 13)
		write(2, "Permission denied\n", 18);
}

int		read_files(int argc, char **argv)
{
	int		i;
	int		fd;

	i = 0;
	while (++i < argc)
	{
		if ((fd = open(argv[i], O_RDWR)) == -1)
		{
			error(argv[i]);
			continue ;
		}
		processing(fd);
		close(fd);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		processing(0);
	else if (argc > 1)
		read_files(argc, argv);
	return (0);
}

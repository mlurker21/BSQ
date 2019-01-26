/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:53:30 by fhagrave          #+#    #+#             */
/*   Updated: 2018/09/09 20:53:32 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <errno.h>
# define BUF_SIZE 14000

typedef struct		s_list
{
	struct s_list	*next;
	char			data;
}					t_list;

void				ft_putchar(char a);
void				ft_putnbr(int nb);
void				ft_putstr(char *str);
int					ft_atoi_mod(char *str, char *symb);

t_list				*ft_create_elem(char data);
void				ft_list_push_back(t_list **begin_list, char data);
int					ft_list_size(t_list *begin_list);
int					read_first_line(int fd_x);

void				fun1(int fd_x, int len);
void				fun2(int *length, int *width, int *fail);
void				fun3(int width, int length);
void				check(char **array_rush, char *array,
					int	width, int length);

int					ft_strlen(char *str);
void				error_msg(void);
void				ft_putchar_err(char c);
void				ft_putstr_err(char *str);
void				processing(int fd_x);

int					minimum(int a, int b, int c);
void				draw_map(int max, int i_max, int j_max, int width);
void				fill_table1(int **table, int *arrayof01, int width);
void				fill_table2(int **table, int *arrayof01,
					int length, int width);
void				fill_table3(int **table, int *arrayof01,
					int length, int width);

t_list				*g_begin;
char				*g_array;
char				g_array_symb[3];
int					g_size[5];

#endif

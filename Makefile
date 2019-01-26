# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/09 20:36:04 by fhagrave          #+#    #+#              #
#    Updated: 2018/09/09 20:36:06 by fhagrave         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_BSQ = bsq

SRCS_BSQ = srcs/main.c \
	srcs/ft_putchar.c \
	srcs/ft_putnbr.c \
	srcs/ft_putstr.c \
	srcs/list.c \
	srcs/fun.c \
	srcs/ft_strlen.c \
	srcs/ft_atoi_mod.c \
	srcs/processing.c \
	srcs/fun_help.c

INCLUDE = includes

all: $(NAME_BSQ)

$(NAME_BSQ):
	@gcc -Wextra -Wall -Werror -o $(NAME_BSQ) $(SRCS_BSQ) -I $(INCLUDE)

fclean:
	@rm -f $(NAME_BSQ)

re: fclean all

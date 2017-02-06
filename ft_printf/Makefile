# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 13:52:42 by dprovorn          #+#    #+#              #
#    Updated: 2016/12/27 17:51:29 by dprovorn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = check.c check_f_array.c check_h_1.c check_h_2.c check_l_1.c \
	  check_other.c check_zj.c core.c ft_printf.c func.c func2.c \
	  get_data.c get_length.c hexa_work.c hexa_work2.c modify.c \
	  modify_str.c number_work.c octa_work.c octa_work2.c print.c \
	  print_str.c print_str2.c wchar_work.c wchar_work2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) -c $? $(SRC)
			@ar rc $(NAME) $? $(OBJ)
				@ranlib $(NAME)

clean:
		@/bin/rm -f $(OBJ)

fclean: clean
		@/bin/rm $(NAME)

re: fclean all

.PHONY: clean

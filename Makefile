# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 00:42:21 by aeddaqqa          #+#    #+#              #
#    Updated: 2019/08/05 20:25:59 by aeddaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = bonus.c main.c color.c draw_line.c color.c ft_check_file.c ft_free_tab.c\
		ft_split_whitespaces.c get_next_line.c guide.c outiles.c play.c rot.c\
		ft_atoi.c ft_putstr.c ft_strchr.c ft_strdel.c ft_strdup.c ft_strjoin.c\
		ft_strlen.c ft_strnew.c ft_strsub.c
INC = fdf.h
mlx1 = cc -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)
NAME = fdf

all : $(NAME)
$(NAME) : $(OBJ)
	$(mlx1) $^ -o $@ 
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all

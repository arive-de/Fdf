# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arive-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 16:10:03 by arive-de          #+#    #+#              #
#    Updated: 2017/01/11 16:51:53 by arive-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf 

SRC= ./srcs/algo_draw.c \
	./srcs/init_window.c \
	./srcs/main.c \
	./srcs/put_display_tab.c \
	./srcs/set_params.c

OBJ= $(subst .c,.o, $(SRC))

CC= gcc
CFLAGS= -Wall -Wextra -Werror
MLX= -lmlx -framework OpenGL -framework Appkit

LIBFT= ./libft/libft.a
LIBINC= -I libft/

INCDIR= -I includes/

$(NAME):
	make -C ./libft/
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MLX) $(INCDIR)

all: $(NAME)

clean:
	/bin/rm -rf $(OBJ)
	make -C libft fclean

fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf ./libft/libft.a
re: fclean all

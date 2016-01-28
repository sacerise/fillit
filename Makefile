# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/22 14:15:29 by sacerise          #+#    #+#              #
#    Updated: 2016/01/04 14:58:47 by sacerise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

LIB=libft/libft.a

INC=includes

CC=gcc

CFLAGS= -Wall -Wextra -Werror

RM=rm -f

OBJ=read.o ft_get_tetri.o main.o list_tetri.o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -o $@ $< -c

$(NAME): $(OBJ) $(LIB)
	$(CC) $+ -o $@

.PHONY: 
	clean fclean re all

clean:
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
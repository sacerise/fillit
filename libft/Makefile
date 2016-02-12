# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 15:08:43 by sacerise          #+#    #+#              #
#    Updated: 2015/12/04 15:26:52 by sacerise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=clang

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

OBJ=ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
ft_isdigit.o ft_isprint.o ft_itoa.o ft_memalloc.o \
ft_memcpy.o ft_memdel.o ft_memset.o ft_putchar.o \
ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o \
ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o \
ft_strcat.o ft_strchr.o ft_strcmp.o ft_strcpy.o ft_strdup.o \
ft_strequ.o ft_striter.o ft_strjoin.o ft_strlcat.o ft_strcmp.o \
ft_strncpy.o ft_strchr.o ft_strsub.o ft_strlen.o\
ft_tolower.o ft_toupper.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
ft_memcmp.o ft_memmove.o ft_strmap.o ft_strmapi.o ft_strequ.o \
ft_striter.o ft_striteri.o ft_strncat.o ft_strlcat.o ft_strnew.o \
ft_strdel.o ft_strclr.o ft_strtrim.o ft_atoi.o ft_strrchr.o ft_strncmp.o \
ft_strnstr.o ft_strstr.o ft_strsplit.o ft_strnequ.o

all: $(NAME)

%.o: %.c libft.h
		$(CC) $(CFLAGS) -o $@ $< -c

$(NAME): $(OBJ)
		ar rc $@ $+
		ranlib $@

.PHONY: clean fclean re all

clean:
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:
	$(MAKE) fclean 
	$(MAKE) all


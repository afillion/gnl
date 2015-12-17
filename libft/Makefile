# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afillion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 15:37:28 by afillion          #+#    #+#              #
#    Updated: 2015/12/03 18:38:44 by afillion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =  ft_strlcat.c \
	ft_lstiter.c \
	ft_memalloc.c \
	ft_lstmap.c \
	ft_lstadd_back.c \
	ft_putendl_fd.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_putnbr_fd.c \
	ft_strjoin.c \
	ft_memdel.c \
	ft_putstr_fd.c \
	ft_strclr.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strncpy.c \
	ft_strsplit.c \
	ft_putnbr.c \
	ft_toupper.c \
	ft_memchr.c \
	ft_strtrim.c \
	ft_isalnum.c \
	ft_putstr.c \
	ft_isascii.c \
	ft_lstdelone.c \
	ft_strdel.c \
	ft_isalpha.c \
	ft_isprint.c \
	ft_strsub.c \
	ft_striteri.c \
	ft_striter.c \
	ft_lstadd.c \
	ft_memcpy.c \
	ft_strchr.c \
	ft_putbase.c \
	ft_bzero.c \
	ft_strncmp.c \
	ft_strcmp.c \
	ft_strmap.c \
	ft_strnequ.c \
	ft_putchar.c \
	ft_memccpy.c \
	ft_iswhitespace.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strequ.c \
	ft_putchar_fd.c \
	ft_isdigit.c \
	ft_memcmp.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_tolower.c \
	ft_lstdel.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strnstr.c \
	ft_putendl.c \
	ft_lstnew.c \
	ft_strcat.c \
	ft_strnew.c \
	ft_strcpy.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

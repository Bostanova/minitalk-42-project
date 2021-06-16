# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eerika <eerika@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 19:28:25 by eerika            #+#    #+#              #
#    Updated: 2021/06/14 19:28:26 by eerika           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libft.a

INCLUDE = libft.h

SRC =	ft_isdigit.c ft_isspace.c \
		ft_putchar.c ft_putstr.c \
		ft_putnbr.c ft_putendl.c \
		ft_atoi.c
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(SRC) $(OBJ) $(INCLUDE)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
		gcc $(FLAG) -c $< -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
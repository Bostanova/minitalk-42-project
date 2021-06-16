# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eerika <eerika@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 19:28:33 by eerika            #+#    #+#              #
#    Updated: 2021/06/14 19:28:34 by eerika           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR		=libft/
LIB			=libft.a

SERVER		=server
SERVER_SRC	=server.c
SERVER_OBJ	=$(SERVER_SRC:.c=.o)

CLIENT		=client
CLIENT_SRC	=client.c
CLIENT_OBJ	=$(CLIENT_SRC:.c=.o)

FLAGS		= -Wall -Wextra -Werror
HEADER		=minitalk.h

%.o:				%.c $(HEADER)
						@gcc $(FLAGS) -I$(LIB_DIR) -c $< -o $(<:.c=.o)
all:				$(SERVER) $(CLIENT)

$(SERVER):			$(LIB_DIR)$(LIB) $(SERVER_OBJ)
						@gcc $(SERVER_OBJ) -I$(LIB_DIR) -L$(LIB_DIR) -lft $(MLXFLAGS) -o $(SERVER)
$(CLIENT):			$(LIB_DIR)$(LIB) $(CLIENT_OBJ)
						@gcc $(CLIENT_OBJ) -I$(LIB_DIR) -L$(LIB_DIR) -lft $(MLXFLAGS) -o $(CLIENT)

$(LIB_DIR)$(LIB):	$(LIB_DIR)
						make -C $(LIB_DIR) all

clean:
						rm -rf $(CLIENT_OBJ) $(SERVER_OBJ)
						make -C $(LIB_DIR) clean

fclean:				clean 
						rm -rf $(SERVER) $(CLIENT)
						make -C $(LIB_DIR) fclean

re:					fclean all

.PHONY:				all clean fclean re
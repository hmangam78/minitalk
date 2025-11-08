# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 12:55:30 by hgamiz-g          #+#    #+#              #
#    Updated: 2025/11/08 10:54:03 by hgamiz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server

CLIENT_SRC = SRCS/client.c
SERVER_SRC = SRCS/server.c
COMMON_SRC = SRCS/minitalk.c

CLIENT_OBJ = SRCS/client.o
SERVER_OBJ = SRCS/server.o
COMMON_OBJ = SRCS/minitalk.o

LIBFT = libft/libft.a

# Include path
CFLAGS += -I./includes

# Rules
all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(COMMON_OBJ) $(LIBFT)
	@printf "🔗  Linking $(CLIENT)\n"
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJ) $(COMMON_OBJ) $(LIBFT)
	@printf "✅  Built $(CLIENT)\n"

$(SERVER): $(SERVER_OBJ) $(COMMON_OBJ) $(LIBFT)
	@printf "🔗  Linking $(SERVER)\n"
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJ) $(COMMON_OBJ) $(LIBFT)
	@printf "✅  Built $(SERVER)\n"

SRCS/client.o: SRCS/client.c includes/minitalk.h includes/libft.h
	@printf "⚙️   Compiling SRCS/client.c\n"
	$(CC) $(CFLAGS) -c SRCS/client.c -o SRCS/client.o

SRCS/server.o: SRCS/server.c includes/minitalk.h includes/libft.h
	@printf "⚙️   Compiling SRCS/server.c\n"
	$(CC) $(CFLAGS) -c SRCS/server.c -o SRCS/server.o

SRCS/minitalk.o: SRCS/minitalk.c includes/minitalk.h
	@printf "⚙️   Compiling SRCS/minitalk.c\n"
	$(CC) $(CFLAGS) -c SRCS/minitalk.c -o SRCS/minitalk.o

clean:
	rm -f SRCS/client.o SRCS/server.o SRCS/minitalk.o

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re

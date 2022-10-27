NAME	=	minitalk
CLIENT	=	client
SERVER	=	server

LIBFTPRINTF	=	libft/libftprintf.a
LIBFTPRINTF_DIR	=	libft

SRC_C	=	client.c
SRC_S	=	server.c
SRC_B_C =	./bonus/client_b.c
SRC_B_S =	./bonus/server_b.c

OBJ_S	=	server.o
OBJ_C	=	client.o
OBJ_B_C =	./bonus/client_b.o
OBJ_B_S =	./bonus/server_b.o

INC		=	minitalk.h

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

ifdef BONUS
	SER_OBJ 	= $(OBJ_B_S)
	CLI_OBJ 	= $(OBJ_B_C)
else
	SER_OBJ	= $(OBJ_S)
	CLI_OBJ	= $(OBJ_C)
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFTPRINTF) $(CLIENT) $(SERVER)


$(SERVER): $(SER_OBJ) $(INC)
	$(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(SER_OBJ)

$(CLIENT): $(CLI_OBJ) $(INC)
	$(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(CLI_OBJ)

$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR)

bonus:
	$(MAKE) BONUS=1 all

clean:
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	$(RM) $(OBJ_S) $(OBJ_C) $(OBJ_B_C) $(OBJ_B_S)

fclean: clean
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re bonus
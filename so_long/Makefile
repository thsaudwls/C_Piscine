NAME		= so_long
LIBFT		= libft/libft.a

INCLUDES = ./so_long.h

SRCS		= so_long.c \
			  image.c \
			  key_manipulation.c \
			  map_transform.c \
			  utils.c \
			  get_next_line.c \
			  get_next_line_utils.c \

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

define libft_call
		cd libft && $(MAKE) $(1) && cd ..
endef

define mlx_call
		cd mlx && $(MAKE) $(1) && cd ..
endef

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@

$(NAME)		:	$(OBJS) $(INCLUDES)
		$(call libft_call, all)
		$(call mlx_call, all)
		cc -o $(NAME) $(FLAGS) $(OBJS) -L ./libft -lft -L ./mlx -lmlx -framework OpenGL -framework AppKit

all			:	$(NAME)

clean		:
		cd libft && make clean && cd ..
		cd mlx && make clean && cd ..
		rm -f $(OBJS)

fclean		:
		cd libft && make fclean && cd ..
		cd mlx && make clean && cd ..
		rm -f $(NAME)
		rm -f $(OBJS)

re			:
		$(MAKE) fclean
		$(MAKE) all

.PHONY		:	all clean fclean re
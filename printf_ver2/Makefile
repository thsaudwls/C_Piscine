LIBFT	=	./libft/libft.a
NAME	=	libftprintf.a
RM		=	rm -f
LIB		=	ar rcu
CC		=	gcc
CFLAGS	=	-c -Wall -Wextra -Werror

SRCS	=	ft_printf_plus.c				\
			ft_printf.c
			
OBJS	=	$(SRCS:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJS)
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			$(CC) $(CFLAGS) -I. $(SRCS)
			$(LIB) $(NAME) $(OBJS)

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean	: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
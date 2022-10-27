NAME	=	libftprintf.a
RM		=	rm -f
AR		=	ar rcu
CC		=	gcc
CFLAGS	=	-c -Wall -Wextra -Werror

SRCS	=	ft_printf_plus.c 			\
			ft_printf.c \
			ft_atoi.c
			
OBJS	=	$(SRCS:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJS)
			$(CC) $(CFLAGS) -I. $(SRCS)
			$(AR) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
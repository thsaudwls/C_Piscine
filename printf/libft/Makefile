# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 20:26:46 by myson             #+#    #+#              #
#    Updated: 2022/05/17 20:47:52 by myson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAG = -Wall -Werror -Wextra

AR = ar rcs
RM = rm -rf

INCLUDES = ./libft.h

PART1 = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c
PART2 = ft_itoa.c ft_putchar_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
 		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_B = ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c

SRCS = $(PART1) $(PART2)

OBJS	= $(SRCS:.c=.o)

OBJS_B = $(SRC_B:.c=.o)

ifdef WITH_BONUS
	OBJFILE = $(OBJS) $(OBJS_B)
else
	OBJFILE = $(OBJS)
endif

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJFILE)
	$(AR) $(NAME) $(OBJFILE)

all : $(NAME)

clean :
	$(RM) $(OBJS_B) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus :
	make WITH_BONUS=1 all

.PHONY : all clean bonus fclean re

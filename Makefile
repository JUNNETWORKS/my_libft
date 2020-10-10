# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 04:46:14 by jtanaka           #+#    #+#              #
#    Updated: 2020/10/10 19:39:17 by jtanaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = libft.a
LIBH = libft.h
SRCS =	ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c
OBJS = $(SRCS:.c=.o)
HEADER = libft.h

.c.o:
	${CC} ${CFLAG} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

so:
	gcc -shared -o libft.so ${SRCS}

.PHONY: all clean fclean re
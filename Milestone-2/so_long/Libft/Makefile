# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 16:49:46 by vacuccu           #+#    #+#              #
#    Updated: 2025/05/05 08:43:52 by vacuccu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = \
       ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_atoi.c \
       ft_bzero.c \
       ft_memset.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strncmp.c \
	   ft_memchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_pchar.c \
	   ft_pnbr_base.c \
	   ft_pnbr_unsigned.c \
	   ft_pnbr.c \
	   ft_ppointer.c \
	   ft_printf.c \
	   ft_pstr.c \
	   get_next_line.c \

	   
       
       
       
	
OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} -c ${FLAGS} -I. $< -o $@

${NAME}:${OBJS}
	ar rc ${NAME} ${OBJS}


clean:
	rm -f ${OBJS}

fclean: clean
	rm -rf ${NAME}
re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 15:52:34 by vacuccu           #+#    #+#              #
#    Updated: 2025/04/02 17:50:40 by vacuccu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# nome libreria statica
NAME = libftprintf.a

# compilatore utilizzato
CC = cc

# condizioni di compilazione
CFLAGS = -Wall -Wextra -Werror

# regola per compilare tutto
all: ${NAME}

# fiole sorgenti da convertire in file oggetto
SRCS = \
		srcs/ft_printf.c \
		srcs/ft_pchar.c \
		srcs/ft_pnbr_unsigned.c \
		srcs/ft_pnbr.c \
		srcs/ft_pnbr_base.c \
		srcs/ft_pstr.c \
		srcs/ft_ppointer.c 

# regola di conversione
OBJS = $(SRCS:.c=.o)

# creazione libreria statica
$(NAME): $(OBJS)
		@ar rcs $(NAME) $(OBJS)
		@echo "Libreria $(NAME) creata!!!"

# creazione file oggetto
%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "File oggetto $@ creato!!!"

# pulizia file oggetto
clean:
		@rm -f $(OBJS)
		@echo "file oggetto rimossi!"

# pulizia di file oggetto e libreria
fclean: clean
		@rm -f $(NAME)
		@echo "Pulizia completa effettuata"

# ricompila il tutto
re : fclean all

# evita eventuali errori
.PHONY: all clean fclean re
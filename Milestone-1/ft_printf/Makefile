# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 15:52:34 by vacuccu           #+#    #+#              #
#    Updated: 2025/01/26 17:26:23 by vacuccu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# nome libreria statica
NAME = libftprintf.a

# compilatore utilizzato
CC = cc

# condizioni di compilazione
CFLAGS = -Wall -Wextra -Werror

# regola per compilare tutto
all: $(NAME)

# fiole sorgenti da convertire in file oggetto
SRCS = ft_printf.c ft_pchar.c ft_pnbr_unsigned.c ft_pnbr.c ft_strlen.c ft_pnbr_base.c ft_pstr.c ft_ppointer.c

# regola di conversione
OBJS = $(SRCS:.c=.o)

# creazione libreria statica
$(NAME): $(OBJS)
		@ar rcs $(NAME) $(OBJS)
		@echo "Libreria $(NAME) creata!!!"

# creazione file oggetto
%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

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
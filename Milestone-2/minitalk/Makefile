# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Librerie personalizzate
LIBFT_DIR = Libft
PRINTF_DIR = ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# File sorgenti
SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

# **************************************************************************** #
#                                COMPILAZIONE                                  #
# **************************************************************************** #

all: $(LIBFT) $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

# Compilazione client
$(NAME_CLIENT): $(OBJ_CLIENT) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF) $(LIBFT) -o $(NAME_CLIENT)

# Compilazione server
$(NAME_SERVER): $(OBJ_SERVER) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF) $(LIBFT) -o $(NAME_SERVER)

# Compilazione libft e ft_printf
$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

# Compilazione dei file .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************** #
#                                CLEANING                                      #
# **************************************************************************** #

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re

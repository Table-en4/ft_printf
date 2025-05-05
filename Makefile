#**************************************************************************** #
# #
# :: : :: :: :: ::#
#Makefile : + : : + : : + : #
#+ : + + : + + : + #
#By : molapoug < molapoug @student .42.fr> + # + + : ++# + #
#+ #+ #+ #+ #+ #+ + #+ #
#Created : 2025 / 04 / 10 18 : 33 : 56 by molapoug # + # # + # #
#Updated : 2025 / 04 / 13 17 : 05 : 10 by molapoug## # ########.fr #
# #
#**************************************************************************** #

#ft _printf / Makefile

NAME = ft_printf
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I../libft
TARGET = ft_printf.a

SRC = ft_printf.c utilis.c ft_printf_unsigned.c ft_printf_px.c
OBJ = $(SRC:.c=.o)
#LIBFT_DIR = ../libft
#LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME) $(TARGET)

$(TARGET): $(OBJ) $(LIBFT)
	ar rcs $@ $(OBJ)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(TARGET)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

NAME = push_swap
LNAME = ./libft/libft.a

LIBFT_DIR = ./libft/

SRC = main.c

OBJ = $(SRC:.c=.o)
INCLUDE = -I. -I$(LIBFT_DIR)
LIBFT = -L $(LIBFT_DIR) -lft

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INC)
LDFLAGS = -g3 -fsanitize=address
MAKE = make
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LNAME)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME) $(LIBFT)

$(LNAME):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)
	$(RM) tag

tag:
	ctags $(SRC) $(LIBFT_DIR)*.c

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
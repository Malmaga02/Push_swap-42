NAME = push_swap

CC = cc
HEADERS = ./libft/headers
CFLAGS = -Wextra -Werror -Wall -g -I$(HEADERS)
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)

LIBFT_DIR = ./libft

RESET = $(shell tput sgr0)
BOLD_TEXT = $(shell tput bold)
ITALIC_TEXT = $(shell tput sitm)
COLOUR_BLUE = \033[0;34m
COLOUR_GREEN = \033[0;32m

SRC =  ./src/algo.c \
		./src/find_bestmoves.c \
		./src/lis.c \
		./src/parsing.c \
		./src/push.c \
		./src/r-rotate.c \
		./src/rotate.c \
		./src/swap.c \
		./src/utils.c \
		./src/main.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@make all -s -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I. -I$(HEADERS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "	$(COLOUR_BLUE) $(BOLD_TEXT) Run ./push_swap with a series of numbers, and I'll sort them. $(RESET)"

clean:
	@make clean -s -C $(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all



# .SILENT:
.PHONY: all clean fclean re
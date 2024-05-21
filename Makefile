NAME = push_swap
NAME_BONUS = checker

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
		./src/minisort.c \
		./src/find_bestmoves.c \
		./src/lis.c \
		./src/parsing.c \
		./src/push.c \
		./src/r-rotate.c \
		./src/rotate.c \
		./src/swap.c \
		./src/algo_utils.c \
		./src/utils.c \
		./src/main.c 

SRC_BONUS = ./src/checker/checker_main.c \
			./src/checker/checker_parsing.c \
			./src/parsing.c \
			./src/checker/push.c \
			./src/checker/r-rotate.c \
			./src/checker/rotate.c \
			./src/checker/swap.c \
			./src/utils.c 


OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@make all -s -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I. -I$(HEADERS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "	$(COLOUR_BLUE) $(BOLD_TEXT) Run ./push_swap with a series of numbers, and I'll sort them. $(RESET)"

bonus: $(OBJ_BONUS)
	@make all -s -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I. -I$(HEADERS) $(OBJ_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)
	@echo "	$(COLOUR_BLUE) $(BOLD_TEXT) Run ./checker with a series of numbers, but this time you'll test your skills! $(RESET)"

clean:
	@make clean -s -C $(LIBFT_DIR)
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_BONUS)

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

re: fclean all bonus



# .SILENT:
.PHONY: all clean fclean re
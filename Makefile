NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = libft/libft.a
LIBFT_PATH = ./libft

FILES_P = main \

FILES_R = 
		
PARS_DIR = ./src/parsing/
RAYC_DIR = ./src/raycast/

OBJS_DIR = ./objet/

SRCS_P = $(addprefix $(PARS_DIR), $(addsuffix .c, $(FILES_P)))
SRCS_E = $(addprefix $(EXEC_DIR), $(addsuffix .c, $(FILES_E)))

OBJS_P = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_P)))
OBJS_E = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_E)))

GREEN = \033[1;32m
BLUE =  \033[1;34m
RED = \033[1;31m
NC = \033[0m

OBJ = $(OBJS_P) $(OBJS_E) $(OBJS_B)

# Création des .o pour les fichiers généraux
$(OBJS_DIR)%.o: $(PARS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(OBJS_DIR)%.o: $(EXEC_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(NAME): $(LIBFT) $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lm
	@echo "$@ : $(BLUE)[READY]$(NC)"

$(LIBFT):
	@make -C $(LIBFT_PATH) all

all: $(NAME)

clean:
	@$(RM) -rf $(OBJS_DIR)
	@make -C $(LIBFT_PATH) clean
#@clear
	@echo "$(RED)============== [OBJECT DELETED] ==============$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean
#@clear
	@echo "$(RED)========== [ OBJECT / EX DELETED ] ==========$(NC)"

re: fclean all
	@echo "\n$(BLUE)================= [ START ] =================$(NC)\n"
	@./$(NAME)

test: fclean all
	@valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=./readline.supp   --child-silent-after-fork=no --track-fds=yes ./$(NAME)

.PHONY: all clean fclean re

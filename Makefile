NAME = cub3d

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

MLX = minilibx-linux
MLX_FLAGS = -L$(MLX) -lmlx_Linux -L/usr/bin -lX11 -lXext -lm -lbsd

HEADER = includes/cub3d.h

GREEN = \033[1;32m
BLUE =  \033[1;34m
RED = \033[1;31m
NC = \033[0m

LIBFT = libft/libft.a
LIBFT_PATH = ./libft

FILES_P = main \
		verif_args \
		asset \
		asset_init \
		print \
		map_init \
		map_utils \
		data_init \
		free \
		end \
		texture_init

FILES_C =

P_DIR = ./src/parsing/
C_DIR = ./src/casting/

FILE_P.C = $(addsuffix .c, $(FILES_P))
FILES_C.C = $(addsuffix .c, $(FILES_C))

SRC_P = $(addprefix $(P_DIR), $(FILE_P.C))
SRC_C = $(addprefix $(C_DIR), $(FILES_C.C))

SRCS_OBJ = $(addprefix $(OBJ_DIR), $(FILE_P.C:.c=.o)) \
		   $(addprefix $(OBJ_DIR), $(FILES_C.C:.c=.o))

OBJ_DIR = obj/

all: lib $(NAME)

$(OBJ_DIR)%.o: $(P_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(OBJ_DIR)%.o: $(C_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(NAME): $(SRCS_OBJ)
	@$(CC) $(CFLAGS) $(SRCS_OBJ) $(LIBFT) -o $(NAME) $(MLX_FLAGS)
	@echo "$@ : $(BLUE)[READY]$(NC)"

lib:
	@make -C $(LIBFT_PATH)
	@make -C $(MLX)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX) clean
	@echo "$(RED)============== [OBJECT DELETED] ==============$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX) clean
	@echo "$(RED)========== [ OBJECT / EX DELETED ] ==========$(NC)"

re: fclean all
	@echo "\n$(BLUE)================= [ START ] =================$(NC)\n"
	@./$(NAME)

.PHONY: all clean fclean re lib

NAME			:= cub3d
NAME_BONUS		:= cub3d_bonus

CC				:= cc
CFLAGS			:= -Wall -Werror -Wextra -g3

MLX				:= minilibx-linux
MLX_FLAGS		:= -L$(MLX) -lmlx_Linux -L/usr/bin -lX11 -lXext -lm -lbsd

# Includes
INC				:= -Iincludes

LIBFT			:= libft/libft.a
LIBFT_PATH		:= ./libft

# Colors
GREEN			:= \033[1;32m
BLUE			:= \033[1;34m
RED				:= \033[1;31m
NC				:= \033[0m

# Directories
SRC_DIR			:= src
CASTING_DIR		:= $(SRC_DIR)/casting
PARSING_DIR		:= $(SRC_DIR)/parsing
OBJ_DIR			:= obj

# Source files (without .c)
PARSING_FILES	:=	main \
					data/verif_args \
					asset/asset_init \
					asset/asset_get \
					asset/asset_verif \
					print/print \
					map/map_init \
					map/map_utils \
					map/map_verif \
					map/map_size \
					texture/create_img \
					texture/texture_init \
					data/data_init \
					free/free \
					player/player_init \
					

CASTING_FILES	:=	hooks \
					raycasting \
					raycasting_utils \
					movement \
					utils \
					utils2 \
					draw_wall \


# Source and object files
SRC_PARSING		:= $(addprefix $(PARSING_DIR)/, $(addsuffix .c, $(PARSING_FILES)))
SRC_CASTING		:= $(addprefix $(CASTING_DIR)/, $(addsuffix .c, $(CASTING_FILES)))
SRCS			:= $(SRC_PARSING) $(SRC_CASTING)
OBJS			:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(NAME)
	@rm -f $(NAME_BONUS)

$(NAME): $(OBJS) lib
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@ $(MLX_FLAGS)
	@echo "$@ : $(BLUE)[READY]$(NC)"


# Pattern rules for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"


lib:
	@make -C $(LIBFT_PATH)
	@make -C $(MLX)

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX) clean
	@echo "$(RED)============== [OBJECT DELETED] ==============$(NC)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX) clean
	@echo "$(RED)========== [ OBJECT / EX DELETED ] ==========$(NC)"

re: fclean all


.PHONY: all clean fclean re lib
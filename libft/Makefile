NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRC_FILES = srcs/ft_atoi.c \
			srcs/ft_atol.c \
			srcs/ft_atoll.c \
			srcs/ft_bzero.c \
			srcs/ft_calloc.c \
			srcs/ft_isalnum.c \
			srcs/ft_isalpha.c \
			srcs/ft_isascii.c \
			srcs/ft_isdigit.c \
			srcs/ft_isprint.c \
			srcs/ft_is_space.c \
			srcs/ft_isuppercase.c \
			srcs/ft_memchr.c \
			srcs/ft_memcmp.c \
			srcs/ft_memcpy.c \
			srcs/ft_memmove.c \
			srcs/ft_memset.c \
			srcs/ft_strchr.c \
			srcs/ft_strdup.c \
			srcs/ft_strlcat.c \
			srcs/ft_strlcpy.c \
			srcs/ft_strlen.c \
			srcs/ft_strcmp.c \
			srcs/ft_strncmp.c \
			srcs/ft_strnstr.c \
			srcs/ft_strrchr.c \
			srcs/ft_tolower.c \
			srcs/ft_toupper.c \
			srcs/ft_get_content.c

SRC_FILES_P2 =	srcs/ft_strjoin.c \
				srcs/ft_substr.c \
				srcs/ft_strtrim.c \
				srcs/ft_split.c \
				srcs/ft_itoa.c \
				srcs/ft_putchar_fd.c \
				srcs/ft_putstr_fd.c \
				srcs/ft_putendl_fd.c \
				srcs/ft_putnbr_fd.c \
				srcs/ft_print_tab_fd.c \
				srcs/ft_strmapi.c \
				srcs/ft_striteri.c

SRC_BONUS = srcs/ft_lstnew_bonus.c \
			srcs/ft_lstadd_front_bonus.c \
			srcs/ft_lstsize_bonus.c \
			srcs/ft_lstlast_bonus.c \
			srcs/ft_lstadd_back_bonus.c \
			srcs/ft_lstdelone_bonus.c \
			srcs/ft_lstclear_bonus.c \
			srcs/ft_lstmap_bonus.c \
			srcs/ft_lstiter_bonus.c \
			srcs/get_next_line_utils.c \
			srcs/get_next_line.c \
			srcs/ft_free_tab.c

SRC_PRINTF =	srcs/ft_printf/ft_printf.c \
				srcs/ft_printf/ft_hexa.c \
				srcs/ft_printf/ft_putstr_ct.c \
				srcs/ft_printf/ft_putnbr_ct.c \
				srcs/ft_printf/ft_putchar_ct.c \
				srcs/ft_printf/ft_putptr.c

SRC_FPRINTF =	srcs/ft_fprintf/ft_fprintf.c \
				srcs/ft_fprintf/ft_fhexa.c \
				srcs/ft_fprintf/ft_fputstr_ct.c \
				srcs/ft_fprintf/ft_fputnbr_ct.c \
				srcs/ft_fprintf/ft_fputchar_ct.c \
				srcs/ft_fprintf/ft_fputptr.c

SRCS = $(SRC_FILES) $(SRC_FILES_P2) $(SRC_BONUS) $(SRC_PRINTF) $(SRC_FPRINTF)

SRC_HEADER = includes/libft.h includes/get_next_line.h

OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(SRC_HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
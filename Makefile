NAME		= fdf

LIBFT_PATH	= ./libs/libft
LIBFT_INC	= $(LIBFT_PATH)/includes
LIBFT		= $(LIBFT_PATH)/libft.a

CFLAGS		= -g3 -Wall -Werror -Wextra
LFLAGS		= -lft -lmlx -lX11 -lXext -lm

LIBS		= -L$(LIBFT_PATH)

INCLUDES	= -I./includes -I$(LIBFT_INC)

SRC_DIR		= ./src/
SRC_LIST	= fdf.c fdf_utils.c map.c draw.c draw_utils.c draw_rotate.c draw_menu.c color.c controls.c
SRC			= $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJS_DIR	= ./objects/
OBJS_LIST	= $(patsubst %.c, %.o, $(SRC_LIST))
OBJS		= $(addprefix $(OBJS_DIR), $(OBJS_LIST))

#colors
GRENN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	@gcc $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBS) -o $(NAME)
	@echo " $(CYAN)$(NAME): $(GRENN)Done!"
	@echo -n "$(RESET)"

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -sC $(LIBFT_PATH) clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -sC $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
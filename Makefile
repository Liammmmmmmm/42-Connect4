NAME = connect4
SRC_DIR = src
BUILD_DIR = .build
INCLUDE_DIR = include

FILES =	$(addprefix $(SRC_DIR)/, \
	main.c \
	put_usage.c \
	init/init_game.c \
	display/display_grid.c \
	destroy/destroy_game.c \
)

OBJS = $(addprefix $(BUILD_DIR)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_DIR)/, $(FILES:.c=.d))

LIBFT_DIR = libft
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/include
LIBFT_ARCHIVE = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_ARCHIVE)
LIBFT_NAME = ft

INCLUDE_FLAGS = $(addprefix -I, $(INCLUDE_DIR) $(LIBFT_INCLUDE_DIR))
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -MD -MP $(INCLUDE_FLAGS)

MAKEFLAGS = --no-print-directory

.PHONY: all clean fclean re $(LIBFT)

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -l$(LIBFT_NAME)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	rm -f $(NAME)
	rm -rf $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean
	$(MAKE) all

-include $(DEPS)

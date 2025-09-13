
BUILD_TYPE_FILE = .build_type.mk
CONFIG_FILE = config.mk
SOURCES_FILE = sources.mk
MAKEFLAGS += --no-print-directory

-include $(BUILD_TYPE_FILE)
-include $(CONFIG_FILE)
-include $(SOURCES_FILE)

BUILD_TYPE_TARGET ?= main

PROJECT_NAME = Libft
NAME = libft.a
BUILD_ROOT_DIR = .build
BUILD_DIR = $(BUILD_ROOT_DIR)/$(BUILD_TYPE_TARGET)
HEADER_DIR = include

OBJS = $(addprefix $(BUILD_DIR)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_DIR)/, $(FILES:.c=.d))

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP -I$(HEADER_DIR)

DEV_DEFINE = -DDEV
DEV_FLAGS = $(DEV_DEFINE) -g3

TEST_NAME = tester
TEST_FILES = main.test.c
TEST_FLAGS = $(CFLAGS) $(DEV_FLAGS)
TEST_OBJS = $(addprefix $(BUILD_DIR)/, $(TEST_FILES:.c=.o))
TEST_DEPS = $(addprefix $(BUILD_DIR)/, $(TEST_FILES:.c=.d))

LOG_PROJECT_NAME = $(DARK_GREY)\[$(BOLD)$(BLUE)$(PROJECT_NAME)$(RESET)$(DARK_GREY):$(BOLD)$(PINK)$(BUILD_TYPE_TARGET)$(RESET)$(DARK_GREY)\]

.PHONY: all clean fclean re test tester dev FORCE

all: $(NAME)
	@echo -e $(LOG_PROJECT_NAME) $(BOLD)$(YELLOW)Builded$(RESET) $(BOLD)$(RED)$(NAME) $(DARK_GREY)\(v$(VERSION)\)$(RESET)

ifneq ($(BUILD_TYPE),$(BUILD_TYPE_TARGET))
$(NAME): $(OBJS) FORCE
else
$(NAME): $(OBJS)
endif
	@ar rcs $(NAME) $(OBJS)
	@echo BUILD_TYPE = $(BUILD_TYPE_TARGET) > $(BUILD_TYPE_FILE)
	@echo -e $(LOG_PROJECT_NAME) $(BOLD)$(YELLOW)Adding$(RESET) objects to $(BOLD)$(RED)$(NAME)$(RESET)

dev:
	@$(MAKE) CFLAGS="$(TEST_FLAGS)" BUILD_TYPE_TARGET=dev

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo -e $(LOG_PROJECT_NAME) $(BOLD)$(YELLOW)Compiling$(RESET) with : $(BOLD)$(LIGHT_GREY)$(CC) $(DARK_GREY)$(CFLAGS) $(GREEN)$<$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_ROOT_DIR)
	@echo -e $(LOG_PROJECT_NAME) $(BOLD)$(YELLOW)Cleaned $(RESET)objects

fclean: clean
	@rm -f $(BUILD_TYPE_FILE)
	@rm -f $(NAME)
	@rm -f $(TEST_NAME)
	@echo -e $(LOG_PROJECT_NAME) $(BOLD)$(YELLOW)Cleaned $(RED)$(NAME)$(RESET)

re: fclean 
	@$(MAKE) all

$(TEST_NAME): dev
	@$(MAKE) -s $(TEST_OBJS) CFLAGS="$(TEST_FLAGS)"
	@$(CC) $(TEST_FLAGS) $(TEST_OBJS) $(NAME) -o $(TEST_NAME)

test: $(TEST_NAME)
	@./$(TEST_NAME)
	@rm $(TEST_NAME)

-include $(DEPS)

BLACK		= '\e[38;5;16m'
RED			= '\e[38;5;196m'
GREEN		= '\e[38;5;46m'
YELLOW		= '\e[38;5;226m'
BLUE		= '\e[38;5;87m'
PINK		= '\033[38;5;213m'
DARK_GREY	= '\e[38;5;237m'
LIGHT_GREY	= '\e[38;5;253m'
WHITE		= '\e[38;5;255m'

BOLD		= '\033[1m'
UNDERLINE	= '\033[4m'

RESET		= '\033[0m'

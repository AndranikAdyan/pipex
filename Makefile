MAKEFLAGS	+= --no-print-directory

RED				= \e[31m
GREEN			= \e[32m
YELLOW			= \e[33m
CYAN			= \e[36m
RESET			= \e[0m

NAME			= pipex

LIBFT_DIR		= libs/libft

LIBFT			= -L./$(LIBFT_DIR) -lft

INCLUDES		= -I./includes -I./$(LIBFT_DIR)

HEADERS			= ./includes/pipex.h

CC				= cc

FLAGS			= -Wall -Wextra -Werror

SRC_DIR			= ./src

SRC				= $(shell find $(SRC_DIR) -name "*.c")

OBJ				= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

BUILD_DIR		= ./build

all: build lib $(NAME)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS) Makefile
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "  ✅ ${GREEN}$<${RESET}"

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(LIBFT) $(MLX)
	@echo "$(YELLOW)Pipex Done!$(RESET)"

lib:
	@make -C $(LIBFT_DIR)

build:
	@mkdir -p ${BUILD_DIR}

clean:
	@echo "🗑  ${RED}Remove Object Files...${RESET}"
	@rm -rf $(BUILD_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "🗑  ${RED}Remove Executable Files...${RESET}"

re: fclean all

echo:
	@echo $(OBJ)

.PHONY: all lib build clean fclean
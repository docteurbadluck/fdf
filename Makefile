CC = cc

LIBX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm
LIBFT = -Llibft -lft

CFLAGS = -Wall -Wextra -Werror

SRC = srcs/main.c \
srcs/init.c srcs/array_of_str_to_int.c \
srcs/print_any_array.c srcs/free_any_array.c \
srcs/valid_input.c srcs/any_test_on_str_array.c \
srcs/from_file_to_array.c srcs/same_number_of_column_in_array.c \
srcs/point.c srcs/print.c srcs/draw_line.c srcs/point_2d.c


HEADERS = includes/fdf.h
BUILD_DIR = build

# Liste des fichiers objets avec le répertoire build
OBJ_FILES = $(SRC:srcs/%.c=$(BUILD_DIR)/%.o)

NAME = $(BUILD_DIR)/fdf

# Règle par défaut pour créer l'exécutable
all: lib $(BUILD_DIR) $(NAME) 
	

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBX) $(LIBFT) -o $(NAME)

# Règle pour compiler un fichier .c en .o dans build/
$(BUILD_DIR)/%.o: srcs/%.c $(HEADERS)
	$(CC) -c $< -o $@

# Nettoyage des fichiers objets dans build/
lib:
	@make -C libft > /dev/null 2>&1
	@make -C minilibx-linux > /dev/null 2>&1

clean:
	rm -f $(OBJ_FILES)

# Nettoyage complet (objets + exécutable dans build/)
fclean: clean
	rm -f $(NAME)

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re
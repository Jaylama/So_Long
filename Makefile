HEADER = so_long.h map.h LIBFT/libft.h GNL/get_next_line.h 

NAME = so_long.out

SRC = $(SRC_MAIN) $(SRC_UTILS) $(SRC_MAP) $(SRC_GAME)

SRC_MAIN = main.c start.c 

SRC_UTILS = $(addprefix GNL/, $(GNL)) $(addprefix LIBFT/, $(LIBFT)) errors.c

GNL = get_next_line.c get_next_line_utils.c

LIBFT = ft_strtrim.c libftxtras.c ft_strchr.c ft_strdup.c ft_strcpy.c ft_substr.c ft_strlen.c ft_memcpy.c ft_calloc.c ft_strjoin.c ft_bzero.c ft_memset.c

SRC_MAP = read_map.c map_checker.c valid_path.c generate_tilemap.c 

SRC_GAME = draw_map.c open_imgs.c end_pgrm.c input.c

OBJ = *.o

FLAGS = -Wall -Wextra -Werror -g

KEYCODES = -D$(ESC) -D $(W) -D $(A) -D $(S) -D $(D) -D $(R) 

MACINC = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

LINUXINC = -I/usr/include -Imlx -O3 -Lmlx -lmlx -L/usr/lib -lXext -lX11 -lm -lz

INCLUDE =

UNAME := $(shell uname -s)

all: $(NAME)

header: 
	gcc $(HEADER)

ifeq ($(UNAME),Darwin)
ESC = KEY_ESC=53
W = KEY_W=13
A = KEY_A=0
S = KEY_S=1
D = KEY_D=2
R = KEY_R=15
$(NAME): $(OBJ)
	@echo "  - Compiling $(NAME)..."
	gcc $(FLAGS) -fsanitize=address $(OBJ) $(MACINC) -o $(NAME)
else ($(UNAME),Linux)
ESC = KEY_ESC=65307
W = KEY_W=119
A = KEY_A=97
S = KEY_S=115
D = KEY_D=100
R = KEY_R=114
$(NAME): $(OBJ)
	@echo "  - Compiling $(NAME)..."
	gcc $(FLAGS) -fsanitize=address $(OBJ) $(LINUXINC) -o $(NAME)
else
	@echo "Error: not compatible with OS"
endif

$(OBJ): $(SRC)
	@echo "  - Making object files..."
	gcc $(FLAGS) $(KEYCODES) -c $(SRC)

clean:
	@echo "  - Removing object files..."
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME) *.gch
	
re: fclean all

norm: 
	norminette $(SRC) *.h

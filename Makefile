NAME = cub3D
 
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# all mlx shit
MLXDIR = ./miniLibX
MLX_FLAGS = -framework OpenGL -framework AppKit

MLX_INC = $(MLXDIR)
MLX_LIB = $(addprefix $(MLXDIR)/,libmlx.a)

## libft shit
LIBFTDIR = ./libft

LIBFT_LIB = $(addprefix $(LIBFTDIR)/,libft.a)
LIBFT_INC = $(LIBFTDIR)
LIBFT_FLAGS = -L $(LIBFTDIR)

## cub shit
CUB_INC = ./includes
CUBSRCDIR = ./src
OBJDIR = ./obj
#CUB_SRCS := $(shell find ./src -name "*.c")
CUB_SRCS = start.c\
			events.c\
			init.c

OBJ = $(addprefix $(OBJDIR)/,$(CUB_SRCS:.c=.o))

all: obj $(LIBFT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(CUBSRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(MLX_INC) -I $(LIBFT_INC) -I $(CUB_INC) -o $@ -c $<

$(LIBFT_LIB):
	@make -C $(LIBFTDIR)

$(MLX_LIB):
	@make -C $(MLXDIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)

clean:
	rm -rf $(NAME)
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all
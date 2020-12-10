cc := gcc

mlx_weird_flags := -framework OpenGL -framework AppKit

mlx_lib := ./lib/libmlx.a
c_warn_flags := -Wall -Wextra -Werror

cub_include := ./includes/
cub_srcs := $(shell find . -name "*.c")

all_includes := -I$(mlx_include) -I$(minirt_include) 
executable := $(shell find . -name "cub3D")

cub3D:	$(cub_srcs) $(cub_include)
	@echo "FUCK THIS SHIT"
	$(cc) $(all_includes) $(cub_srcs) $(mlx_lib) $(mlx_weird_flags) -o $@

clean: $(executable)
	rm $<

exec:
	$(shell ./cub3D)

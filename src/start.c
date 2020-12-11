#include "get_next_line.h"
#include "libft.h"
#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "init_del.h"

#define WIN_WIDTH 1024
#define WIN_HEIGHT 1000

int		err_err(char *s)
{
	ft_putstr(s);
	exit(1);
}

t_map		*parse_map(char *file)
{
	t_map *map;
	int fd;
	
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);

	if ((map = (t_map *)ft_memalloc(sizeof(t_map))) == NULL)
		return (NULL);
	return (map);
}

int             main(int argc, char *argv[])
{
	t_map *map;
	t_mlx *mlx;

	if (argc < 2)
		return (err_err("error: not enough arguments\nusage: ./wolf3d [map]"));
	if ((mlx = my_init_mlx()) == NULL)
		return (err_err("error: couldn\'t init mlx\n"));
	if ((map = parse_map(argv[1])) == NULL)
		return (err_err("exited from parsing map\n"));
	mlx->map = map;
}
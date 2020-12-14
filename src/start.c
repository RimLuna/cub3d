#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>


#define WIN_WIDTH 1024
#define WIN_HEIGHT 1000

int		err_err(char const *s)
{
	ft_putstr(s);
	exit(EXIT_FAILURE);
}

int             main(int argc, char *argv[])
{
	t_cub	cub;

	if (argc < 2)
		return (err_err("error: not enough arguments\nusage: ./cub3D [map]\n"));
	init(&cub);
	if (parse_file(argv[1], &cub.conf) == 0)
		return (err_err("error: parsing map file went wrong.\n"));
}

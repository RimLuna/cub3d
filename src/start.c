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

int		err_err(char const *s)
{
	ft_putstr(s);
	exit(EXIT_FAILURE);
}

int		check_ext(char *file)
{
	int	len;
	int ext_len;

	len = ft_strlen(file);
	ext_len = ft_strlen(".cub");
	if (len < ext_len)
		return (0);
	return (!ft_strcmp(file + len - ext_len, ".cub"));
}

int		parse_file(char *file, t_cub *cub)
{
	int fd;
	char *line;

	cub = NULL;
	if (!check_ext(file))
		return (0);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &line))
	{
		printf(line);
		free(line);
	}
	return (1);
}

int             main(int argc, char *argv[])
{
	t_cub	cub;

	if (argc < 2)
		return (err_err("error: not enough arguments\nusage: ./cub3D [map]\n"));
	init(&cub);
	if (parse_file(argv[1], &cub) == 0)
		return (err_err("error: parsing map file went wrong.\n"));
}

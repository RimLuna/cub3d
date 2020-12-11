#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int		err(char *s)
{
	ft_putstr(s);
	return (1);
}

int             main(int argc, char *argv[])
{
    int fd;
	char *line;
	int ret;

	if (argc < 2)
		return (err("error: not enough arguments\nusage: ./wolf3d [map]"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
                return (err("error: couldn\'t open file\n"));
	while ((ret = get_next_line(fd, &line)))
    {
		printf("%s\n", line);
	}
    // m.mlx = mlx_init();
    // m.win = mlx_new_window(m.mlx, 1920, 1080, "Kill me");
    // set_controls(&m);
    // mlx_loop(m.mlx);
}
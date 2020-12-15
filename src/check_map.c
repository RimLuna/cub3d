#include "cub3d.h"

int		count_columns(char const *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '1')
			j++;
		else if (line[i] != ' ')
			return (0);
		i++;
	}
	return (j);
}

int		check_top_bottom_borders(t_buf *map_buf)
{
	int		first_line;
	int		last_line;
	t_buf	*last;

	if (!map_buf)
		return (0);
	first_line = count_columns(map_buf->str);
	last = ft_buf_last(map_buf);
	printf("\nFIRST ::::::: %d\n\n", first_line);
	printf("\nLAST ::::::: %d\n\n", count_columns(last->str));

	if (last)
		last_line = count_columns(last->str);
	else
		last_line = 0;
	if (first_line == last_line)
		return (first_line);
	ft_putstr("\nFFF CHECKED\n");
	return (0);
}

int		check_left_right_borders(t_buf *map_buf)
{
	int				i;
	int				first;
	int				last;

	if (!map_buf)
		return (0);
	i = 0;
	printf("\nlen map buf::::%d\n", ft_buf_len(map_buf));
	while (map_buf)
	{
		first = 0;
		while (map_buf->str[first] == ' ')
			first++;
		last = ft_strlen(map_buf->str) - 1;
		while (last > 0 && map_buf->str[last] == ' ')
			last--;
		printf("first: %d\n", first);
		printf("last:%d\n", last);
		printf("first char:%c\n", map_buf->str[first]);
		printf("last char:%c\n", map_buf->str[last]);
		printf("line:%s\n", map_buf->str);

		if (last <= 1
			|| map_buf->str[first] != '1'
			|| map_buf->str[last] != '1')
			return (0);
		ft_putstr("LEFTRIGHT\n\n");
		map_buf = map_buf->next;
		i++;
	}
	return (i);
}

int		is_map_valid(t_conf *conf, t_buf *map_buf)
{
	int i;
	int col;

	while (map_buf)
	{
		i = 0;
		col = 0;
		while (map_buf->str[i])
		{
			if (!is_in(map_buf->str[i], " 01234NSEW"))
				return (0);
			if (map_buf->str[i++] != ' ')
				col++;
		}
		if (col != conf->columns)
			return (0);
		map_buf = (map_buf->next);
	}
	return (1);
}
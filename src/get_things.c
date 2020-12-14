#include "cub3d.h"

int		get_key(char const *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (R);
	else if (line[0] == 'N' && line[1] == 'O')
		return (NO);
	else if (line[0] == 'S' && line[1] == 'O')
		return (SO);
	else if (line[0] == 'W' && line[1] == 'E')
		return (WE);
	else if (line[0] == 'E' && line[1] == 'A')
		return (EA);
	else if (line[0] == 'S' && line[1] == 'T')
		return (ST);
	else if (line[0] == 'F' && line[1] == 'T')
		return (FT);
	else if (line[0] == 'S' && line[1] == ' ')
		return (S);
	else if (line[0] == 'S' && line[1] == 'U')
		return (SU);
	else if (line[0] == 'S' && line[1] == 'C')
		return (SC);
	else if (line[0] == 'F' && line[1] == ' ')
		return (F);
	else if (line[0] == 'C' && line[1] == ' ')
		return (C);
	return (MAP);
}


int		get_text_i(int key)
{
	if (key == NO)
		return (TEX_NORTH);
	else if (key == SO)
		return (TEX_SOUTH);
	else if (key == WE)
		return (TEX_WEST);
	else if (key == EA)
		return (TEX_EAST);
	else if (key == ST)
		return (TEX_SKY);
	else if (key == FT)
		return (TEX_FLOOR);
	else if (key == SU)
		return (TEX_SPRITE_UP);
	else if (key == SC)
		return (TEX_SPRITE_C);
	return (TEX_SPRITE);
}

char	*get_path(int start, char const *line)
{
	int i;
	int end;
	char *path;

	i = start;
	if (!line)
		return (NULL);
	while (line[start] && line[start] == ' ')
		start++;
	end = ft_strlen(line);
	while (line[end] == ' ')
		end--;
	if (start == i || end - start <= 0 || !(path = ft_substr(line, start, end - start)))
		return (NULL);
	return (path);
}

int		get_params(t_conf *conf, char const *line, t_buf **map_buf)
{
	int key;
    static int empty_line_map = 0;
    static int content_after = 0;
    int len_line;

	len_line = ft_strlen(line);
	if (len_line == 0 && conf->keys[MAP])
		empty_line_map = 1;
	if (empty_line_map && content_after)
		return (0);
	if (len_line == 0)
		return (1);
	key = get_key(line);
	if (key != MAP && (conf->keys[key] || conf->keys[MAP]))
		return (0);
	if (key == R)
		return (parse_dim(conf, line));
	else if (key >= NO && key <= ST)
		return (parse_text(conf, key, line));
	else if (key == F || key == C)
		return (parse_color(conf, key, line));
	conf->keys[key] = 1;
	if (empty_line_map)
		content_after = 1;
	return (!(!ft_buf_add(map_buf, ft_strdup(line))));
}


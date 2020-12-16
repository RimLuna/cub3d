#include "cub3d.h"

int		parse_dim(t_conf *conf, char const *line)
{
	int i;
	int useless;
	t_buf	*buf;
	t_buf	*param;

	i = -1;
	while (line[++i])
		if (line[i] != ' ' && line[i] < '0' && line[i] > '9')
			return (0);
	buf = NULL;
	if (!(buf = ft_split_buf(line, ' ')) || ft_buf_len(buf) != 3)
		return (ft_buf_clear(&buf));
	param = buf->next;
	useless = ft_atoi(param->str);
	if (useless <= 1)
		return (ft_buf_clear(&buf));
	conf->requested_width = useless;
	//printf("\n%d\n", conf->requested_width);
	param = param->next;
	useless = ft_atoi(param->str);
	if (useless <= 1)
		return (ft_buf_clear(&buf));
	conf->requested_height = useless;
	//printf("\n%d\n", conf->requested_height);
	return (ft_buf_clear(&buf) | 1);
}

int		parse_text(t_conf *conf, int key, char const *line)
{
	char *text_path;
	int text_i;

	text_i = get_text_i(key);
	if (conf->text_path[text_i])
	{
		free(conf->text_path[text_i]);
		conf->text_path[text_i] = NULL;
	}
	if (!(text_path = get_path((text_i == TEX_SPRITE) ? 1 : 2, line)))
		return (0);
	conf->text_path[text_i] = text_path;
	//printf("\n%s\n", conf->text_path[text_i]);
	return (1);
}

static int		buf_to_color(t_buf *buf)
{
	int i;
	int color;
	int tmp;

	i = 0;
	color = 0;
	while (buf)
	{
		tmp = ft_atoi(buf->str);
		if (tmp < 0 || tmp > 255)
			return (-1);
		color = color | (tmp << (16 - (i++ * 8)));
		buf = buf->next;
	}
	return (color);
}

int     is_in(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (c);
		i++;
	}
	return (0);
}

int		parse_color(t_conf *conf, int key, char const *line)
{
	int i;
	int color;
	t_buf	*tmp[2];

	i = 1;
	while (line[i])
		if (!is_in(line[i++], " ,1234567890"))
			return (0);
	tmp[0] = NULL;
	tmp[1] = NULL;
	tmp[0] = ft_split_buf(line, ' ');
	//printf("\nTMP 0 : %p\n", tmp[0]);
	//printf("\nBUFLEN  0  :%d\n\n", ft_buf_len(tmp[0]));
	//tmp[1] = ft_split_buf(tmp[0]->next->str, ',');
	//printf("\nTMP 1 : %p\n", tmp[1]);
	//ft_putstr(tmp[1]->str);
	//printf("\nBUFLEN  0  :%d\n\n", ft_buf_len(tmp[1]));

	if (!tmp[0] || ft_buf_len(tmp[0]) != 2
		|| !(tmp[1] = ft_split_buf(tmp[0]->next->str, ','))
		|| ft_buf_len(tmp[1]) != 3)
		return (ft_buf_clear(&tmp[0]) || ft_buf_clear(&tmp[1]));
	//ft_putstr("HHHHHHHHHHHHHHHHHHHH\n");
	if ((int)((color = buf_to_color(tmp[1]))) < 0)
		return (ft_buf_clear(&tmp[0]) || ft_buf_clear(&tmp[1]));
	key = (key == F) ? TEX_FLOOR : TEX_SKY;
	conf->text_set[key] = color;
	//printf("\n%x\n", conf->text_set[key]);

	return ((ft_buf_clear(&tmp[0]) || ft_buf_clear(&tmp[1])) | 1);
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

int		skip_spaces(char *s)
{
	int i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t'))
		i++;
	return (i);
}

int		skip_spaces_back(char *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t') && i > 0)
		i--;
	return (i);
}
int 	check_map_chars(char *s)
{
	int i;

	i = 0;
	while (s[i])
		if (!is_in(s[i++], " 012NSEW\t"))
			return (0);
	return (1);
}

int		check_map(t_buf *map_buf)
{
	while (map_buf)
	{
		int start;
		int end;
		int actual_len;

		start = skip_spaces(map_buf->str);
		if ((end = skip_spaces_back(map_buf->str)) < 2)
			return (0);
		//printf("\nline:: %s\nfirst:: %d\nlast:: %d\n", map_buf->str, start, end);
		if (!check_map_chars(map_buf->str))
			return (0);
		if (map_buf->str[end] != '1' || map_buf->str[start] != '1')
			return (0);
		actual_len = end - start + 1;
		//printf("\nline:: %s\nlen:: %d\nfirst:: %c\nlast:: %c\n", map_buf->str, actual_len, map_buf->str[start], map_buf->str[end]);
		map_buf =  map_buf->next;
	}
	return (1);
}

int 	parse_map(t_conf *conf, t_buf *map_buf)
{
	if (!check_map(map_buf))
		return (0);
	while (map_buf)
	{
		ft_putstr(map_buf->str);
		ft_putstr("\n");
		map_buf =  map_buf->next;
	}
	return (1);
}
int		parse_file(char *file, t_conf *conf)
{
	int fd;
	char *line;
	int r;
	t_buf *map_buf;
	t_buf *tnp;

	if (!check_ext(file))
		return (0);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	map_buf = NULL;
	r = 1;
	while (get_next_line(fd, &line) > 0)
	{
		r = (r && get_params(conf, line, &map_buf));
		free(line);
	}
	if (!r || !parse_map(conf, map_buf))
		return (ft_buf_clear(&map_buf));
	close(fd);
	ft_buf_clear(&map_buf);
	return (1);
}
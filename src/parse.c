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
	printf("\n%d\n", conf->requested_width);
	param = param->next;
	useless = ft_atoi(param->str);
	if (useless <= 1)
		return (ft_buf_clear(&buf));
	conf->requested_height = useless;
	printf("\n%d\n", conf->requested_height);
	return (ft_buf_clear(&buf));
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
	printf("\n%s\n", conf->text_path[text_i]);
	return (1);
}

int		buf_to_color(t_buf *buf)
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
	if (!(tmp[0] = ft_split_buf(line, ' ')) || ft_buf_len(tmp[0]) != 2
		|| !(tmp[1] = ft_split_buf(tmp[0]->next->str, ','))
		|| ft_buf_len(tmp[1]) != 3)
		return (ft_buf_clear(&tmp[0]) || ft_buf_clear(&tmp[1]));
	if ((int)((color = buf_to_color(tmp[1]))) < 0)
		return (ft_buf_clear(&tmp[0]) || ft_buf_clear(&tmp[1]));
	key = (key == F) ? TEX_FLOOR : TEX_SKY;
	conf->text_set[key] = color;
	printf("\n%x\n", conf->text_set[key]);

	return (ft_buf_clear(&tmp[0]) || ft_buf_clear(&tmp[1]));
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

int		parse_file(char *file, t_conf *conf)
{
	int fd;
	char *line;
	int r;
	t_buf *map_buf;

	if (!check_ext(file))
		return (0);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	map_buf = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		r = get_params(conf, line, &map_buf);
		free(line);
	}
	return (1);
}
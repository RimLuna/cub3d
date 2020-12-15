#ifndef CUB3D_H
# define CUB3D_H

# define TEXTURES			9

# include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# include "get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "events.h"
# include "keys.h"
# include "struct.h"
# include "libft.h"
# include "macro.h"

void            init_config(t_conf *conf);
void        	zero_vec(t_vec *vector);
void		    init(t_cub *cub);

int		get_key(char const *line);
int		get_text_i(int key);
char	*get_path(int start, char const *line);
int		get_params(t_conf *conf, char const *line, t_buf **map_buf);

int		check_ext(char *file);
//int		buf_to_color(t_buf *buf);

int		parse_color(t_conf *conf, int key, char const *line);
int		parse_dim(t_conf *conf, char const *line);
int		parse_text(t_conf *conf, int key, char const *line);
int		parse_file(char *file, t_conf *conf);

int		count_columns(char const *line);
int		check_top_bottom_borders(t_buf *map_buffer);
int		is_map_valid(t_conf *conf, t_buf *map_buf);
int		check_left_right_borders(t_buf *map_buf);

int		parse_map(t_conf *conf, t_buf *map_buf);

int		map_cpy(t_conf *conf, t_buf *map_buf, int *map);
#endif
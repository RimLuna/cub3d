#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"
# include "macro.h"

typedef struct s_vec {
	float		x;
	float		y;
} t_vec;

typedef struct s_buf
{
	char	*str;
	struct s_buf *next;
} t_buf;

typedef struct	s_camera
{
	t_vec	pos;
	t_vec	dir;
	t_vec	x_dir;
	t_vec	plane;
}				t_camera;

typedef struct  s_window {
	void		*mlx;
	void		*win;
	t_vec		size;
	double		ratio;
}               t_window;

typedef struct s_conf {
	int			requested_height;
	int			requested_width;
	int			*map;
	int			rows;
	int			columns;
	double		rotate_speed;
	double		move_speed;
	char		*text_path[TEXTURES];
	unsigned	text_set[TEXTURES];
	int			keys[LAST];
	double		fov;
} t_conf;

typedef struct s_cub {
	t_conf		conf;
	t_window	window;
	t_vec		pos;
	t_camera	cam;
	t_vec		move;
	t_vec		x_move;
	t_vec		rotate;
} t_cub;

int				ft_buf_len(t_buf *buf);
t_buf			*ft_buf_add(t_buf **buf, char *str);
t_buf			*ft_buf_last(t_buf *buf);
int				ft_buf_clear(t_buf **buf);
t_buf   		*ft_split_buf(char const *s, char splitter);

#endif
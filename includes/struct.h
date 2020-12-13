#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vec {
	float		x;
	float		y;
} t_vec;

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
	//unsigned	c[TEXTURES];
	//int			set[C_LAST];
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

#endif
#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vec {
	float		x;
	float		y;
} t_vec;

typedef struct s_map {
	int			w;
	int			h;
	int			**val;
} t_map;

typedef struct s_player {
	float		x;
	float		y;
	t_vec		d;
	t_vec		p;
} t_player;

typedef struct  s_mlx {
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	player;
}               t_mlx;


#endif
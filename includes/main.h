#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "key_macos.h"

typedef struct s_vec
{
	double x;
	double y;
} t_vec;

typedef struct s_player 
{
	t_vec pos;
	t_vec dir;
} t_player;

typedef struct s_info
{
	void *mlx;
	void *win;
	t_vec pos;
	t_vec dir;
	t_vec cam_plane;
	double  move_speed;
	double  rot_speed;
} t_info;

#endif
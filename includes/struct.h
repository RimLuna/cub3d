#ifndef STRUCT_H
# define STRUCT_H

typedef struct  s_mlx {
	void                            *mlx;
	void                            *win;
}               t_mlx;

typedef struct s_all {
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double cameraX;
	double rayDirX;
	double rayDirY;
	double mapX;
	double mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;

} t_all;

#endif
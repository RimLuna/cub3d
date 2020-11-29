#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct s_vec
{
		double x, y;
} t_vec;

	//A basic struct for RGB color
typedef struct s_rgb
{
	uint8_t r, g, b;
} t_rgb;

#endif
#include "init_del.h"

void            init_config(t_conf *conf)
{
    int     i;
    
    conf->requested_height = 0;
    conf->requested_width = 0;

    conf->map = NULL;
    conf->rows = 0;
    conf->columns = 0;
    conf->rotate_speed = 0;
    conf->move_speed = 0;
    i = -1;
    while (i++ < TEXTURES)
        conf->text_path[i] = NULL;
    conf->requested_height = 0;
    conf->requested_height = 0;
    conf->fov = 0;
}

void        	zero_vec(t_vec *vector)
{
    vector->x = 0;
    vector->y = 0;
}


void		    init(t_cub *cub)
{
	init_config(&cub->conf);
	zero_vec(&cub->move);
	zero_vec(&cub->x_move);
	zero_vec(&cub->rotate);
}
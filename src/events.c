#include "../includes/cub3d.h"

void		close(int keycode, t_mlx *m)
{
    mlx_destroy_window(m->mlx, m->win);
}

void		key_press(int keycode, void *param)
{
    t_mlx *m;

    m = (t_mlx *)param;
    if (keycode == ESC)
    {
        mlx_destroy_window(m->mlx, m->win);
        exit(0);
    }
}

void		set_controls(t_mlx *m)
{
    mlx_hook(m->win, 2, 0, key_press, m);
	mlx_hook(m->win, 17, 0, close, m);
	//mlx_hook(m->win, 4, 0, mouse_press, m);
	//mlx_hook(m->win, 5, 0, mouse_release, m);
	//mlx_hook(m->win, 6, 0, mouse_move, m)
}
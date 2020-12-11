#include "init_del.h"

t_mlx           *mlxdel(t_mlx *mlx)
{
        if (!mlx)
                return (NULL);
        if (mlx->win != NULL)
                mlx_destroy_window(mlx->mlx, mlx->win);
        ft_memdel((void **)&mlx);
        return (NULL);
}

t_mlx		*my_init_mlx(void)
{
	t_mlx   *mlx;

    if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
        return (NULL);
    if ((mlx->mlx = mlx_init()) == NULL || (mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH,WIN_HEIGHT, "cub3D")) == NULL)
        return (mlxdel(mlx));
    mlx_loop(mlx->mlx);
    return (mlx);
}

void			init_player(t_player *player)
{
    player->d = (t_vec){1.0f, 0.0f};
    player->p = (t_vec){0.0f, 2.0f / 3.0f};
}
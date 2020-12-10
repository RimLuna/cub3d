#include "../includes/cub3d.h"

int             main(void)
{
    t_mlx m;

    m.mlx = mlx_init();
    m.win = mlx_new_window(m.mlx, 1920, 1080, "Kill me");
    set_controls(&m);
    mlx_loop(m.mlx);
} 
#ifndef EVENTS_H
# define EVENTS_H

#include "struct.h"

void		close(int keycode, t_mlx *m);
void		key_press(int keycode, void *param);
void		set_controls(t_mlx *m);

#endif

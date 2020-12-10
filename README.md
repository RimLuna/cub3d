# cub3d, wtf is the point of doing this
I hate this already, 
*this was stolen from our savior **https://lodev.org/cgtutor/raycasting.html***

## Displays a window
I'm too lazy to even fucking copy code and compile it, kill me, I am my own enemy

## following and never leading: an eternal struggle
*stolen from* **https://github.com/VBrazhnik/FdF/wiki/How-to-handle-mouse-buttons-and-key-presses%3F**

### Handling mouse buttons and key presses with Minilibx
**int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);**
#### To handle a key press
int x_event is 2.

for int (*funct)() use the following function:
```
int key_press(int keycode, void *param)
```
#### To handle a mouse button press
int x_event is 4.

for int (*funct)() use the following function:
```
int mouse_press(int button, int x, int y, void *param)
```
#### To handle a key release
int x_event is 3.

for int (*funct)() use the following function:
```
int key_release(int keycode, void *param)
```
#### To handle a mouse button release
int x_event is 5.

for int (*funct)() use the following function:
```
int mouse_release(int button, int x, int y, void *param)
```
#### To handle a mouse movement
int x_event is 6.

for int (*funct)() use the following function:
```
int mouse_move(int x, int y, void *param)
```
#### To handle a a red button (X button) press
int x_event is 17.

for int (*funct)() use the following function:
```
int close(void *param)
{
    (void)param;
    exit(0);
}
```
#### mouse button codes
```
Left button — 1
Right button — 2
Third (Middle) button — 3
Scroll Up — 4
Scroll Down — 5
Scroll Left — 6
Scroll Right — 7
```
#### Mask values for x_mask
**https://refspecs.linuxfoundation.org/LSB_1.3.0/gLSB/gLSB/libx11-ddefs.html**
### Key event controls
**https://github.com/qst0/ft_libgfx**
### I STILL HATE C
```
gcc -framework OpenGL -framework AppKit libmlx.a
```
#### hooking into events
```
mlx_hook(vars.win, 2, 1L<<0, close, &vars);
```
we register to the KeyPress event with the according KeyPressMask **1L<<0**. Now whenever we press a key, the window will be closed.

**Now, I guess I will start, maybe**
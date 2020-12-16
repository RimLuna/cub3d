# cub3d, wtf is the point of doing this
I hate this already, 
*this was stolen from our savior **https://lodev.org/cgtutor/raycasting.html***

### I STILL HATE C
**Now, I guess I will start, maybe**
## the fucking parser, parse my ass bitch, fuck graphics
we get a fucking disgusting file **.cub**, and are asked to parse it.
```
R 1920 1080
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

S ./path_to_the_sprite_texture
F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000002000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
why is this shit cancerous, like how fucking hard is it to give a nice file
## Fucking confused for fuck's sake about this map
the map is supposed to be closed for it to be valid, therefore surrounded by 1's.



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

# 18/3/24
- At Maud's. Started looking at the project, definitions of isometric and parallel projection, etc.

# 19/3/24
- At 42, started testing fdf samples (cannot move around, resize, etc.)
- Reading and taking notes about color concepts (bit depth, pixels, raster graphics, vector graphics, etc.)
- Downloaded minilibx `sources.tgz` to install => hassle
	- Copied X11 header files from `/System/Volumes/Data/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/` to a new folder `~/42/X11`, (+found Xshm.h on the web) modified them (replaced all "X11/*.h" with "*.h"), compiled the main with `gcc main.c -I/Users/fallan/42/X11/ -L. -lmlx -framework OpenGL -framework AppKit`. <br> Yields linker errors like: "  
		>"_XWindowEvent", referenced from:
      _mlx_int_wait_first_expose in libmlx.a(mlx_int_wait_first_expose.o)
  "_XkbKeycodeToKeysym", referenced from:
      _mlx_int_param_KeyRelease in libmlx.a(mlx_int_param_event.o)
      _mlx_int_param_KeyPress in libmlx.a(mlx_int_param_event.o)
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)"

	- Tried to use minilibx_macos: `make`, then `gcc mlxtest.c -L. -lmlx -framework OpenGL -framework AppKit`, but I get many errors:
		> In file included from mlxtest.c:2:
./mlx_int.h:24:3: error: unknown type name 'GLuint'
  GLuint        pixel_vshader;
		No error if only mlx.h though. Added [OpenGL headers](https://stackoverflow.com/questions/3907818/opengl-headers-for-os-x-linux) to mlx.h
- Started making a makefile based on [Minilibx guide by harm-smits/42Docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
- N.b.: commented out "#include mlx_int.h" in mlx.h of minilibx_macos, which I use in my Makefile
- Testing mlx: using the [guide](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html):
	- successfully opened a 640*480 Window named "Hello World!"

# 20/3/24
- Testing mlx by continuing to follow the harm-smits guide


# 22/3/24
- Back to work: testing mlx. Printing pixels, a square, a rectangle, in various colors !
- @Bgolding helped me find `man ./mlx.1`
- Reading man, tried to implement a mouse hook (to draw a yellow square), no success. Asked Copilot chat which helped me (suggested `mlx_hook(mlx_win, 4, 1L<<2, my_mlx_put_square_put, &params);`), but it segfaults when I click. Hard to find the code, looking into .m files...will read more of the guide next time.

# 25/3/24
- Gitignore: created Fdf/gitignore to ignore minilibx and added the gitignore to the main gitignore
- Reading harm-smits documentation, finding out about X11 event types

# 26/3/24
- Kevin @kly helped me make a working hook with my square_put function, so events work now
- Made a keycode correspondence table
- Working on making a triangle: made the triangle
- Working on making a hexagon

# 28/3/24
- hexagon underway, but I need to get to work on Fdf. Not a regular hexagon it seems btw
- Ok I need to work on the actual project. Back to reading about [isometric projection](https://en.wikipedia.org/wiki/Isometric_projection), in particular [rotation angles](https://en.wikipedia.org/wiki/Isometric_projection#Rotation_angles), and the [mathematics](https://en.wikipedia.org/wiki/Isometric_projection#Mathematics), bringing me to [rotation matrices](https://en.wikipedia.org/wiki/Rotation_matrix)
- Octant: think it might use the 7th (+-+), which is what the subject seems to be asking. But the isometric projection article gives matrices for the first
- Took a look at the libmath (math.h) and `man float`
- Advanced on input: wrote function to count lines, and integrated get_next_line to get all lines and store them in an array. Need to split them into individual characters and "atoi" them into a float map

# 2/4/24
- back to work
- Working on input: error management (line length). N.b.: heavy-handed input management not needed, as from subject:
> Rappelez-vous que le but de ce projet n’est pas de parser des cartes ! Toutefois, cela ne signifie pas que votre programme peut crasher, mais qu’on part du principe qu’une carte sera correctement formatée dans le fichier passé en paramètre.
- Managed to split input and fit it into a array of ints, but issues at the borders. To fix

# 4/4/24
- Summary: Makefile(s) mostly, to make underpinning libraries
- Slow today (increasing focus at the end of the day and evening)...but with Copilot I was able to make the nested makefile
- One thing that mattered was changing the order at line 37:
`$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)` instead of `$(NAME): $(OBJ) $(FT_PRINTF) $(LIBFT)`
- For `clean`, need rule for obj files of required libraries
- Silencing deprecation warnings:
	- in mlx Makefile, added `-DGL_SILENCE_DEPRECATION` to CFLAGS
	- in mlx_new_window.m, added:
```c
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
[[self openGLContext] setView:self];
#pragma clang diagnostic pop
```
around line 364 expression `[[self openGLContext] setView:self];`
- Added debugging and sanitizer rules to makefile
- Fixed the "issues at the borders" mentioned last time
- Started working on making a 3d coordinate map. Problem: passing info about # of columns and lines to another function in the map array. Issues implementing that without segfaulting etc.

# 5/4/24
- Discussion avec Mathis Guyot @Mguyot sur mon projet a chill valley
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
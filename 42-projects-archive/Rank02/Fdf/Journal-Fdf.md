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
- Redid my map with a linked list, not finished yet, but it shortens things quite a bit

# 8/4/24
- A bit of linked list programming in the train

# 9/4/24
- Linked list input handling finished
- Isometric projection: what I need to do:
	- Place the origin at the center of the map: divide window_length and window_heigth by 2
	- ...
- In the train: line between points (my_mlx_line_put)

# 11/4/24
- Back to work at 42
- Trying to print my isometric projection using the mlx. Not successful so far.
- Re-using the key handler as it worked well with mlxtest.c: seg fault caused by call to ft_isometric_transform. Maybe look at the pointer being passed as param ?

# 12/4/24
- Working on seg faults with my list(s) passed as parameters
- Spent hours on this, actually the issue was simply the function prototype, which had to be `int key_handler(int keycode, t_env *env)` to correctly pass on the parameter, while `int key_handler(t_env *env, int keycode)` didn't pass it on properly !!!
- In retrospect that the order of parameters is central should have made sense...

# 15/4/24
- Isometric transform modifies points (checked with print statements)
- Issue with input handling (0's apparently, not enough lines read with elem.fdf for instance)
- Need to print points, then verify if coordinates are well set (or upside down)
- Okay managed to print points with `mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);`
- Now need to scale points a bit, space them apart
- In train: playing with x_min, y_max, etc. but issues (see printf statements printing out the same value for each)

# 17/4/24
- Back to work
- Refactoring code (graph_handling_utils.c, graph_transformation_utils.c, ft_lstiter to apply the various transformations, etc.)
- Next: test ft_lstiter on isometric transform (syntax) => works but better not to use it

# 18/4/24
- Centering + zoom functions seems to work okay
- Now on to line drawing : managed to write a function that draws a line between two points
Need to test it with y1 > y2 !!
issue with (0, 150, 0, 50)
=> one approach found online: [Bresenham's line algorithm](https://classic.csunplugged.org/documents/activities/community-activities/line-drawing/line-drawing.pdf): couldn't implement it easily, decided to use the *Digital differential analyzer graphics algorithm*, copying a C++ implementation from [Wikipedia](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)). Seems to work well; edit: no it doesn't ! Maybe Bresenham is indeed simpler, see [implementation](https://www.javatpoint.com/computer-graphics-bresenhams-line-algorithm)
- Now need to collect the set of points between which a line must be drawn => not yet !

# 19/4/24
- Issue with Bresenham is that it only works in one octant. Need floating point numbers working version
for other octants. Go with DDA !
- Copied [the C version from GeeksForGeeks](https://www.geeksforgeeks.org/dda-line-generation-algorithm-computer-graphics/), adapted it to respect the Norm. In some places important to use new variable float (X, Y) instead of typecasting int (x1, y1)as float.
- Window handling: not much of an answer (for Window close event) in the mlx man, nor online mlx guide by Harm-Smits: asked Copilot chat which told me what to do => could've found it myself, in the events enum for minilibx (see Concepts-Fdf.md, Mac OS X supported events)
- Ok for ESC key, but resizing not natively supported by the minilibx it seems, so I don't think I'll do it
- Clearing window: works, but harder to reinitialize the env so I decided to let go this functionality
- Mouse handling: sort of works for one "mouse up" or "mouse down" but segfaults right after
- Key options: implemented RGB colors but cannot redraw, need to restart program
- Wrote a function to draw a line from point to point i + #columns but it doesn't work exactly; need to fix input handling at this stage

# 29/4/24
- Back to work (back from Prague)
- Fixed input handling (column length bug: `while (array[i + 1])` -> `while (array[i])`)
- Renamed files
- Issue with ft_printf on MacOS: replace with printf (careful to replace printf with ft_printf before handing in project!)
- Working on line drawing: blocked though. Discussion with Damian: try checking your line filling algorithm without the projection, i.e. flat from the top, just the grid with no altitude => yes !! right, I can see the algo's issues ! Damian also advises to check flood fil algo (google it with "fdf"). Idea: multiply distance between each grid point by a given factor, then use projection. Managed to fill the grid almost 100%, except for first "vertical" line on grid (0, 0) to (1, 0) in grid position notation (i.e. top left)
- Problem: doesn't work after projection. Maybe a better approach is space points, then projection. => used the "size" approach and removed zoom => boom something works.
- Center points works well, what I need to remove is the zoom

To do:
- replace printf with ft_printf before handing in project
- Norm
- reduce/resize window

# 30/4/24
- Tested against sample fdf, looking good: the sample doesn't output all lines in grid systematically so I likely won't fix it. Update: fixed it pretty much entirely (my function doesn't iterate to the end of the grid though)
- Working on color inputs ("0, 0x8010305" point coordinates as input), new function hex_to_color. Problem: atoi doesn't seem to work on hex values. Developed a function ft_hex_string_to_int for that, but it makes everything segfault so commented it out for now.

# 2/5/24
- Back to work (after IDIAP hackathon application and Bitcoin meetup taking a lot of time on Tuesday, Wednesday)
- Solved hex color input, and first "vertical" line of grid.
- Found better projection formula (on Stack Overflow)
- However, the last few "vertical" lines don't get printed
- Biggest problem: t1, t2 maps look like sh... compared to what the sample fdf program produces

# 3/5/24
- Refactoring (for Norm and readability, to help debug)
- t1, t2 looking slightly better
- Issue with unwanted diagonal lines being drawn between grid points
- Finally removed zoom functions + ft_graph_transformation, a few lines of code to compute `size` in ft_isometric_projection are enough.
- env->drawn apparently necessary to prevent segfault when pressing key multiple times (could be because point->list not reset properly with anchor everywhere ?)
- Issue with the split with pyramide (see /debug/split-fail-pyramide.bash): checked split on the string, it works. Issue is before. Note: should've known split is ok, it passed moulinette..

- Evening: fixed hex_string_to_int function to properly handle colors, removed rotation, now my t2 is almost good. Problem: right vertical border in blue for no reason. Need to remove it/change color.
- What I did: 
	- `ft_apply_zoom(env->point_list, 10);` to zoom in 10x
	-
	```c
	if (line_coordinates[0] == 990)
		ft_printf("printing edge point (%d,%d) to (%d,%d), with color %d\n", line_coordinates[0], line_coordinates[1], line_coordinates[2], line_coordinates[3], line_coordinates[6]);
	```
	To print out right border (0-99 so x * 10, e.g. 990 to get rightmost set of vertical lines, 980 to get the penultimate, etc.). Turquoise color code does appear (int 1044442, [hex #FEFDA](https://www.color-hex.com/color/0fefda)), and some too high numbers to convert to RGB color scheme  
- Stayed until midnight

# 4/5/24
- Saturday morning at 42
- Debugging last vertical lines
- Used `ft_draw_points` only: it looks like a problem with the input handling 
<br>=> created `1-border.fdf`:
>1,0xff0000	&emsp; 0 &emsp; 1,0xff0000<br>
>1,0xff0000	&emsp; 0 &emsp; 1,0xff0000<br>
>1,0xff0000	&emsp; 0 &emsp; 1,0xff0000<br>
>1,0xff0000	&emsp; 0 &emsp; 1,0xff0000<br>
=> solved by adding `|| '\n'` back to my ft_whitespace_to_space function ('\n' are irrelevant in my program, no need to treat them specially)

- Then segfault causing issue => because I commented out the `line_read = ft_whitespace_to_space(line_read);` lines in ft_examine_lines, causing the #columns not to be read correctly, leading to errors down the road

Testing maps:
- elem-fract.fdf and julia (500*500 elements) don't work (2-5 secs to count lines and columns). Unclear if too slow or infinite loop. Waited 2-3 minutes and nothing more.`
n.b.: mars.fdf works, window doesn't load immediately but when loaded, pressing a key immediately prints out the map
- Pentenegpos.fdf doesn't really look like what's asked
- elem2.fdf: normalized in the misc/fdf => maybe source of issue with elem-fract?
- pylone.fdf: both my fdf and the sample fdf recognize it as an irregular map

=> write normalizer
=> try to make function more efficient to see if largest maps work:
Instruments shows it is the call by ft_lstadd_back to ft_lstlast that takes 5min11s

- Fixed the linked list, tried it, then tried to shorten function for Norm (25lines) > seg fault, don't know why!

# 5/5/24
- Fixed input handling bug leading to segfault (by looking at previous commits and copying code from when it worked)
- Fixed vertical lines not being drawn (with same method, I had deleted some necessary code)
- Norm done: drawing.c, input_utils.c, projection_utils.c
- Norm to do: rewrite ft_line_put (malloc likely)
- Learning about memory management:
	- Copilot helped me, and also this article prompted my mind: https://geeksforgeeks.org/dynamically-allocate-2d-array-c/
	- the malloc of char ***split: it's a 3d array of size (sizeof(2d array) * #lines). Then each 2d array is malloced by ft_split
	- freeing char ***split: since ft_split is malloc-ed in one block of memory (`ret = (char **)ft_calloc(size + 1, sizeof(char *));`),
	we also free it as one block of memory, instead of character by character, even though the type is a 2d array, which allows us to access
	it using a double index: ret[i][j]. So char ***split is only freed by two calls to free: for each split i.e. each split[line], and globally
	with free(split)
- All good, memory partly looked at (need to test systematically with leaks), but projection problem with pentenegpos....need different projection algo it seems

- Implemented an x_axis rotation matrix (see https://m4nnb3ll.medium.com/fil-de-fer-fdf-the-first-graphical-project-at-42-the-network-5cce69203448 and https://en.wikipedia.org/wiki/Rotation_matrix)


# 6/5/24
- In the train: working on rotation matrices + orthographic projection


- Also, weird issues coming up, lines drawn diagonally between points...
- Seg fault with old isometric projection...maybe leaks ? => heap buffer overflow

- At 42: used usleep and asked Copilot how to display line by line and point by point, => just
```c
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_do_sync(mlx);
    usleep(500000);
```

- Also added clear window functionality upon pressing 'c' or 'del'

- Finally solved the issue by asking Copilot for help with the projection and it said to use double instead of int
=> replacing all ints with doubles AND removing the orthographic projection, which was superfluous, solved the problem
for Pentenegpos !!! Finally !! Now on to memory management (and maybe line interpolation ?)

I realized the issue with orthographic projection by using the simplest map I had, my custom square.fdf:
0 0 0 0 0
0 1 1 1 0
0 1 1 1 0
0 1 1 1 0
0 0 0 0 0
 
// test_maps_fallan/square.fdf:
// input:
// pt 9 : (4.000000,1.000000), altitude 0.000000,
// 45 degrees = 0.785 radians
// z rotation:
// x' = (cos(0.785) * 4 - sin(0.785) * 1) == 2.12272789556
// y' = (sin(0.785) * 4 + cos(0.785) * 1) == 3.53468899359
// z' == 0

// x rotation:
// x' = x == 2.12272789556
// y' = cos(0.615) * 3.534 == 2.88647736135
// z' == sin(0.615) * 3.534 == 2.03897141776

// orthographic projection:
// x == 2.12272789556
// y == 2.88647736135
// z == 2.03897141776

// x' = 2.122 - 2.886 == -0.764
***// y' = (2.122 + 2.886) / (2 - 2.03897141776) == -128.504434477***
=> this made an extreme value for no reason, so I read the wiki article and saw there was no need for an ortho projection,
so I tested my code without it and it worked !


# 7/5/24
- Looked at code with Filipo:
	- ft_free (from GNL): useless because pointer parameter is passed as value, need to pass by reference!
	- Understand your code ! What input does it take, structure, etc. !
	- Rename line_data to dimensions
	- #

- Looked at leaks with Hajar:
	- 0 leaks !!
	- Issues were:
		- in ft_free_array, j not reset to 0 when looping through i
		- didn't free dimensions (ex line_data)

	- Notes:
		- add -g3 flags to sanitizer
		- set freed pointers to NULL (security reasons, see [how2heap on github](https://github.com/shellphish/how2heap) for exploits)

- To do Fdf:
	- Check leaks intel Macs: ok
	- Center graph again: ok (done manually)
	- Norm: Floriano helped me with header (and Makefile) Norm
	- Interpolation ?
	- Zoom ?

# 10/5/24
- Note for future housekeeping: project pushed from "fixing_projection" branch, then worked some more on my Macbook main branch, I think.
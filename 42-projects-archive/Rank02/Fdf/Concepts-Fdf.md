# Fdf (Fil de Fer) concepts

# Descriptive geometry
> [Descriptive geometry](https://en.wikipedia.org/wiki/Descriptive_geometry) is the branch of geometry which allows the representation of three-dimensional objects in two dimensions by using a specific set of procedures.

## Projections
### [Parallel projection](https://en.wikipedia.org/wiki/Parallel_projection)
> In three-dimensional geometry, a parallel projection (or axonometric projection) is a projection of an object in three-dimensional space onto a fixed plane, known as the projection plane or image plane, where the rays, known as lines of sight or projection lines, are parallel to each other. It is a basic tool in descriptive geometry. The projection is called orthographic if the rays are perpendicular (orthogonal) to the image plane, and oblique or skew if they are not.
> A perspective projection of an object is often considered more realistic than a parallel projection, since it more closely resembles human vision and photography. However, parallel projections are popular in technical applications, since the parallelism of an object's lines and faces is preserved, and direct measurements can be taken from the image. Among parallel projections, orthographic projections are seen as the most realistic, and are commonly used by engineers.

### [Isometric projection](https://en.wikipedia.org/wiki/Isometric_projection)
> Isometric projection is a method for visually representing three-dimensional objects in two dimensions in technical and engineering drawings. It is an axonometric projection in which the three coordinate axes appear equally foreshortened and the angle between any two of them is 120 degrees.
> The term "isometric" comes from the Greek for "equal measure", reflecting that the scale along each axis of the projection is the same (unlike some other forms of graphical projection).

[From Stack Overflow](https://stackoverflow.com/a/28614357) (a question on Fdf, clearly):
> For isometric projection I suggest you try the following instead:

```
u = x*cos(α) + y*cos(α+120°) + z*cos(α-120°)
v = x*sin(α) + y*sin(α+120°) + z*sin(α-120°)
```
> although for C you'll have to convert to radians. α will rotate your view, choose however you want to align stuff. If you choose α as a multiple of 30° you'll get fairly nice numbers involving just a simple square root.

Used the following (produces hard to differentiate one from my previous) [from SE](https://gamedev.stackexchange.com/a/159473):
>Suppose your 2D coordinates are x' and y', and your 3D coordinates are x , y and z.
>To convert 3D coordinated to a 2D isometric projection you use the following formulae:<br>
>x' = (x-z)/ sqrt(2)<br>
>y' = (x + 2y + z) / sqrt(6)<br>



### Fitting the projection in the window (centering the projection and zooming in to see it properly)
- Two constraints:
0. Centering the grid:
#columns / 2
#lines / 2

then points are transformed to be 

1. Fitting the grid:
	1.1 before rotation:<br>
		- #columns * zoom_factor must < WINDOW_WIDTH<br>
		- &&<br>
		- #line * zoom_factor must < WINDOW_WIDTH<br>
		=> `while (#columns * zoom_factor < WINDOW_WIDTH && #lines * zoom_factor < WINDOW_WIDTH) {zoom_factor++;} zoom_factor--;`
	2.1 after rotation:<br>
- 

## Rotation
### [Rotation matrices](https://en.wikipedia.org/wiki/Rotation_matrix)
> The two-dimensional case is the only non-trivial (i.e. not one-dimensional) case where the rotation matrices group is commutative, so that it does not matter in which order multiple rotations are performed.

> In two dimensions, the classic rotation matrix has the form: $$\begin{bmatrix}
cos(θ) & sin(θ)\\
-sin(θ) & cos(θ)
\end{bmatrix}$$


# Colouring
## [Bit depth](http://preservationtutorial.library.cornell.edu/tutorial/intro/intro-04.html)
> The number of bits used to define each pixel. The greater the bit depth, the greater the number of tones (grayscale or color) that can be represented. Digital images may be produced in black and white (bitonal), grayscale, or color:
> - A *bitonal image* is represented by pixels consisting of 1 bit each, which can represent two tones (typically black and white), using the values 0 for black and 1 for white or vice versa.
> - A *grayscale image* is composed of pixels represented by multiple bits of information, typically ranging from 2 to 8 bits or more.
> - A *color image* is typically represented by a bit depth ranging from 8 to 24 or higher. With a 24-bit image, the bits are often divided into three groupings: 8 for red, 8 for green, and 8 for blue. Combinations of those bits are used to represent other colors. A 24-bit image offers 16.7 million (2^24) color values.
### [Bits per channel](https://www.cambridgeincolour.com/tutorials/bit-depth.htm)
The bit depth for each primary color. The **bits per pixel (bpp)** refers to the sum of the bits in all three color channels and represents the total colors available at each pixel. 
### Choosing bit depth
> the human eye can only discern about 10 million different colors, so saving an image in any more than 24 bpp is excessive if the only intended purpose is for viewing. On the other hand, images with more than 24 bpp are still quite useful since they hold up better under post-processing.
### Common names
| Bits per pixel | Number of colors available | 		Common name(s)			|
| :------------: | :------------------------: | :-----------------------------: |
|		1		 |				2			  |			Monochrome 				|
|		2		 |				4			  | EGA (Enhanced Graphics Adapter) |
|		4		 |				16			  | VGA (Video Graphics Array)		|
|		8		 |				256			  | XGA, High Color					|
|		16		 |				65536		  | SVGA, True Color				|
|		24		 |				16777216	  | 
|		32		 |	162777216 + Transparency  |
|		48		 |				281 Trillion  |

# [X Window System](https://en.wikipedia.org/wiki/X_Window_System)
> The X Window System (**X11** or simply **X**) is a windowing system for bitmap displays, common on Unix-like operating systems. It has been at version 11 since 1987 (hence "X11"). FOSS software (MIT license). It is an architecture-independent system for remote graphical uer interfaces and input device capabilities. Each person using a networked terminal has the ability to interact with the display with any type of user input device. It provides the basic framework for a GUI environment: drawing and moving windows on the display device and interacting with a mouse and keyboard.

# [Bitmap](https://en.wikipedia.org/wiki/Bitmap)
A mapping from some domain (for example, a range of integers) to bits. It is also called a bit array or bitmap index. Very often used to refer to a particular bitmapping application, the **pix-map**, which refers to a map of [pixels](https://en.wikipedia.org/wiki/Pixel).

# [Raster graphics#](https://en.wikipedia.org/wiki/Raster_graphics)
(Whole article is not very long and quite interesting)
## Raster–vector conversion
> Vector images (line work) can be rasterized (converted into pixels), and raster images vectorized (raster images converted into vector graphics), by software. In both cases some information is lost, although certain vectorization operations can recreate salient information, as in the case of optical character recognition.

# [Vector graphics](https://en.wikipedia.org/wiki/Vector_graphics)
> - a form of computer graphics in which visual images are created directly from geometric shapes defined on a Cartesian plane, such as points, lines, curves and polygons.
> - Vector graphics are based on the mathematics of analytic or coordinate geometry, and is not related to other mathematical uses of the term vector. This can lead to some confusion in disciplines in which both meanings are used.
> - While vector hardware has largely disappeared in favor of raster-based monitors and printers,[2] vector data and software continues to be widely used, especially when a high degree of geometric precision is required, and when complex information can be decomposed into simple geometric primitives. Thus, it is the preferred model for domains such as engineering, architecture, surveying, 3D rendering, and typography, but is entirely inappropriate for applications such as photography and remote sensing, where raster is more effective and efficient. Some application domains, such as geographic information systems (GIS) and graphic design, use both vector and raster graphics at times, depending on purpose.

# [Minilibx/X11]
## [Events](https://tronche.com/gui/x/xlib/events/)
> [Note](https://harm-smits.github.io/42docs/libs/minilibx/events.html): On MacOS - Cocoa (AppKit) and OpenGL - version, minilibx has partial support of X11 events and doesn’t support X11 mask (x_mask argument of mlx_hook is useless, keep it at 0).

### Mac OS X supported events:
```c
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// usage:
mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
```

### Event types
#### [Exposure Events](https://tronche.com/gui/x/xlib/events/exposure/)
> The X protocol does not guarantee to preserve the contents of window regions when the windows are obscured or reconfigured. Some implementations may preserve the contents of windows. Other implementations are free to destroy the contents of windows when exposed. X expects client applications to assume the responsibility for restoring the contents of an exposed window region. (An exposed window region describes a formerly obscured window whose region becomes visible.) Therefore, the X server sends Expose events describing the window and the region of the window that has been exposed. A naive client application usually redraws the entire window. A more sophisticated client application redraws only the exposed region.
#### [Expose](https://tronche.com/gui/x/xlib/events/exposure/expose.html)
> The X server can report Expose events to clients wanting information about when the contents of window regions have been lost. The circumstances in which the X server generates Expose events are not as definite as those for other events.

### Event masks
no support with OpenGL + Cocoa (see above)

## MLX functions
`man ~/42/Fdf/lib/minilibx/man/man1/mlx_new_window.1`
### Window handling
SYNOPSYS
```c
	   void *
       mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

       int
       mlx_clear_window ( void *mlx_ptr, void *win_ptr );

       int
       mlx_destroy_window ( void *mlx_ptr, void *win_ptr );
```

DESCRIPTION
> The `mlx_new_window  ()` function creates a new window on the screen, using the size_x and size_y parameters to determine its size, and title as the text that should be displayed in the window's title bar.  The mlx_ptr parameter is the connection identifier returned by `mlx_init ()` (see the mlx  man  page).
`mlx_new_window  ()` returns a void * window identifier that can be used by other MiniLibX calls.  Note that the MiniLibX can handle an arbitrary number of separate windows.
`mlx_clear_window ()` and `mlx_destroy_window ()` respectively clear (in black) and destroy the given window. They both have the same parameters: mlx_ptr is the screen connection identifier, and win_ptr is a window identifier.


# FDF considerations
## Lines between points:
	- For point (x, y): lines to (x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)
	- For each line y: (x = 0, y) to (x + 1, y), x++ until x + 1 is #column_count
	- For each column x: (x, y = 0) to (x, y + 1), y++ until y + 1 is #line_count

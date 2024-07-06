# Makefile know-how
Reference(s):
- [Colby College's simple Makefile tutorial](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html):
	- [Pattern rules](https://www.gnu.org/software/make/manual/make.html#Pattern-Intro)
- [All you need to know about C Static libraries](https://dev.to/iamkhalil42/all-you-need-to-know-about-c-static-libraries-1o0b)

## Elements of a Makefile
### Rules
#### General structure
A Makefile contains a list of *rules* which are in two parts:
- A *dependency line* which details which files depend on which other files:
	- pre-colon: the *target* file
	- post-colon: the *prerequisites* (which *depend* on the first part)
- *Actions/Commands* (indented with a tab)
- The syntax is as follows:
```bash
RULE: DEPENDENCY LINE
	[tab]ACTION LINE(S)
```
(n.b.: the action line, or recipe, can appear on the same line after a `;` rather than a newline+tab)
- [Types of prerequisites](https://www.gnu.org/software/make/manual/make.html#Prerequisite-Types):
	- *normal*: imposes an order in which recipes will be invoked: recipes for all prerequisites will be completed before the recipe for the target. If any prerequisite is newer than the target, the target is considered out-of-date and must be rebuilt.
	- *order-only*: ensures that a prerequisite is built before a target, but without forcing the target to be updated if the prerequisite is updated

#### Pattern rules
[*pattern rules*](https://www.gnu.org/software/make/manual/make.html#Pattern-Intro) contain the character `%` in the target, which matches any nonempty string -> "a pattern for matching file names". Look exactly like ordinary rules otherwise.

##### Prefixes
`SRCS = ft_.....c ft_...c ....
`SRC = $(addprefix src/, $(SRCS))`


### [Variables](https://www.gnu.org/software/make/manual/make.html#Using-Variables)
[Two flavors](https://www.gnu.org/software/make/manual/make.html#Flavors):
- **recursively expanded variables**: defined by lines using `=` or the `define` directive. References to other variables are expanded whenever a variable is substituted.
	- Example:
	```bash
	foo = $(bar)
	bar = $(ugh)
	ugh = Huh?

	all:;echo $(foo)
	```
	will echo ‘Huh?’: `$(foo)` expands to `$(bar)` which expands to `$(ugh)` which finally expands to ‘Huh?’
	- n.b.: you cannot append something to the end of such a variable (infinite loop), e.g. `CFLAGS = $(CFLAGS) -O`
- **simply expanded variables**: defined by lines using `:=` or `::=` (equivalent in GNU make, but only the `::=` form is described by POSIX standard). Their value is scanned only once, expanding any references to other variables and functions, when the variable is defined.
	- Example:
	```bash
	x := foo
	y := $(x) bar
	x := later
	```
	is equivalent to:
	```bash
	y := foo bar
	x := later
	```
- [**Automatic variables**](https://www.gnu.org/software/make/manual/make.html#Automatic-Variables) :
	- `$@` : file name of the target of the rule
	- `$<` : name of the first prerequisite
	- `$^` : name of all the prerequisites with spaces in-between

#### Substitution references
A *substitution reference* substitutes the value of a variable with alterations you specify, e.g.
```bash
foo := a.o b.o l.a c.o
bar := $(%foo:.o=.c)
```
sets `bar` to 'a.c b.c l.a c.c'

## Syntax
- `make` with no arguments executes from the first rule in the file
- line split: "`$\`+newline", although `make`` places no limit on the length of a line in a makefile
- `tab` is required at the beginning of any command, e.g. "`gcc`"
- `%` matches any nonempty string (see [Pattern rules](https://www.gnu.org/software/make/manual/make.html#Pattern-Intro)). N.b.: 42 Norm doesn't authorize wildcards for `SRC`

## Making a static library with archiver (`ar`)
- **Flags**:
	- `-r` : to replace or add the specified files to the archive. Creates a new archive file if the archive does not exist
	- `-c` : create the archive silently (no message to `stderr`)
	- `-s` : write an object-file index to the archive, or update an existing one. N.b.: the index is used by the compiler to speed-up symbol-lookup inside the library and make sure the order of the symbols in the library don't matter during compilation.


## Commands
- `make -n` : check if relink
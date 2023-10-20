# Makefile know-how
Reference(s):
- [Colby College's simple Makefile tutorial](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html):
	- [Pattern rules](https://www.gnu.org/software/make/manual/make.html#Pattern-Intro)
	- [All you need to know about C Static libraries](https://dev.to/iamkhalil42/all-you-need-to-know-about-c-static-libraries-1o0b)

## Elements of a Makefile
- A Makefile contains a list of *rules* which are in two parts:
	- A *Dependency line* which details which files depend on which other files
		pre-colon, the *target* file and post-colon, the *prerequisites* (which *depend* on the first part)
	- *Actions*/*Commands* (indented with a tab)
- 
```bash
RULE: DEPENDENCY LINE
	[tab]ACTION LINE(S)
```

## Syntax
- `make` with no arguments executes from the first rule in the file
- `tab` is required at the beginning of any command, e.g. "`gcc`"
- `%` matches any nonempty string (see [Pattern rules](https://www.gnu.org/software/make/manual/make.html#Pattern-Intro)). N.b.: 42 Norm doesn't authorize wildcards for `SRC`
- **Compiler flags** :
	- `-I` : specifies to look in the current directory (.) for header files.
	- `-c`: generate the object file, i.e. compile and assemble, but do not link
	- `-o` : write output to file
- **Automatic variables** :
	- `$@` : file name of the target of the rule
	- `$<` : name of the first prerequisite
	- `$^` : name of all the prerequisites with spaces in-between


## Making a static library with archiver (`ar`)
- **Flags**:
	- `-r` : to replace or add the specified files to the archive. Creates a new archive file is the archive does not exist
	- `-c` : create the archive silently (no message to `stderr`)
	- `-s` : write an object-file index to the archive, or update an existing one. N.b.: the index is used by the compiler to speed-up symbol-lookup inside the library and make sure the order of the symbols in the library don't matter during compilation.
	- 
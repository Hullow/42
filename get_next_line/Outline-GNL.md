// input: file descriptor, e.g. text file
// output: line read

// Procedure:

// 1. take in a file descriptor
// 2. read that file descriptor, byte by byte, to a buffer of size BUFFER_SIZE (variable), until you hit a newline character byte ("\n"), or you hit the end of the BUFFER_SIZE
// 3. If the BUFFER_SIZE is smaller than the number of characters of the line, ?
// 4. Return the line read as a string

// Summary of procedure:
// you want it to read the line until the buffer is full, then store the buffer value into a "return" array, empty the buffer ? or refill it ? => test to see what happens when you read twice. then repeat the procedure, add it to the return array, => problem: array size isn't known. so array of arrays ? just use linked list. then, return string from linked list, maybe after having extracted it.
// **termination condition**:
cannot be directly applied to read(). Must be done on the buffer. Problem: if nbytes


// Constraints:
// A. Successive calls to the function must enable one to read the whole of the text file pointed to by the file descriptor
// B. Votre programme doit lire le moins possible à chaque appel à get_next_line(). Si vous rencontrez une nouvelle ligne, vous devez retourner la ligne précédente venant d’être lue. Ne lisez pas l’intégralité du fichier pour ensuite traiter chaque ligne.
// Pour vos tests, gardez à l’esprit que :
1) Le buffer et la ligne peuvent être de tailles très différentes.
2) Un descripteur de fichier ne pointe pas seulement sur de simples
fichiers.
Soyez malins et vérifiez votre travail avec vos pairs. Préparez un
large éventail de tests pour votre évaluation.

Note: presumably this is done with the use of a (local) static variable

```c
char *get_next_line(int fd)
{

static int line = 0;
int	char_count;
char_count = ft_line_length(fd, line);
lines++;
char	array_read[char_count];
char	buf[BUFFER_SIZE];

read(fd, buf, char_count);
// CASE: buf size not constrained
// read into buf of size 3
// is there a way to stop at \n character ?
// reminder: read returns number of bytes read


// CASE: buf size is constrained (buf == 3)
// read into buf of size 3
// malloc an array of size 3
// store the contents of buf in array
// read into buf of size 3

// if buf == 1 && char_count == 5
// read will do ?
// reminder: buf needs to point to a valid memory location with a length not smaller than the specified size because of overflow.

}

int	ft_line_length(fd, line)
char c;
int char_count = 0;
static int read_position;

//use read here ?

while (c != "\n")
	char_count++;
	read_position++;

return(char_count);

```c
char	*get_next_line(int fd)
{

}
```
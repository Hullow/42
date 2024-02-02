void ft_putchar(char c);

void border(char c); //function for first and last line
void lines(char c); //function for other lines

void rush(int x, int y) {

	int x; //column number
	int y; //line number

	scanf(x,y);
	if x or y == 0 break;

	int i_x;
	int i_y;

	border(x) //prints the first line
	i_y = 1;
	while i_y < y {lines(x)}  //goes through each line 
	border(x) //prints the last line
}

void border(int x) {

	i_x=1;
	putchar a
    while i_x < x { //prints b (x-2)times; from 1 to x-1
        putchar b;
        i_x++1;
    }
    putchar c
    putchar newline
}

void lines(int x) {
    i_x = 1;
	putchar b
    while i_x < x { //print space (x-2)times; from 1 to x-1
        putchar space;
        i_x++1;
	}
    putchar b
    putchar newline
}

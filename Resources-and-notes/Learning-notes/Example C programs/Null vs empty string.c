#include <stdio.h>
#include <string.h>

int main()
{
    char empty[5] = { '\0' };
    char null[5];

    if( strcmp(empty,null)==0 )
        puts("Strings are the same");
    else
        puts("Strings are not the same");
	printf("empty has length: %lu\n", strlen(empty));
	printf("null has length: %lu\n", strlen(null));
    return(0);
}
#include <string.h>
#include <stdio.h>

/* int main()
{
	char *src = "lorem ipsum dolor sit amet";
	char dst[50]; = "dolor sit amet";
	printf("length of dst: %lu, length of src: %lu\n", strlen(dst), strlen(src));
	
	size_t dstlen = strlen(dst);
	strlcpy(dst, src, dstlen);
	printf("dst after strcpy: %s\n", dst);
	return (0);
} */

#include <string.h>
#include <stdio.h>

int main() {
    char *src = "lorem ipsum dolor sit amet";
    char dst[256]; // Make sure this is large enough to hold src and the null terminator.
    // Use strlcpy to copy the string safely to dst.
    strlcpy(dst, src, sizeof(dst));
    
    // Now you can modify dst.
 // Capitalize the first letter, for example.
    printf("dst after modifications: %s\n", dst);

    return 0;
}

/* int main() {
    char *src = "lorem ipsum dolor sit amet";
	printf("%s\n", src);
    return (0);
} */



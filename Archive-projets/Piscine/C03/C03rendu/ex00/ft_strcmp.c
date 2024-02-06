int ft_strcmp(char *s1, char *s2)
{
while (*s1 != 0 && *s2 != 0 && *s1 == *s2)
{
s1++;
s2++;
}
if (*s1 == 0 && *s2 == 0)
return (0);
else if (*s1 == 0 && *s2 != 0)
return (- *s2);
else if (*s2 == 0 && *s1 != 0)
return (*s1);
else
return (*s1 - *s2);
}

#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
argc = 3;
int myfunction = ft_strcmp(argv[1], argv[2]);
int benchmark = strcmp(argv[1], argv[2]);
// Test using strcmp
if (benchmark == 0)
printf("strcmp: the two strings identical, the return value being %d.\n", benchmark);
else if (benchmark > 0)
printf("strcmp: first non-matching character in %s is greater (in ASCII) than that of %s, the return value being %d.\n", argv[1], argv[2], benchmark);
else if (benchmark < 0)
printf("strcmp: first non-matching character in %s is lower (in ASCII) than that of %s, the return value being %d.\n", argv[1], argv[2], benchmark);
// Test using my function
if (myfunction == 0)
printf("my function: two strings identical, the return value being %d.\n", myfunction);
else if (myfunction < 0)
printf("my function: first non-matching character in %s is greater (in ASCII) %s, the return value being %d.\n", argv[1], argv[2], myfunction);
else if (myfunction > 0)
printf("my function: first non-matching character in %s is lower than %s, the return value being %d.\n", argv[1], argv[2], myfunction); 
return(0);
}
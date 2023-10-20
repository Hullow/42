# Notes Libft

## 

## Checklist
- "Toute mémoire allouée sur la heap doit être libéré lorsque c’est nécessaire. Aucun
leak ne sera toléré" => free les malloc ?

## Journal
- 14?/10/23: wasted time on `man toupper` looking at the notion of locales, which only applied to `toupper_l`
- 18/10/23: used `sed` (from chatGPT) to insert `#include <Libft.h>` at the beginning of each file, then tried to replace it with `#include "Libft.h"` => didn't work, ended up using VS Code find and replace manually in each file. Wasted ~45min.


## Tester librairie
`gcc main.c -L. -lname -o main` <!-- n.b.: name is "ft" in our case ("Libft.a"). We remove the "lib" from the name and the extension, so flag is "-lft" -->
Main.c:
```c
#include "Libft.h"
int	main(int argc, char **argv)
{
	if (argc > 1)
		printf("your string '%s' is %zu characters long.\n", argv[1], ft_strlen(argv[1]));
	return(0);
}
```

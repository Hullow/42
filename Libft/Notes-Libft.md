# Notes Libft

## 

## Checklist
- "Toute mémoire allouée sur la heap doit être libéré lorsque c’est nécessaire. Aucun
leak ne sera toléré" => free les malloc ?

## Journal
- 14?/10/23: wasted time on `man toupper` looking at the notion of locales, which only applied to `toupper_l`
- 18/10/23: used `sed` (from chatGPT) to insert `#include <Libft.h>` at the beginning of each file, then tried to replace it with `#include "Libft.h"` => didn't work, ended up using VS Code find and replace manually in each file. Wasted ~45min.
- 24/10/23: a whole day of work almost on memmove, until I decided to write the solution to all scenarios on paper, then code it. It was almost correct except for some increment I missed. Looked at the solution to finally crack it; I was very close but not there (esp syntax of array was an issue, even though we are handling char arrays so [] notation is useable). Next time work out scenarios faster, look at solution faster.
- 30/10/23: finished debugging `ft_memmove` + `ft_strlcpy` in the morning. `Strlcpy`: simply rewrote it.

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


## On Libc
(Du *GNU Libc Manual*)
- Les fonctions qui operent sur des blocs de memoire arbitraire qui n'ont pas forcement de null-terminator ont des noms qui commencent par `mem`. Leurs elements sont appeles *bytes* pour des raisons de style, mais ont peut leur donner comme input des pointeurs de n'importe quel type
- Les fonctions qui operent sur des strings, dont avec null-terminator, commencent par `str`
- Souvent il existe une version `mem` et une version `str` d'une fonction. L'usage depend de la situation.
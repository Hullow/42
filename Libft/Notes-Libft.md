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
- 3/11/23: ft_split (debut), structure et commence ft_count_memory. + aide Theo debugging VS Code.
- 6/11/23: 
	- ft_split (suite): bus error dans ft_count_words corrige en rajoutant un `&& *search` dans un `while` lui-meme contenu dans un grand `while (*search)`. Verification: seulement quand il finit la boucle
	- ft_substr (termine parce que necessaire pour ft_split): passe 1h30-2h sur un memory problem. Les tests de francinette avec len == SIZE_MAX posaient probleme, d'ou solution `if (len > strlen(s)) len = strlen(s);`. Plus de problemes de memoire
- 7/11/23:
	- ft_split (suite - 2h): tourne, printf dans main marche, mais une fois sur 2 pour "CBonjourChelloCgoodbyeC" il print "Bonjour", "ello", "goodby" au lieu de "hello" et "goodbye". Il print aussi une ligne "dealloc" à la fin bizarrement.
	- paco/francinette ne compile pas contrairement à moi. bizarre. => après essais, questions dans groupe whatsapp...c'était le makefile qu'il fallait compléter avec ft_split.c !
	- C/C++ VSCode Microsoft debugger: add compile instructions, e.g. `-L. -lft`, to `tasks.json`
- 8/11/23:
	- ft_split (suite – 1h): debug with chatGPT => need to calloc correctly, with `*`: `ft_calloc(word_count, sizeof(char*))` and null-terminate each string in the array: `split[i][j] = '\0';`.
- 10/11/23:
  - ft_split (suite - 5h): des heures a essayer de capter d'ou vient le memory leak.
    - ChatGPT me pointe ds bonne direction: strtrim qui malloc (stop - start + 1), or des fois stop < start. J'avais ecris if (stop - start < 0), sans succes; c'etait parce que unsigned int (undefined behavior). Il fallait evaluer start > stop plutot. Reste des leaks dans split
    - corrige probleme avec char character[1] => ne null-termine pas automatiquement !
    - `fsanitize=address` me pointe ou je dois free()
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
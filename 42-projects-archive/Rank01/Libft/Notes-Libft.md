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
    - une fois corrige, la francinette me pointe ou je dois free()

- 13/11/23:
	- strlcat: enfin bon. Solution trouvee en regardant la reponse sur le gitbook: le man de strlcat n'etait pas clair, il fallait retourner une valeur differente selon les cas. Cas de figure:
		- si `dstsize <= dstlen`, alors le buffer de destination est trop petit pour accueillir de nouveau caracteres; pas besoin de manip. Il faut return (dstsize + srclen) parce que ...(1) ?
		- si `dstsize > srclen + dstlen`, on a la place pour tout copier, donc `ft_memcpy(dst + dstlen, src, srclen + 1)` (+1: pour copier le `'\0'`)
		- sinon, on manque de place pour tout copier, donc:
		```c
		while (i < dstsize - dstlen - i)
			dst[dstlen + i] = src[i]; i++;
		dst[dstlen + i] = '\0'; // on NUL-termine manuellement
		```
	(1): question sur Discord, on m'envoie sur le [code source de libc/strlcat.c](https://android.googlesource.com/platform/bionic/+/ics-mr0/libc/string/strlcat.c): effectivement, deux return value differentes, selon si `dstlen >= dstsize` ou pas. Mais toujours pas compris *pourquoi*. 

- 14/11/23:
	- debugged many Libft functions. notes on a few:
		- ft_memchr: had to convert `*string` to `unsigned char` to test: `if ((unsigned char) *string == character)`, and not stop at end of string, i.e. remove `while (*string)`
		- ft_strchr: had to include case where `c` is `'\0'` and typecast `c` to `char` when comparing with `*string`

- 15/11/23: 30 bonnes minutes pour faire marcher le debugger VSCode, solution trouvee (`-g` flag en compilant pour produire des debugging infos)

- 23/11/23: trip to Aix, no work sadly.

- 24/11/23: reading about linked lists, but mostly working on Makefile for the bonus. One note: `clean` and `fclean` rules only need a target but no prerequisites. My bonus rule: 
```c
bonus: | $(NAME) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ_BONUS)
```
didn't work without the prerequisites (`$(NAME) $(OBJ_BONUS)`) in the dependency line (first line). Why ? ChatGPT: the **purpose of a prerequisite** in a makefile is to specify a file that must be up-to-date before the target can be processed; thus leads make to check if each prerequisite is newer than the target. If so, or if the prerequisite doesn't exist, make executes the commands associated with that target.

Purpose of Prerequisites: In a makefile, a prerequisite is a file that must be up-to-date before the target can be processed. When you specify prerequisites for a target, make checks if each prerequisite is newer than the target. If so, or if the prerequisite doesn't exist, make executes the commands associated with that target.


All right, that was helpful. `make bonus` now works, after adding `$(NAME) $(OBJ_BONUS)` as prerequisites in the dependency line. However, I don't understand the underlying logic for the need to include these variables there. Indeed, the following rules `clean` and `fclean` don't have prerequisites yet work. Why is it different ?

For reference see the code below:


```c
bonus: $(NAME) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ_BONUS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
```

ChatGPT
I'm glad to hear that your make bonus now works! Let's break down the underlying logic behind prerequisites in makefiles and why they are necessary for some targets but not others.

Understanding Prerequisites in Makefiles

- 27/11/23: little work, fooling around with linked lists/bonus part for 1h30 at societe de lecture. tired, not v focused.

- 28/11/23: advancing on linked lists. Debugging `lstadd_back`: needed to add a temp variable to modify. See [42 gitbook answer](https://42-cursus.gitbook.io/guide/rank-00/libft/bonus-functions/ft_lstadd_back) which I still don't fully understand.

```c
void ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list *last;
    last = ft_lstlast(*alst);
    if (!last)
        *alst = new; /* if last is NULL, there is no list, so we set the list pointer * to point to the new element */
    last->next = new;  /* we set the last's next variable to point to the new element */
}
```

- 1/12/23: morning: video about stack and heap in train; reading about structs online. lstiter: looked at hints. lstmap: looked at solution, not too proud of myself.

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
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (1);
}

#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	character;

	character = 'i';

	printf("The return value of tupper is %c\n", toupper(character));
	printf("The return value of ft_tupper is %c\n", ft_toupper(character));
	printf("The variable character is now equal to: %c\n", character);
		return (0);
}


// NAME
//      xlocale -- Extended locale support.

// LIBRARY
//      Standard C Library (libc, -lc)

// DESCRIPTION
//      Include <xlocale.h> for extended locale support.  It can be used alone or with the POSIX locale
//      API in <locale.h>.

//      The extended locale, or "xlocale" API consists of five basic routines, which are documented sepa-
//      rately: duplocale(3), freelocale(3), newlocale(3), querylocale(3), and uselocale(3).  For each of
//      these routines, if a NULL locale_t is given, the current locale is used.
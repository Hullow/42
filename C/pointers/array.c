#include <unistd.h>

void    ft_print_array(int *tab, int size)
{
    int i;
/*   i = 0;
    while (i < size)
    {
        tab[i] += 48;
        i++;
    }
    
    i = 0;
    while (i < size)
    {
    write(1, &tab[i], 1);
    i++;
    }
    write(1, "\n", 1);
*/    
    i = 0;
    while (i < size)
    {
        *(tab+i) += 48;
        i++;
    }
 
    i = 0;
    while (i < size)
    {
        write(1, tab+i, 1);
    i++;
    }
}

int main(void)
{
    int tab[5];
    int size = 5;
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    tab[3] = 4;
    tab[4] = 5;
 /* tab = malloc(size * sizeof(int));   // need this to initialize tab
    *tab = 1;
    *(tab+1) = 2;
    *(tab+2) = 3;
    *(tab+3) = 4;
    *(tab+4) = 5;
 */ ft_print_array(tab, size);
    return (0);
}
#include <unistd.h>
#include <stdlib.h>

void    ft_rev_int_tab(int *tab, int size)
{
    int i;
    i = 0;
    while (i < size)
    {
        *(tab+i) += 48;
        i++; 
    }
    i = 0;
    while(i < size)
    {
        write(1, tab+i, 1);
        i++;
    }
}

int main(void)
{
    int *tab;
    int size;
    
    size = 5;
//   
    *tab = 1;
    *(tab+1) = 2;
    *(tab+2) = 3;
    *(tab+3) = 4;
    *(tab+4) = 5;
    
    ft_rev_int_tab(tab, size);
    free(tab);
    return (0);
}
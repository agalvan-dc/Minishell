
#include "../libft.h"
//#include <stdio.h>
//#include <string.h>
void *ft_memset(void *b, int c, size_t len)
{
    unsigned char   *ptr;
    size_t      i;

    i = 0;
    ptr = (unsigned char *)b;
    while (i < len)
    {
        ptr[i] = (unsigned char)c;
        i++;
    }
    return(b);
}
/*
int main(void)
{
    char cad1[] = "Hello World";
    char cad2[] = "Hello World";

    memset(cad1, 'z', 4);
    ft_memset(cad2, 'z', 4);

    printf("%s\n", cad1);
    printf("%s", cad2);
    return(0);
}*/

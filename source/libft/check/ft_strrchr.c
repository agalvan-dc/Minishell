
#include "../libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char    *p;
    int i;

    i = 0;
    p = (char *)s;
    if (!p)
        return (NULL);
    while (p[i])
        i++;
    while (i >= 0)
    {
        if ((unsigned char)p[i] == (unsigned char)c)
            return (p + i);
        i--;
    }
    return (NULL);
}

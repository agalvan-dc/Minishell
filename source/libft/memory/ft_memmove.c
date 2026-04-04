
#include "../libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char   *d;
    unsigned char   *s;
    size_t  i;

    if (!dst && !src)
        return (NULL);
    i = 0;
    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    if (d < s)
    {
        while (i < len)
        {
            d[i] = s[i];
            i++;
        }
    }
    else
    {
        while (len > 0)
        {
            len--;
            d[len] = s[len];
        }
    }
    return(dst);
}


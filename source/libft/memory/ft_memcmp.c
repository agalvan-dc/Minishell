
#include "../libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t  i;
    const unsigned char *p1;
    const unsigned char *p2;

    p1 = (const unsigned char *)s1;
    p2 = (const unsigned char *)s2;
    i = 0;
    while (i < n)
    {
        if (p1[i] != p2[i])
            return (p1[i] - p2[i]);
        i++;
    }
    return (0);
}

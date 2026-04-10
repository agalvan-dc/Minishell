
#include "../libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    unsigned char   *p;

    if (size != 0 && count > SIZE_MAX / size)
        return (NULL);
    p = malloc(count * size);
    if (!p)
        return (NULL);
    ft_memset(p, 0, count * size);
    return (p);
}

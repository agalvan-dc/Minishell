
#include "../libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *cad;
    size_t  i;
    size_t  s_len;

    i = 0;
    s_len = 0;
    while (s[s_len])
        s_len++;
    if (s_len <= (size_t)start || len == 0)
        return (ft_strdup(""));
    if (start + len > s_len)
        len = s_len - start;
    cad = malloc(sizeof(char) * (len + 1));
    if (cad == NULL)
        return (NULL);
    while (i < len)
    {
        cad[i] = s[(size_t)start + i];
        i++;
    }
    cad[i] = '\0';
    return (cad);
}
/*
#include <stdio.h>
int main(void)
{
    printf("%s", ft_substr("lorem ipsum dolor sit amet", 0, 10));
    return (0);
}*/

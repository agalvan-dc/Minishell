#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		srcsize;

	n = (unsigned int)n;
	i = 0;
	srcsize = ft_strlen((char *)src);
	if (n)
	{
		while (src[i] != '\0' && (i + 1 < n))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (srcsize);
}


#include "../libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = ft_strlen(src);
	i++;
	dest = malloc(i * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, i);
	return (dest);
}

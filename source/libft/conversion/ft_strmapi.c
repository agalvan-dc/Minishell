
#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;
	int		l;

	if (!(s))
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	dest = malloc((l + 1) * (sizeof(char)));
	if (!(dest))
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

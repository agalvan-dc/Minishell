#include "../libft.h"

int	ft_wordcompt(char *str, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sep)
		{
			while (str[i] != sep && str[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_sep(char *str, char **dest, char sep, int count)
{
	int	k;
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (str[i] != '\0' && j < count)
	{
		k = 0;
		while (str[i] == sep)
			i++;
		while (str[i + k] != sep && str[i + k] != 0)
			k++;
		dest[j] = ft_substr(str, i, k);
		if (! dest[j++])
			return (NULL);
		i = i + k;
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(char const *str, char sep)
{
	char	**dest;
	int		count;

	if (!str)
		return (NULL);
	count = ft_wordcompt((char *)str, sep);
	dest = (char **)malloc((count + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	return (ft_sep((char *)str, dest, sep, count));
}


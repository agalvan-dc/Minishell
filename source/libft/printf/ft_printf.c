
#include  "../libft.h"

int	ft_printf(const char *str, ...)
{
	va_list		liste;
	int			i;
	int			count;

	va_start(liste, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_check_format(str, liste, i);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(liste);
	return (count);
}


#include "../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	count_putchar_fd(char c, int *count, int fd)
{
	write(fd, &c, 1);
	*count += 1;
}

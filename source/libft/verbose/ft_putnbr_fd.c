
#include  "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	char			c;

	c = '-';
	nb = n;
	if (n < 0)
	{
		write(fd, &c, 1);
		nb = n * -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd((nb / 10), fd);
	}
	c = 48 + nb % 10;
	write (fd, &c, 1);
}

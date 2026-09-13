/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_puthexa_max(unsigned int nb)
{
	int		count;
	char	*alphabet;

	count = 0;
	alphabet = "0123456789ABCDEF";
	if (nb >= 16)
		count += ft_puthexa_max(nb / 16);
	count += ft_putchar(alphabet[nb % 16]);
	return (count);
}

int	ft_puthexa_min(unsigned int nb)
{
	int		count;
	char	*alphabet;

	count = 0;
	alphabet = "0123456789abcdef";
	if (nb >= 16)
		count += ft_puthexa_min(nb / 16);
	count += ft_putchar(alphabet[nb % 16]);
	return (count);
}

int	ft_puthexa_long(unsigned long nb)
{
	int		count;
	char	*alphabet;

	count = 0;
	alphabet = "0123456789abcdef";
	if (nb >= 16)
		count += ft_puthexa_long(nb / 16);
	else
		count += ft_putstr("0x");
	count += ft_putchar(alphabet[nb % 16]);
	return (count);
}

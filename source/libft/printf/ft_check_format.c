/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include  "../libft.h"

int	ft_check_format(const char *str, va_list liste, int i)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar(va_arg(liste, int));
	else if (str[i] == 's')
		count += ft_putstr(va_arg(liste, char *));
	else if (str[i] == 'p')
		count += ft_puthexa_long(va_arg(liste, unsigned long));
	else if (str[i] == 'i' || str[i] == 'd')
		count += ft_putnbr(va_arg(liste, int));
	else if (str[i] == 'u')
		count += ft_putunbr(va_arg(liste, unsigned int));
	else if (str[i] == 'x')
		count += ft_puthexa_min(va_arg(liste, unsigned int));
	else if (str[i] == 'X')
		count += ft_puthexa_max(va_arg(liste, unsigned int));
	else if (str[i] == '%')
		count += ft_putchar('%');
	i++;
	return (count);
}

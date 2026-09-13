/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char    *p;
    int i;

    i = 0;
    p = (char *)s;
    if (!p)
        return (NULL);
    while (p[i])
        i++;
    while (i >= 0)
    {
        if ((unsigned char)p[i] == (unsigned char)c)
            return (p + i);
        i--;
    }
    return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    char    *p;
    int i;

    i = 0;
    p = (char *)s;
    c = (char)c;
    if (!p || !p[0])
        return (NULL);
    while (p[i] && p[i] != c)
    {
        if (p[i] == c)
            return (&p[i]);
        i++;
    }
    if (p[i] == c)
        return (&p[i]);
    return (NULL);
}

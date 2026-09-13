/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *cur;
    t_list  *tmp;

    if (!lst || !*lst)
        return ;
    cur = *lst;
    while (cur != NULL)
    {
        tmp = cur->next;
        del(cur->content);
        free(cur);
        cur = tmp;
    }
    *lst = NULL;
    return ;
}


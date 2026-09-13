/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *cur;

    if (!lst || !new)
        return ;
    cur = *lst;
    if (*lst == NULL)
    {
        *lst = new;
        return ;
    }
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = new;
    return ;
}


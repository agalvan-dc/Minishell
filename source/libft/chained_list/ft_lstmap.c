/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *n_node;
    t_list  *aux;
    void    *a;

    n_node = NULL;
    while (lst)
    {
        a = f(lst->content);
        aux = ft_lstnew(a);
        if (!aux)
        {
            del(a);
            ft_lstclear(&n_node, del);
            return (n_node);
        }
        ft_lstadd_back(&n_node, aux);
        lst = lst->next;
    }
    return (n_node);
}


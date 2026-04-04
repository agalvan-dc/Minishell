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


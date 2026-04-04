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


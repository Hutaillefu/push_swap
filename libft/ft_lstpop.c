#include "libft.h"

#include <stdio.h>

t_list  *ft_lstpop(t_list **lst)
{
    t_list *head;

    if (!lst || !(*lst))
        return (NULL);

    head = *lst;
    *lst = head->next;
    return head;
}
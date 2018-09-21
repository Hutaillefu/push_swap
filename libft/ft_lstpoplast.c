#include "libft.h"

t_list  *ft_lstpoplast(t_list **lst)
{
    t_list  *last;
    t_list  *previous;
    if (!lst || !(*lst))
        return (NULL);
    previous = NULL;
    last = *lst;
    while (last->next)
    {
        previous = last;
        last = last->next;
    }
    previous->next = NULL;
    return last;
}
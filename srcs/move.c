#include "push_swap.h"

#include <stdio.h>

// sa, sb, ss
void    swap_two_first(t_list **lst)
{
    t_list  *t1;
    t_list  *t2;

    if (!lst || !(*lst) || !(*lst)->next)
        return;
    
    t1 = ft_lstpop(lst);
    t2 = ft_lstpop(lst);

    ft_lstadd(lst, t1);
    ft_lstadd(lst, t2);
}

// pa, pb
void    move_sommet(t_list **from, t_list **to)
{
    if (!from || !to || ! (*from))
        return ;
    ft_lstadd(to, ft_lstpop(from));
}

// ra, rb, rr
void    rotate_up(t_list **lst)
{
    if (!lst || !(*lst) || !(*lst)->next)
        return ;
    ft_lstpush(lst, ft_lstpop(lst));
}

// rra, rrb, rrr
void    rotate_down(t_list **lst)
{
    if (!lst || !(*lst) || !(*lst)->next)
        return ;
    ft_lstadd(lst, ft_lstpoplast(lst));
}

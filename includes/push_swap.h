#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

void    swap_two_first(t_list **lst);
void    move_sommet(t_list **from, t_list **to);
void    rotate_up(t_list **lst);
void    rotate_down(t_list **lst);

#endif
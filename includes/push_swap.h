#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

void    swap_two_first(t_list **lst);
void    move_sommet(t_list **from, t_list **to);
void    rotate_up(t_list **lst);
void    rotate_down(t_list **lst);

void	display(const char *tag, t_list **list);
int	ft_lstsorted(t_list **lst);
int	ft_lstgetmax(t_list **lst);
int	ft_lstgetmin(t_list **lst);
int	ft_lstgetminindex(t_list **lst);
int	can_rotate(t_list **lst);
int	can_rotate_index(t_list **lst);

t_list	*duplicate(t_list **lst);

int	ft_lstlen(t_list **lst);

void	process_param(t_list **lst, char *param);
int	process_command(char *command, t_list **la, t_list **lb);
#endif

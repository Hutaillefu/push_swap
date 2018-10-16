/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:29:48 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:29:52 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	swap_two_first(t_list **lst);
void	move_sommet(t_list **from, t_list **to);
void	rotate_up(t_list **lst);
void	rotate_down(t_list **lst);

void	display(const char *tag, t_list **list);
int		ft_lstsorted(t_list **lst);
int		ft_lstgetmax(t_list **lst);
int		ft_lstgetmin(t_list **lst);
int		ft_lstgetminindex(t_list **lst);
int		can_rotate(t_list **lst);
int		can_rotate_index(t_list **lst);
t_list	*duplicate(t_list **lst);
int		ft_lstlen(t_list **lst);
int     process_param(t_list **lst, char *param);
int		process_command(char *command, t_list **la, t_list **lb, int display);
int		ft_lstinversed(t_list **list);
void	free_list(t_list **lst);
int		ft_lstgetvalue(t_list **lst);
int		ft_get_median(t_list **lst);
int		lst_get_index(t_list **lst, int value);
void    move_min_to_head(t_list **la, t_list **lb);
void    move_max_to_head(t_list **la, t_list **lb);
void    move_median_to_head(t_list **la, t_list **lb);
#endif

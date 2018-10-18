/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:26:31 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:26:37 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two_first(t_list **lst)
{
	t_list	*t1;
	t_list	*t2;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	t1 = ft_lstpop(lst);
	t2 = ft_lstpop(lst);
	ft_lstadd(lst, t1);
	ft_lstadd(lst, t2);
}

void	move_sommet(t_list **from, t_list **to)
{
	if (!from || !to || !(*from))
		return ;
	ft_lstadd(to, ft_lstpop(from));
}

void	rotate_up(t_list **lst)
{
	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	ft_lstpush(lst, ft_lstpop(lst));
}

void	rotate_down(t_list **lst)
{
	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	ft_lstadd(lst, ft_lstpoplast(lst));
}

int		is_action(char *cmd)
{
	if (!cmd || !(*cmd))
		return (0);
	return (ft_strcmp(cmd, "sa") == 0 ||
	ft_strcmp(cmd, "sb") == 0 ||
	ft_strcmp(cmd, "pa") == 0 ||
	ft_strcmp(cmd, "pb") == 0 ||
	ft_strcmp(cmd, "ra") == 0 ||
	ft_strcmp(cmd, "rb") == 0 ||
	ft_strcmp(cmd, "rr") == 0 ||
	ft_strcmp(cmd, "rra") == 0 ||
	ft_strcmp(cmd, "rrb") == 0 ||
	ft_strcmp(cmd, "rrr") == 0);
}

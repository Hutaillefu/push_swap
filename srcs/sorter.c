/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sorter.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 14:50:50 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 14:50:52 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_2(t_list **lst_to_sort, t_list **other)
{
	process_command("sa", lst_to_sort, other, 1);
}

void		sort_3(t_list **list_to_sort, t_list **other)
{
	int a;
	int b;
	int c;

	a = *((int *)(*list_to_sort)->content);
	b = *((int *)(*list_to_sort)->next->content);
	c = *((int *)(*list_to_sort)->next->next->content);
	if (c > a && c > b)
		process_command("sa", list_to_sort, other, 1);
	else if (a < b && a < c)
	{
		process_command("rra", list_to_sort, other, 1);
		process_command("sa", list_to_sort, other, 1);
	}
	if (ft_lstsorted(list_to_sort))
		return ;
	if (a > b && a > c)
		process_command("ra", list_to_sort, other, 1);
	if (ft_lstsorted(list_to_sort))
		return ;
	if (c < a && c < b && a > b)
		process_command("sa", list_to_sort, other, 1);
	if (!ft_lstsorted(list_to_sort))
		process_command("rra", list_to_sort, other, 1);
}

void		sort_4(t_list **list_to_sort, t_list **other)
{
	if (ft_lstlen(list_to_sort) >= 4 &&
		ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->next->content)
		&& ft_lstgetmin(list_to_sort) == (*(int *)(*list_to_sort)->content) &&
		ft_lstsorted(&(*list_to_sort)->next->next))
	{
		process_command("sa", list_to_sort, other, 1);
		process_command("ra", list_to_sort, other, 1);
		return ;
	}
	if (ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->content) &&
		ft_lstsorted(&(*list_to_sort)->next))
	{
		process_command("ra", list_to_sort, other, 1);
		return ;
	}
	if (check_rotate(list_to_sort, other))
		return ;
	move_min_to_head(list_to_sort, other);
	if (ft_lstsorted(list_to_sort))
		return ;
	process_command("pb", list_to_sort, other, 1);
	sort_3(list_to_sort, other);
	process_command("pa", list_to_sort, other, 1);
}

static void	sort_n_2(t_list **list_to_sort, t_list **other)
{
	move_min_to_head(list_to_sort, other);
	if (ft_lstsorted(list_to_sort))
		return ;
	if (ft_lstlen(list_to_sort) >= 4 &&
		ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->next->content)
		&& ft_lstgetmin(list_to_sort) == (*(int *)(*list_to_sort)->content) &&
		ft_lstsorted(&(*list_to_sort)->next->next))
	{
		process_command("sa", list_to_sort, other, 1);
		process_command("ra", list_to_sort, other, 1);
		return ;
	}
	process_command("pb", list_to_sort, other, 1);
	if (ft_lstlen(list_to_sort) == 4)
		sort_4(list_to_sort, other);
	else
		sort_n(list_to_sort, other);
	process_command("pa", list_to_sort, other, 1);
}

void		sort_n(t_list **list_to_sort, t_list **other)
{
	if (!list_to_sort || !(*list_to_sort))
		return ;
	if (ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->content) &&
	ft_lstsorted(&(*list_to_sort)->next))
	{
		process_command("ra", list_to_sort, other, 1);
		return ;
	}
	if (ft_lstlen(list_to_sort) >= 4 &&
		ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->next->content)
		&& ft_lstgetmin(list_to_sort) == (*(int *)(*list_to_sort)->content) &&
		ft_lstsorted(&(*list_to_sort)->next->next))
	{
		process_command("sa", list_to_sort, other, 1);
		process_command("ra", list_to_sort, other, 1);
		return ;
	}
	if (check_rotate(list_to_sort, other))
		return ;
	sort_n_2(list_to_sort, other);
}

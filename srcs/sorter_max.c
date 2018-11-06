/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sorter_max.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 10:20:07 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 10:20:09 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int			is_min(t_list **list, int value)
{
	t_list *it;

	if (!list)
		return (0);
	it = *list;
	while (it)
	{
		if (ft_lstgetvalue(&it) <= value)
			return (1);
		it = it->next;
	}
	return (0);
}

static void	clean_b(t_list **la, t_list **lb)
{
	while (ft_lstlen(lb) > 0)
	{
		move_max_to_head(la, lb);
		process_command("pa", la, lb, 1);
	}
}

static void	clean_a(t_list **la, t_list **lb, int median, int *ret)
{
	while (is_min(la, median))
	{
		if (ft_lstgetvalue(la) <= median)
			process_command("pb", la, lb, 1);
		else
			process_command("ra", la, lb, 1);
		if (lb && ft_lstlen(lb) > 1 && ft_lstgetvalue(lb) ==
		median && is_min(la, median))
		{
			*ret = 1;
			if (ft_lstgetvalue(la) > median)
				process_command("rr", la, lb, 1);
			else
				process_command("rb", la, lb, 1);
		}
	}
}

void		sort_max(t_list **la, t_list **lb)
{
	int		median;
	int		ret;

	ret = 0;
	while (la && *la && ft_lstlen(la) > 1)
	{
		median = ft_get_median(la);
		clean_a(la, lb, median, &ret);
		if (ret)
		{
			ret = 0;
			if (ft_lstgetvalue(la) > ft_get_median(la))
				process_command("rrr", la, lb, 1);
			else
				process_command("rrb", la, lb, 1);
		}
	}
	clean_b(la, lb);
}

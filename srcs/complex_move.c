/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   complex_move.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 19:41:39 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 19:41:41 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void		move_min_to_head(t_list **la, t_list **lb)
{
	int		min;
	int		min_index;
	int		len;
	char	*cmd;

	min = ft_lstgetmin(la);
	min_index = lst_get_index(la, min);
	len = ft_lstlen(la);
	if (min_index == 1)
		process_command("sa", la, lb, 1);
	else
	{
		if ((len - min_index + 1.0) > len / 2.0)
			cmd = ft_strdup("ra");
		else
			cmd = ft_strdup("rra");
		while ((*(int *)(*la)->content) != min)
			process_command(cmd, la, lb, 1);
		ft_strdel(&cmd);
	}
}

void		move_max_to_head(t_list **la, t_list **lb)
{
	int		max;
	int		min_index;
	int		len;
	char	*cmd;

	max = ft_lstgetmax(lb);
	min_index = lst_get_index(lb, max);
	len = ft_lstlen(lb);
	if (min_index == 1)
		process_command("sb", la, lb, 1);
	else
	{
		if ((len - min_index + 1.0) > len / 2.0)
			cmd = ft_strdup("rb");
		else
			cmd = ft_strdup("rrb");
		while ((*(int *)(*lb)->content) != max)
			process_command(cmd, la, lb, 1);
		ft_strdel(&cmd);
	}
}

static void	process_median(t_list **la, t_list **lb, int median, char *cmd)
{
	if (ft_lstgetvalue(la) < median)
		process_command("pb", la, lb, 1);
	else
		process_command(cmd, la, lb, 1);
}

void		move_median_to_head(t_list **la, t_list **lb)
{
	int		median;
	int		min_index;
	int		len;
	char	*cmd;

	median = ft_get_median(la);
	min_index = lst_get_index(la, median);
	len = ft_lstlen(la);
	if (min_index == 1)
		process_median(la, lb, median, "sa");
	else
	{
		if ((len - min_index + 1.0) > len / 2.0)
			cmd = ft_strdup("ra");
		else
			cmd = ft_strdup("rra");
		while ((*(int *)(*la)->content) != median)
		{
			process_median(la, lb, median, cmd);
		}
		ft_strdel(&cmd);
	}
}

int			check_rotate(t_list **list_to_sort, t_list **other)
{
	if (can_rotate(list_to_sort))
	{
		move_min_to_head(list_to_sort, other);
		return (1);
	}
	return (0);
}

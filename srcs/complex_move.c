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

void	move_min_to_head(t_list **la, t_list **lb)
{
	int min = ft_lstgetmin(la);
	int min_index = ft_lstgetminindex(la);
	int len = ft_lstlen(la);
	char *cmd;

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

void move_max_to_head(t_list **la, t_list **lb)
{
	int max = ft_lstgetmax(lb);
	int min_index = lst_get_index(lb, max);
	int len = ft_lstlen(lb);
	char *cmd;

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

void move_median_to_head(t_list **la, t_list **lb)
{
	int median = ft_get_median(la);
	int min_index = lst_get_index(la, median);
	int len = ft_lstlen(la);
	char *cmd;

	if (min_index == 1)
	{
		if (ft_lstgetvalue(la) < median)
		{
			process_command("pb", la, lb, 1);
		}
		else
			process_command("sa", la, lb, 1);
	}
	else
	{
		if ((len - min_index + 1.0) > len / 2.0)
			cmd = ft_strdup("ra");
		else
			cmd = ft_strdup("rra");

		while ((*(int *)(*la)->content) != median)
		{
			if (ft_lstgetvalue(la) < median)
			{
				process_command("pb", la, lb, 1);
			}
			else
				process_command(cmd, la, lb, 1);
		}
		ft_strdel(&cmd);
	}
}

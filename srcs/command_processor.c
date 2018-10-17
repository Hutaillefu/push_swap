/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   command_proccessor.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 14:16:16 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 14:16:17 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_swap(char *command, t_list **la, t_list **lb)
{
	if (ft_strcmp(command, "sa") == 0)
		swap_two_first(la);
	else if (ft_strcmp(command, "sb") == 0)
		swap_two_first(lb);
	else if (ft_strcmp(command, "ss") == 0)
	{
		swap_two_first(la);
		swap_two_first(lb);
	}
	else
		return (0);
	return (1);
}

static int	process_pick(char *command, t_list **la, t_list **lb)
{
	if (ft_strcmp(command, "pa") == 0)
		move_sommet(lb, la);
	else if (ft_strcmp(command, "pb") == 0)
		move_sommet(la, lb);
	else
		return (0);
	return (1);
}

static int	process_rotate(char *command, t_list **la, t_list **lb)
{
	if (ft_strcmp(command, "ra") == 0)
		rotate_up(la);
	else if (ft_strcmp(command, "rb") == 0)
		rotate_up(lb);
	else if (ft_strcmp(command, "rr") == 0)
	{
		rotate_up(la);
		rotate_up(lb);
	}
	else
		return (0);
	return (1);
}

static int	process_reverse_rotate(char *command, t_list **la, t_list **lb)
{
	if (ft_strcmp(command, "rra") == 0)
		rotate_down(la);
	else if (ft_strcmp(command, "rrb") == 0)
		rotate_down(lb);
	else if (ft_strcmp(command, "rrr") == 0)
	{
		rotate_down(la);
		rotate_down(lb);
	}
	else
		return (0);
	return (1);
}

int			process_command(char *command, t_list **la, t_list **lb,
	int display)
{
	if (!command || !la || !lb || ft_strlen(command) < 2)
		return (0);
	if (process_swap(command, la, lb) ||
		process_pick(command, la, lb) ||
		process_rotate(command, la, lb) ||
		process_reverse_rotate(command, la, lb))
	{
		if (display)
		{
			ft_putstr(command);
			ft_putstr("\n");
		}
	}
	else
		return (0);
	return (1);
}

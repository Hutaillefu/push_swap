/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:26:31 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:26:37 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void		sort_max(t_list **la, t_list **lb)
{
	while (la && (*la) && ft_lstlen(la) > 1)
	{
		move_median_to_head(la, lb);
		process_command("pb", la, lb, 1);
	}
	while (ft_lstlen(lb) > 0)
	{
		move_max_to_head(la, lb);
		process_command("pa", la, lb, 1);
	}
}

int				main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;
	int		len;

	if (argc == 1)
		return (0);
	argv++;
	if (!init_param(&la, argv))
		return (0);
	if (ft_lstsorted(&la))
		return (0);
	len = ft_lstlen(&la);
	if (len == 2)
		sort_2(&la, &lb);
	else if (len == 3)
		sort_3(&la, &lb);
	else if (len == 4)
		sort_4(&la, &lb);
	else if (len < 20)
		sort_n(&la, &lb);
	else
		sort_max(&la, &lb);
	return (0);
}

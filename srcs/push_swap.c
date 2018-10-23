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

// static void		sort_max(t_list **la, t_list **lb)
// {
// 	while (la && (*la) && ft_lstlen(la) > 1)
// 	{
// 		move_median_to_head(la, lb);
// 		process_command("pb", la, lb, 1);
// 	}
// 	while (ft_lstlen(lb) > 0)
// 	{
// 		move_max_to_head(la, lb);
// 		process_command("pa", la, lb, 1);
// 	}
// }

void	display(t_list **lst)
{
	t_list *it;

	it = *lst;
	while (it)
	{
		ft_putnbr(ft_lstgetvalue(&it));
		ft_putchar(' ');
		it = it->next;
	}
	ft_putchar('\n');
}

#include <stdio.h>

int	is_min(t_list **list, int value)
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

static void		sort_max(t_list **la, t_list **lb)
{
	int		median;

	while (la && *la && ft_lstlen(la) > 1)
	{
		median = ft_get_median(la);

		while (is_min(la, median))
		{
			if (ft_lstgetvalue(la) <= median)
				process_command("pb", la, lb, 1);
			else
				process_command("ra", la, lb, 1);
		//	if (ft_lstlen(lb) >= 2 && ft_lstgetvalue(lb) < (*(int *)ft_lstgetindex(lb, ft_lstlen(lb) - 1)->content))
		//		process_command("rb", la, lb, 1);
 		}
	}

//	 display(lb);

	while (ft_lstlen(lb) > 0)
	{
		move_max_to_head(la, lb);
		process_command("pa", la, lb, 1);
	}
}

static void		free_lists(t_list **la, t_list **lb)
{
	free_list(la);
	free_list(lb);
}

static void		process(t_list **la, t_list **lb)
{
	int		len;

	len = ft_lstlen(la);
	if (len == 2)
		sort_2(la, lb);
	else if (len == 3)
		sort_3(la, lb);
	else if (len == 4)
		sort_4(la, lb);
	else if (len < 20)
		sort_n(la, lb);
	else
		sort_max(la, lb);
}

void			main_2(t_list **la, t_list **lb, char **tmp, int argc)
{
	if (!init_param(la, tmp, argc))
	{
		free_lists(la, lb);
		return ;
	}
	if (ft_lstsorted(la))
	{
		free_lists(la, lb);
		return ;
	}
	process(la, lb);
	free_lists(la, lb);
}

int				main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;

	la = NULL;
	lb = NULL;
	if (argc == 1)
		return (0);
	argv++;
	main_2(&la, &lb, argv, argc);
	return (0);
}

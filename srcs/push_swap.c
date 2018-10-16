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

void sort_2(t_list **lst_to_sort, t_list **other)
{
	process_command("sa", lst_to_sort, other, 1);
}

void sort_3(t_list **list_to_sort, t_list **other)
{
	int a = *((int *)(*list_to_sort)->content);
	int b = *((int *)(*list_to_sort)->next->content);
	int c = *((int *)(*list_to_sort)->next->next->content);

	if (c > a && c > b)
		process_command("sa", list_to_sort, other, 1);
	else if (a < b && a < c)
	{
		process_command("rra", list_to_sort, other, 1);
		process_command("sa", list_to_sort, other, 1);
	}

	if (ft_lstsorted(list_to_sort))
		return;

	if (a > b && a > c)
		process_command("ra", list_to_sort, other, 1);

	if (ft_lstsorted(list_to_sort))
		return;

	if (c < a && c < b && a > b)
		process_command("sa", list_to_sort, other, 1);

	if (!ft_lstsorted(list_to_sort))
		process_command("rra", list_to_sort, other, 1);
}

int check_rotate(t_list **list_to_sort, t_list **other)
{
	if (can_rotate(list_to_sort))
	{
		move_min_to_head(list_to_sort, other);
		return (1);
	}
	return (0);
}

void sort_4(t_list **list_to_sort, t_list **other)
{
	if (ft_lstlen(list_to_sort) >= 4 &&
		ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->next->content) &&
		ft_lstgetmin(list_to_sort) == (*(int *)(*list_to_sort)->content) &&
		ft_lstsorted(&(*list_to_sort)->next->next)) // min max sorted
	{
		process_command("sa", list_to_sort, other, 1);
		process_command("ra", list_to_sort, other, 1);
		return;
	}

	if (ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->content) && ft_lstsorted(&(*list_to_sort)->next))
	{
		process_command("ra", list_to_sort, other, 1);
		return;
	}

	if (check_rotate(list_to_sort, other))
		return;

	move_min_to_head(list_to_sort, other);

	if (ft_lstsorted(list_to_sort))
		return;

	process_command("pb", list_to_sort, other, 1);
	sort_3(list_to_sort, other);
	process_command("pa", list_to_sort, other, 1);
}

void sort_n(t_list **list_to_sort, t_list **other)
{
	if (!list_to_sort || !(*list_to_sort))
		return;

	if (ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->content) && ft_lstsorted(&(*list_to_sort)->next)) // max sorted
	{
		process_command("ra", list_to_sort, other, 1);
		return;
	}

	if (ft_lstlen(list_to_sort) >= 4 &&
		ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->next->content) &&
		ft_lstgetmin(list_to_sort) == (*(int *)(*list_to_sort)->content) &&
		ft_lstsorted(&(*list_to_sort)->next->next)) // min max sorted
	{
		process_command("sa", list_to_sort, other, 1);
		process_command("ra", list_to_sort, other, 1);
		return;
	}

	if (check_rotate(list_to_sort, other))
		return;

	move_min_to_head(list_to_sort, other);

	if (ft_lstsorted(list_to_sort))
		return;

	if (ft_lstlen(list_to_sort) >= 4 &&
		ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->next->content) &&
		ft_lstgetmin(list_to_sort) == (*(int *)(*list_to_sort)->content) &&
		ft_lstsorted(&(*list_to_sort)->next->next)) // min max sorted
	{
		process_command("sa", list_to_sort, other, 1);
		process_command("ra", list_to_sort, other, 1);
		return;
	}

	process_command("pb", list_to_sort, other, 1);

	if (ft_lstlen(list_to_sort) == 4)
		sort_4(list_to_sort, other);
	else
		sort_n(list_to_sort, other);

	process_command("pa", list_to_sort, other, 1);

}

void sort_max(t_list **la, t_list **lb)
{
	while (la && (*la) && ft_lstlen(la) > 1)
	{
		move_median_to_head(la, lb);
		process_command("pb", la, lb, 1);
	}

	//display("la : ", la);
	//display("lb : ", lb);

	while (ft_lstlen(lb) > 0)
	{
		move_max_to_head(la, lb);
		process_command("pa", la, lb, 1);
	}

	// display("la : ", la);
	// display("lb : ", lb);
}

int main(int argc, char **argv)
{
	t_list *la = NULL;
	t_list *lb = NULL;

	if (argc == 1)
		return (0);

	argv++;

	while (*argv)
	{
		if (!process_param(&la, *argv))
		{
			ft_putstr_fd("Error\n", 2);
			free_list(&la);
			return (0);
		}
		argv++;
	}

	if (ft_lstsorted(&la))
		return (0);

	int len = ft_lstlen(&la);

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

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

// Retourne la valeur d'un ;aillon de la liste
int ft_lstgetvalue(t_list **lst)
{
	return ((*(int *)(*lst)->content));
}

void ft_sort_tab(int *tab, int len)
{
	int i;
	int tmp;

	if (!tab)
		return;
	i = 0;
	while (i + 1 < len)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
			continue;
		}
		i++;
	}
}

int *ft_lst_to_array(t_list **lst)
{
	int *tab;
	t_list *it;
	int i;

	if (!lst)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * ft_lstlen(lst));
	it = *lst;
	i = 0;
	while (it)
	{
		tab[i] = ft_lstgetvalue(&it);
		i++;
		it = it->next;
	}

	return (tab);
}

int ft_get_median(t_list **lst)
{
	int len;
	int *tab;
	int res;

	if (!lst || !(*lst))
		return (-1);
	len = ft_lstlen(lst);
	tab = ft_lst_to_array(lst);

	ft_sort_tab(tab, len);

	if (len == 2)
		return tab[0] < tab[1] ? tab[0] : tab[1];
	if (len % 2 != 0)
		res = tab[len / 10];
	else
		res = tab[(len + 1) / 10];
	free(tab);
	tab = NULL;
	return (res);
}

void sort_2(t_list **lst_to_sort, t_list **other)
{
	process_command("sa", lst_to_sort, other, 1);
}

void sort_3(t_list **list_to_sort, t_list **other)
{
	int a = *((int *)(*list_to_sort)->content);
	int b = *((int *)(*list_to_sort)->next->content);
	int c = *((int *)(*list_to_sort)->next->next->content);

	if (c > a && c > b) // c = max
		process_command("sa", list_to_sort, other, 1);
	else if (a < b && a < c) // a = min
	{
		process_command("rra", list_to_sort, other, 1);
		process_command("sa", list_to_sort, other, 1);
	}

	if (ft_lstsorted(list_to_sort))
		return;

	if (a > b && a > c) // a = max
		process_command("ra", list_to_sort, other, 1);

	if (ft_lstsorted(list_to_sort))
		return;

	if (c < a && c < b && a > b)
		process_command("sa", list_to_sort, other, 1);

	if (!ft_lstsorted(list_to_sort))
		process_command("rra", list_to_sort, other, 1);
}

int lst_get_index(t_list **lst, int value)
{
	t_list *it;
	int i;
	if (!lst || !(*lst))
		return (-1);
	i = 0;
	it = *lst;
	while (it)
	{
		if (ft_lstgetvalue(&it) == value)
			return (i);
		it = it->next;
		i++;
	}
	return (-1);
}

void move_median_to_head(t_list **list_to_sort, t_list **other)
{
	int median = ft_get_median(list_to_sort);
	int min_index = lst_get_index(list_to_sort, median);
	int len = ft_lstlen(list_to_sort);
	char *cmd;

	if (min_index == 1)
	{
		if (ft_lstgetvalue(list_to_sort) < median)
		{
			process_command("pb", list_to_sort, other, 1);
			//if (ft_lstgetvalue(other) < *((int *)ft_lstgetindex(other, ft_lstlen(other) - 1)->content))
			//process_command("rb", list_to_sort, other, 1);
		}
		else
			process_command("sa", list_to_sort, other, 1);
	}
	else
	{
		if ((len - min_index + 1.0) > len / 2.0)
			cmd = ft_strdup("ra");
		else
			cmd = ft_strdup("rra");

		while ((*(int *)(*list_to_sort)->content) != median)
		{
			if (ft_lstgetvalue(list_to_sort) < median)
			{
				process_command("pb", list_to_sort, other, 1);
				//if (ft_lstgetvalue(other) < *((int *)ft_lstgetindex(other, ft_lstlen(other) - 1)->content))
				//process_command("rb", list_to_sort, other, 1);
			}
			else
				process_command(cmd, list_to_sort, other, 1);
		}
		ft_strdel(&cmd);
	}
}

void move_max_to_head(t_list **list_to_sort, t_list **other)
{
	int max = ft_lstgetmax(other);
	int min_index = lst_get_index(other, max);
	int len = ft_lstlen(other);
	char *cmd;

	if (min_index == 1)
		process_command("sb", list_to_sort, other, 1);
	else
	{
		if ((len - min_index + 1.0) > len / 2.0)
			cmd = ft_strdup("rb");
		else
			cmd = ft_strdup("rrb");

		while ((*(int *)(*other)->content) != max)
			process_command(cmd, list_to_sort, other, 1);
		ft_strdel(&cmd);
	}
}

void move_min_to_head(t_list **list_to_sort, t_list **other)
{
	int min = ft_lstgetmin(list_to_sort);
	int min_index = ft_lstgetminindex(list_to_sort);
	int len = ft_lstlen(list_to_sort);
	char *cmd;

	if (min_index == 1)
		process_command("sa", list_to_sort, other, 1);
	else
	{

		if ((len - min_index + 1.0) > len / 2.0)
			cmd = ft_strdup("ra");
		else
			cmd = ft_strdup("rra");

		while ((*(int *)(*list_to_sort)->content) != min)
			process_command(cmd, list_to_sort, other, 1);
		ft_strdel(&cmd);
	}
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

	// sleep(1);
	// display("la : ", list_to_sort);
	// display("lb : ", other);
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

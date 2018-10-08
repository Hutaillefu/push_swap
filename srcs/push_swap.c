#include "push_swap.h"

#include <stdio.h>

//static int cpt = 0;

int	ft_lstgetvalue(t_list **lst)
{
	return ((*(int *)(*lst)->content));
}

void	sort_2(t_list **lst_to_sort, t_list **other)
{
	process_command("sa", lst_to_sort, other, 1);
}

void	sort_3(t_list **list_to_sort, t_list **other)
{
	int a = *((int *)(*list_to_sort)->content);
	int b = *((int *)(*list_to_sort)->next->content);
	int c = *((int *)(*list_to_sort)->next->next->content);

	if (c > a && c > b)		// c = max
		process_command("sa", list_to_sort, other, 1);
	else if (a < b && a < c)	// a = min
	{
		process_command("rra", list_to_sort, other, 1);
		process_command("sa", list_to_sort, other, 1);
	}

	if (ft_lstsorted(list_to_sort))
		return ;

	if (a > b && a > c)	// a = max
		process_command("ra", list_to_sort, other, 1);

	if (ft_lstsorted(list_to_sort))
		return ;

	if (c < a && c < b && a > b)
		process_command("sa", list_to_sort, other, 1);

	if (!ft_lstsorted(list_to_sort))
		process_command("rra", list_to_sort, other, 1);
}

void	move_min_to_head(t_list **list_to_sort, t_list **other)
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

int	check_rotate(t_list **list_to_sort, t_list **other)
{
	if (can_rotate(list_to_sort))
	{
		//printf("CAN ROTATE\n");
		move_min_to_head(list_to_sort, other);
		return (1);
	}
	return (0);

}

void	sort_4(t_list **list_to_sort, t_list **other)
{
	if (ft_lstlen(list_to_sort) >= 4 &&
		ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->next->content) &&
		ft_lstgetmin(list_to_sort) == (*(int *)(*list_to_sort)->content) &&
		ft_lstsorted(&(*list_to_sort)->next->next)) // min max sorted
	{
		process_command("sa", list_to_sort, other, 1);
		process_command("ra", list_to_sort, other, 1);	
		return ;
	}

	if (ft_lstgetmax(list_to_sort) ==(*(int *)(*list_to_sort)->content) && ft_lstsorted(&(*list_to_sort)->next))
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

void	sort_n(t_list **list_to_sort, t_list **other)
{
	if (ft_lstgetmax(list_to_sort) ==(*(int *)(*list_to_sort)->content) && ft_lstsorted(&(*list_to_sort)->next)) // max sorted
	{
		process_command("ra", list_to_sort, other, 1);
		return ;
	}

	if (ft_lstlen(list_to_sort) >= 4 &&
		ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->next->content) &&
		ft_lstgetmin(list_to_sort) == (*(int *)(*list_to_sort)->content) &&
		ft_lstsorted(&(*list_to_sort)->next->next)) // min max sorted
	{
		process_command("sa", list_to_sort, other, 1);
		process_command("ra", list_to_sort, other, 1);
		return ;
	}

	if (check_rotate(list_to_sort, other))
		return ;

	move_min_to_head(list_to_sort, other);

	if (ft_lstsorted(list_to_sort))
		return ;

	if (ft_lstlen(list_to_sort) >= 4 &&
		ft_lstgetmax(list_to_sort) == (*(int *)(*list_to_sort)->next->content) &&
		ft_lstgetmin(list_to_sort) == (*(int *)(*list_to_sort)->content) &&
		ft_lstsorted(&(*list_to_sort)->next->next)) // min max sorted
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

int	main(int argc, char **argv)
{
	t_list	*la = NULL;
	t_list	*lb = NULL;

	if (argc == 1)
		return (0);

	argv++;

	while (*argv)
	{
		if (!process_param(&la, *argv))
		{
			ft_putstr_fd("Error", 2);
			//free la
			return (0);
		}
		argv++;
	}

	//display("la : ", &la);

	if (ft_lstsorted(&la))
		return (0);

	int len = ft_lstlen(&la);
	//printf("len : %d\n", len);

	if (len == 2)
		sort_2(&la, &lb);
	else if (len == 3)
		sort_3(&la, &lb);
	else if (len == 4)
		sort_4(&la, &lb);
	else 
		sort_n(&la, &lb);

	//printf("NB ACTIONS : %d\n", cpt); 

	return (0);
}

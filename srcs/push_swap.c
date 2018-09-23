#include "push_swap.h"

#include <stdio.h>

static int cpt = 0;

int	ft_lstgetvalue(t_list **lst)
{
	return ((*(int *)(*lst)->content));
}

void	sort_2(t_list **lst_to_sort, t_list **other)
{
	cpt = process_command("sa", lst_to_sort, other);
}

void	sort_3(t_list **list_to_sort, t_list **other)
{
	int a = *((int *)(*list_to_sort)->content);
	int b = *((int *)(*list_to_sort)->next->content);
	int c = *((int *)(*list_to_sort)->next->next->content);

	if (c > a && c > b)		// c = max
		cpt = process_command("sa", list_to_sort, other);
	else if (a < b && a < c)	// a = min
	{
		cpt = process_command("rra", list_to_sort, other);
		cpt = process_command("sa", list_to_sort, other);
	}

	if (ft_lstsorted(list_to_sort))
		return ;

	if (a > b && a > c)	// a = max
		cpt = process_command("ra", list_to_sort, other);

	if (ft_lstsorted(list_to_sort))
		return ;

	if (c < a && c < b && a > b)
		cpt = process_command("sa", list_to_sort, other);

	if (!ft_lstsorted(list_to_sort))
		cpt = process_command("rra", list_to_sort, other);
}

void	sort_4(t_list **list_to_sort, t_list **other)
{
	int min = ft_lstgetmin(list_to_sort);
	int min_index = ft_lstgetminindex(list_to_sort) + 1;
	int len = ft_lstlen(list_to_sort);
	char *cmd;

	int canrotate = can_rotate(list_to_sort);

	if (canrotate == 1)
	{
		printf("CAN ROTATE\n");
		while ((*(int *)(*list_to_sort)->content) != min)
			cpt = process_command("rra", list_to_sort, other);
		return ;
	}


	if (min_index == 1)
		cpt = process_command("sa", list_to_sort, other);
	else
	{

		if ((len - min_index + 1.0) > len / 2.0)
			cmd = ft_strdup("ra");
		else 
			cmd = ft_strdup("rra");

		while ((*(int *)(*list_to_sort)->content) != min)
			cpt = process_command(cmd, list_to_sort, other);
	}

	if (ft_lstsorted(list_to_sort))
		return ;

	cpt = process_command("pb", list_to_sort, other);
	sort_3(list_to_sort, other);
	cpt = process_command("pa", list_to_sort, other);
}

void	sort_n(t_list **list_to_sort, t_list **other)
{
	int min = ft_lstgetmin(list_to_sort);
	int min_index = ft_lstgetminindex(list_to_sort) + 1;
	int len = ft_lstlen(list_to_sort);
	char *cmd;

	printf("ESFSF %d\n", min_index);

	int canrotate = can_rotate(list_to_sort);
	//int canrotateindex = can_rotate_index(list_to_sort);

	if (canrotate == 1)
	{
		printf("CAN ROTATE\n");
		while ((*(int *)(*list_to_sort)->content) != min)
			cpt = process_command("rra", list_to_sort, other);
		return ;
	}
	
	if (min_index == 1)
		cpt = process_command("sa", list_to_sort, other);
	else
	{
		if ((len - min_index + 1.0) > len / 2.0)
			cmd = ft_strdup("ra");
		else 
		cmd = ft_strdup("rra");
		while ((*(int *)(*list_to_sort)->content) != min)
			cpt = process_command(cmd, list_to_sort, other);
	}

	if (ft_lstsorted(list_to_sort))
		return ;

	cpt = process_command("pb", list_to_sort, other);

	if (ft_lstlen(list_to_sort) == 4)
		sort_4(list_to_sort, other);
	else 
		sort_n(list_to_sort, other);
	cpt = process_command("pa", list_to_sort, other);
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
		process_param(&la, *argv);
		argv++;
	}

	display("la : ", &la);

	if (ft_lstsorted(&la))
	{
		printf("already sorted\n");
		return (0);
	}

	int len = ft_lstlen(&la);
	printf("len : %d\n", len);

	if (len == 2)
		sort_2(&la, &lb);
	else if (len == 3)
		sort_3(&la, &lb);
	else if (len == 4)
		sort_4(&la, &lb);
	else 
		sort_n(&la, &lb);

	printf("NB ACTIONS : %d\n", cpt); 

	return (0);
}

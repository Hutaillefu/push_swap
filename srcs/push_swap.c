#include "push_swap.h"

#include <stdio.h>

int	ft_lstgetvalue(t_list **lst)
{
	return ((*(int *)(*lst)->content));
}

void	sort_2(t_list **lst_to_sort, t_list **other)
{
	printf("sorting list of 2\n");
	process_command("sa", lst_to_sort, other);
}

void	sort_3(t_list **list_to_sort, t_list **other)
{
	printf("sorting list of 3\n");

	int a = *((int *)(*list_to_sort)->content);
	int b = *((int *)(*list_to_sort)->next->content);
	int c = *((int *)(*list_to_sort)->next->next->content);

	if (c > a && c > b)		// c = max
		process_command("sa", list_to_sort, other);
	else if (a < b && a < c)	// a = min
	{
		process_command("rra", list_to_sort, other);
		process_command("sa", list_to_sort, other);
	}

	if (ft_lstsorted(list_to_sort))
		return ;

	 if (a > b && a > c)	// a = max
 		 process_command("ra", list_to_sort, other);

	if (ft_lstsorted(list_to_sort))
		return ;

	if (c < a && c < b && a > b)
		process_command("sa", list_to_sort, other);
	
	if (!ft_lstsorted(list_to_sort))
	 	process_command("rra", list_to_sort, other);
}

void	sort_4(t_list **list_to_sort, t_list **other)
{
	printf("sorting list of 4\n");

	int min = ft_lstgetmin(list_to_sort);
	int min_index = ft_lstgetminindex(list_to_sort) + 1;
	int len = ft_lstlen(list_to_sort);
	char *cmd;

	printf("min index %d on %d len\n", min_index, len);

	if ((len - min_index + 1.0) > len / 2.0)
		cmd = ft_strdup("ra");
	else 
		cmd = ft_strdup("rra");

	while ((*(int *)(*list_to_sort)->content) != min)
		process_command(cmd, list_to_sort, other);
	if (ft_lstsorted(list_to_sort))
		return ;

	process_command("pb", list_to_sort, other);
	sort_3(list_to_sort, other);
	process_command("pa", list_to_sort, other);
}

void	sort_n(t_list **list_to_sort, t_list **other)
{
	printf("sorting list of n\n");

	int min = ft_lstgetmin(list_to_sort);
	int min_index = ft_lstgetminindex(list_to_sort) + 1;
	int len = ft_lstlen(list_to_sort);
	char *cmd;

	printf("min index %d on %d len\n", min_index, len);

	if ((len - min_index + 1.0) > len / 2.0)
		cmd = ft_strdup("ra");
	else 
		cmd = ft_strdup("rra");

	while ((*(int *)(*list_to_sort)->content) != min)
		process_command(cmd, list_to_sort, other);
	process_command("pb", list_to_sort, other);

	if (ft_lstlen(list_to_sort) == 4)
		sort_4(list_to_sort, other);
	else 
		sort_n(list_to_sort, other);
	process_command("pa", list_to_sort, other);
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

	return (0);
}

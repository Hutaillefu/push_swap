#include "push_swap.h"

#include <stdio.h>

int		ft_lstsorted(t_list **list)
{
	t_list	*it;

	if (!list || !(*list))
		return (0);

	it = *list;
	while (it && it->next)
	{
		if ((*(int *)it->next->content) < (*(int *)it->content))
			return (0);
		it = it->next;
	}
	return (1);
}

void	process_param(t_list **list, char *param)
{
	int value;

	if (!list || !param)
		return;
	// Verif doublon, ...
	value = ft_atoi(param);

	ft_lstpush(list, ft_lstnew(&value, sizeof(value)));
}

void	process_command(char *command, t_list **la, t_list **lb)
{
	if (!command || !la || !lb)
		return ;
	if (ft_strcmp(command, "sa") == 0)
		swap_two_first(la);
	else if (ft_strcmp(command, "sb") == 0)
		swap_two_first(lb);
	else if (ft_strcmp(command, "ss") == 0)
	{
		swap_two_first(la);
		swap_two_first(lb);
	}
	else if (ft_strcmp(command, "pa") == 0)
		move_sommet(lb, la);
	else if (ft_strcmp(command, "pb") == 0)
		move_sommet(la, lb);
	else if (ft_strcmp(command, "ra") == 0)
		rotate_up(la);
	else if (ft_strcmp(command, "rb") == 0)
		rotate_up(lb);
			else if (ft_strcmp(command, "rr") == 0)
	{
		rotate_up(la);
		rotate_up(lb);
	}
	else if (ft_strcmp(command, "rra") == 0)
		rotate_down(la);
	else if (ft_strcmp(command, "rrb") == 0)
		rotate_down(lb);
			else if (ft_strcmp(command, "rrr") == 0)
	{
		rotate_down(la);
		rotate_down(lb);
	}
}

int		main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;
	char	*line;
	
	if (argc == 1)
		return (0);

	argv++;
	lb = NULL;
	while (argv && *argv)
	{
		process_param(&la, *argv);
		argv++;		
	}

	while (get_next_line(0, &line))
	{
		process_command(line, &la, &lb);
	}

	if (ft_lstsorted(&la) && lb == NULL)
		printf("OK\n");
	else
		printf("KO\n");

	while (la)
	{
		printf("%d\n", (*(int *)la->content));
		la = la->next;
	}

	return (0);
}
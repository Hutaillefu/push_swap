#include "push_swap.h"

#include <stdio.h>

void		display(const char *tag, t_list **lst)
{
	t_list *it;
	if (!lst)
		return ;
	printf("%s", tag);
	if (!(*lst))
		printf("----------\n");
	it = *lst;
	while (it)
	{
		printf("%d ", (*(int *)it->content));
		it = it->next;
	}
	printf("\n");
}

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
	display("la : ", la);
	display("lb : ", lb);
	printf("\n");

}

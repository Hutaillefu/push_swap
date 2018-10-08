#include "push_swap.h"

#include <stdio.h>

t_list		*duplicate(t_list **lst)
{
	t_list	*list = NULL;
	t_list	*it;

	if (!lst || !(*lst))
		return (NULL);
	it = *lst;
	while (it)
	{
		int c;
		c = (*(int *)it->content);
		ft_lstpush(&list, ft_lstnew(&c, sizeof(c)));
	}
	return list;
}

void	display(const char *tag, t_list **lst)
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

int		ft_lstlen(t_list **lst)
{
	t_list *it;
	int res;
	if (!lst || !(*lst))
		return (0);
	res = 1;
	it = *lst;
	while (it->next)
	{
		it = it->next;
		res++;
	}
	return (res);
}

int		ft_lstgetmax(t_list **lst)
{
	t_list	*it;
	int	max;

	if (!lst || !(*lst))
		return (0);
	max =(*(int *) (*lst)->content);
	it = (*lst)->next;
	while (it)
	{
		if ((*(int *)it->content) > max)
			max = (*(int *)it->content);
		it = it->next;
	}
	return (max);
}

int		ft_lstgetmin(t_list **lst)
{
	t_list	*it;
	int	min;

	if (!lst || !(*lst))
		return (0);
	min =(*(int *) (*lst)->content);
	it = (*lst)->next;
	while (it)
	{
		if ((*(int *)it->content) < min)
			min = (*(int *)it->content);
		it = it->next;
	}
	return (min);
}

int		ft_lstgetminindex(t_list **lst)
{
	t_list	*it;
	int	minindex;
	int	min;
	int	index;

	if (!lst || !(*lst))
		return (-1);
	min =(*(int *) (*lst)->content);
	minindex = 0;
	index = 0;
	it = *lst;
	while (it)
	{
		if ((*(int *)it->content) < min)
		{
			minindex = index;
			min = (*(int *)it->content);
		}
		it = it->next;
		index++;
	}
	return (minindex);
}

int		can_rotate(t_list **lst)
{
	t_list	*it;
	int nb = 0;
	int first = (*(int *)(*lst)->content);
	it = *lst;
	while (it && it->next)
	{
		if ((*(int *)it->next->content) < (*(int *)it->content))
		{
			if (nb == 1)
				return (0);
			if (it->next->next != NULL && (*(int *)it->next->content) < first )
				nb++;
		}
		else if (nb == 1)
			return (0);
		it = it->next;
	}
	return nb;
}

int		can_rotate_index(t_list **lst)
{
	t_list	*it;
	int nb = 0;
	int index = 0;
	int curr_index = 0;

	it = *lst;
	while (it && it->next)
	{
		if ((*(int *)it->next->content) < (*(int *)it->content))
		{
			curr_index = index;
			nb++;
		}
		index++;
		it = it->next;
	}
	return curr_index;
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

int		ft_lstinversed(t_list **list)
{
	t_list	*it;

	if (!list || !(*list))
		return (0);

	it = *list;
	while (it && it->next)
	{
		if ((*(int *)it->next->content) > (*(int *)it->content))
			return (0);
		it = it->next;
	}
	return (1);
}

int		ft_lstvaluebreak(t_list **list)
{
	t_list	*it;
//	int res = 0;

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

int		ft_lstdoublon(t_list **lst, int value)
{
	t_list	*it;
	if (!lst || !(*lst))
		return (0);
	it = *lst;
	while (it)
	{
		if ((*(int *)it->content) == value)
			return (1);
		it = it->next;
	}
	return (0);
}

int		process_param(t_list **list, char *param)
{
	long value;

	if (!list || !param)
		return (0);
	value = ft_atoi(param);
	if (value > 2147483647 || (value == 0 && ft_strcmp(param, "0") != 0) || ft_lstdoublon(list, value))
		return (0);
	
	ft_lstpush(list, ft_lstnew(&value, sizeof(value)));
	return (1);
}

static int cpt = 0;

int	process_command(char *command, t_list **la, t_list **lb, int display)
{
	if (!command || !la || !lb)
		return 0;
		
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
	else
		return (0);
	
	if (display)
		printf("%s\n", command);

	/*display("la : ", la);
	display("lb : ", lb);
	printf("\n");*/
	
	cpt++;
	return (1);

}

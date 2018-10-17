/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
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

int		can_rotate(t_list **lst)
{
	t_list	*it;
	int		nb;
	int		first;

	nb = 0;
	it = *lst;
	first = (*(int *)(*lst)->content);
	while (it && it->next)
	{
		if ((*(int *)it->next->content) < (*(int *)it->content))
		{
			if (nb == 1)
				return (0);
			if (it->next->next != NULL && (*(int *)it->next->content) < first)
				nb++;
		}
		else if (nb == 1)
			return (0);
		it = it->next;
	}
	return (nb);
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
	long	value;
	t_list	*tmp;

	if (!list || !param)
		return (0);
	value = ft_atoi(param);
	if (value > 2147483647 || (value == 0 && ft_strcmp(param, "0") != 0) ||
	ft_lstdoublon(list, value))
		return (0);
	if (!(tmp = ft_lstnew(&value, sizeof(value))))
		return (0);
	ft_lstpush(list, tmp);
	return (1);
}

int		init_param(t_list **la, char **argv)
{
	while (argv && *argv)
	{
		if (!process_param(la, *argv))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		argv++;
	}
	return (1);
}

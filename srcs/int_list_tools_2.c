/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   int_list_tools_2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 14:08:49 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 14:08:51 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void		free_maillon(void *content, size_t size)
{
	(void)size;
	free(content);
	content = NULL;
}

void			free_list(t_list **lst)
{
	if (!lst || !(*lst))
		return ;
	ft_lstdel(lst, free_maillon);
	lst = NULL;
}

int				ft_lstgetmax(t_list **lst)
{
	t_list	*it;
	int		max;

	if (!lst || !(*lst))
		return (0);
	max = (*(int *)(*lst)->content);
	it = (*lst)->next;
	while (it)
	{
		if ((*(int *)it->content) > max)
			max = (*(int *)it->content);
		it = it->next;
	}
	return (max);
}

int				ft_lstgetmin(t_list **lst)
{
	t_list	*it;
	int		min;

	if (!lst || !(*lst))
		return (0);
	min = (*(int *)(*lst)->content);
	it = (*lst)->next;
	while (it)
	{
		if ((*(int *)it->content) < min)
			min = (*(int *)it->content);
		it = it->next;
	}
	return (min);
}

int				ft_lstsorted(t_list **list)
{
	t_list *it;

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

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   int_list_tools.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 19:31:44 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 19:31:46 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_tab(int *tab, int len)
{
	int	i;
	int	tmp;

	if (!tab)
		return ;
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

int			ft_lstgetvalue(t_list **lst)
{
	return ((*(int *)(*lst)->content));
}

static int	*ft_lst_to_array(t_list **lst)
{
	int		*tab;
	t_list	*it;
	int		i;

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

int			ft_get_median(t_list **lst)
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
		res = (tab[0] < tab[1] ? tab[0] : tab[1]);
	else if (len % 2 != 0)
		res = tab[len / (ft_lstlen(lst) / 50 >= 5 ? ft_lstlen(lst) / 50 : 5)];
	else
		res = tab[(len + 1) / (ft_lstlen(lst) / 50 >= 5 ? ft_lstlen(lst) / 50
		: 5)];
	free(tab);
	tab = NULL;
	return (res);
}

int			lst_get_index(t_list **lst, int value)
{
	t_list	*it;
	int		i;

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

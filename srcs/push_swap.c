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

static void		free_lists(t_list **la, t_list **lb)
{
	free_list(la);
	free_list(lb);
}

static void		process(t_list **la, t_list **lb)
{
	int		len;

	len = ft_lstlen(la);
	if (len == 2)
		sort_2(la, lb);
	else if (len == 3)
		sort_3(la, lb);
	else if (len == 4)
		sort_4(la, lb);
	else if (len < 20)
		sort_n(la, lb);
	else
		sort_max(la, lb);
}

int				main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;

	la = NULL;
	lb = NULL;
	if (argc == 1)
		return (0);
	argv++;
	if (!init_param(&la, argv, argc))
	{
		free_lists(&la, &lb);
		return (0);
	}
	if (ft_lstsorted(&la))
	{
		free_lists(&la, &lb);
		return (0);
	}
	process(&la, &lb);
	free_lists(&la, &lb);
	return (0);
}

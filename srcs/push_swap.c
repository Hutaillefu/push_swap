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

static void		sort_max(t_list **la, t_list **lb)
{
	while (la && (*la) && ft_lstlen(la) > 1)
	{
		move_median_to_head(la, lb);
		process_command("pb", la, lb, 1);
	}
	while (ft_lstlen(lb) > 0)
	{
		move_max_to_head(la, lb);
		process_command("pa", la, lb, 1);
	}
}

static void		free_tmp(char **tmp)
{
	int i;

	if (!tmp || !(*tmp))
		return ;
	i = 0;
	while (tmp[i])
	{
		ft_strdel(&tmp[i]);
		i++;
	}
	tmp = NULL;
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
	char	**tmp;
	int		fr;

	la = NULL;
	lb = NULL;
	tmp = NULL;
	fr = 0;
	if (argc == 1)
		return (0);
	argv++;
	if (argc == 2)
	{
		fr = 1;
		if (!(tmp = ft_strsplit(*argv, ' ')))
			return (0);
	}
	else
		tmp = argv;
	if (!init_param(&la, tmp))
	{
		free_list(&la);
		free_list(&lb);
		if (fr)
			free_tmp(tmp);
		return (0);
	}
	if (fr)
		free_tmp(tmp);
	if (ft_lstsorted(&la))
	{
		free_list(&la);
		free_list(&lb);
		return (0);
	}
	process(&la, &lb);
	free_list(&la);
	free_list(&lb);
	return (0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:26:31 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:26:37 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void		free_var(t_list **la, t_list **lb, t_list **actions,
	char **line)
{
	free_list(la);
	free_list(lb);
	free_list(actions);
	ft_strdel(line);
}

static void		main_2(t_list **la, t_list **lb, t_list **actions)
{
	if (ft_lstsorted(la) && (*lb) == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_var(la, lb, actions, NULL);
}

static int		process(t_list **la, t_list **lb, t_list **actions)
{
	t_list *it;

	it = *actions;
	while (it)
	{
		if (!process_command((char *)(it->content), la, lb, 0))
		{
			ft_putstr_fd("Error\n", 2);
			free_var(la, lb, actions, NULL);
			return (0);
		}
		it = it->next;
	}
	return (1);
}

static int		read_param(t_list **la, t_list **lb, t_list **actions)
{
	char	*line;
	t_list	*new;

	line = NULL;
	new = NULL;
	while (get_next_line(0, &line))
	{
		if (!line || !is_action(line) || !(new = ft_lstnew(line, sizeof(line))))
		{
			free_var(la, lb, actions, &line);
			return (0);
		}
		ft_lstpush(actions, new);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}

int				main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;
	t_list	*actions;

	if (argc == 1)
		return (0);
	la = NULL;
	lb = NULL;
	actions = NULL;
	if (!init_param(&la, ++argv, argc))
	{
		free_list(&la);
		return (0);
	}
	if (!read_param(&la, &lb, &actions))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!process(&la, &lb, &actions))
		return (0);
	main_2(&la, &lb, &actions);
	return (0);
}

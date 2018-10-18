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

static void		free_var(t_list **la, char **line)
{
	free_list(la);
	ft_strdel(line);
}

static void		main_2(t_list **la, t_list **lb, char **line)
{
	ft_strdel(line);
	if (ft_lstsorted(la) && (*lb) == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_list(la);
	free_list(lb);
}

int				main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;
	char	*line;

	if (argc == 1)
		return (0);
	la = NULL;
	lb = NULL;
	line = NULL;
	if (!init_param(&la, ++argv))
	{
		free_list(&la);
		return (0);
	}
	while (get_next_line(0, &line))
	{
		if (!line || !process_command(line, &la, &lb, 0))
		{
			ft_putstr_fd("Error\n", 2);
			free_var(&la, &line);
			return (0);
		}
	}
	main_2(&la, &lb, &line);
	return (0);
}

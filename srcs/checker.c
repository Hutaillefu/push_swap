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

int		init_param(t_list **la, char **argv)
{
	while (argv && *argv)
	{
		if (!process_param(la, *argv))
		{
			ft_putstr_fd("Error\n", 2);
			free_list(la);
			return (0);
		}
		argv++;
	}
	return (1);
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
	if (!init_param(&la, argv))
		return (0);
	while (get_next_line(0, &line))
	{
		if (!process_command(line, &la, &lb, 0))
		{
			ft_putstr_fd("Error\n", 2);
			free_list(&la);
			return (0);
		}
	}
	if (ft_lstsorted(&la) && lb == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}

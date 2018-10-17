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

int		main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;
	char	*line;
	int		res;

	if (argc == 1)
		return (0);
	argv++;
	la = NULL;
	lb = NULL;
	line = NULL;
	if (!init_param(&la, argv))
	{
		free_list(&la);
		return (0);
	}
	while ((res = get_next_line(0, &line)))
	{
		if (!line || res == -1 || !process_command(line, &la, &lb, 0))
		{
			ft_putstr_fd("Error\n", 2);
			free_list(&la);
			ft_strdel(&line);
			return (0);
		}
	}
	ft_strdel(&line);
	if (ft_lstsorted(&la) && lb == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_list(&la);
	free_list(&lb);
	return (0);
}

#include "push_swap.h"

#include <stdio.h>

int		main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;
	char	*line;
	
	if (argc == 1)
		return (0);

	argv++;
	lb = NULL;
	while (argv && *argv)
	{
		process_param(&la, *argv);
		argv++;		
	}

	while (get_next_line(0, &line))
	{
		process_command(line, &la, &lb);
	}

	if (ft_lstsorted(&la) && lb == NULL)
		printf("OK\n");
	else
		printf("KO\n");

	while (la)
	{
		printf("%d\n", (*(int *)la->content));
		la = la->next;
	}

	return (0);
}

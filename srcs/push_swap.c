#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*la;
	//t_list	*lb;

	if (argc == 1)
		return (0);

	argv++;

	while (*argv)
	{
		process_param(&la, *argv);
		argv++;
	}

	display("la : ", &la);

	return (0);
}

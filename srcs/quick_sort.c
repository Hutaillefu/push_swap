#include <stdlib.h>
#include <stdio.h>

static int nb = 10;

void	swap(int **values, int first, int second)
{
	int c;

	if (first == second)
		return ;
	printf("swaping %d & %d\n", (*values)[first], (*values)[second]);

	c = (*values)[first];
	(*values)[first] = (*values)[second];
	(*values)[second] = c;
}


void	display(int *values)
{
	int i;

	i = 0;
	while (i < nb)
	{
		printf("%d ", values[i]);
		i++;
	}
	printf("\n");
}

int	partitionner(t_list **values, int first, int second, int pivot)
{
	int i, j;

	swap(values, pivot, second);
	display(*values);
	i = first;
	j = first;
	while (i < second)
	{
		if ((*values)[i] <= (*values)[second])
		{
			swap(values, i, j);
			display(*values);
			j++;
		}
		i++;
	}
	swap(values, second, j);
	display(*values);
	return (j);
}

void	quick_sort(t_list **values, int first, int second)
{
	int pivot;


	if (first < second)
	{
		//printf("sorting between index %d & %d\n", first, second);
		pivot = first;
		pivot = partitionner(values, first, second, pivot);
		quick_sort(values, first, pivot - 1);
		quick_sort(values, pivot + 1, second);
	}
}


int	main(void)
{
	int *values = (int *)malloc(sizeof(int) * nb);
	values[0] = 3;
	values[1] = 7;
	values[2] = 8;
	values[3] = 10;
	values[4] = 5;
	values[5] = 1;
	values[6] = 9;
	values[7] = 4;
	values[8] = 0;
	values[9] = 2;

	display(values);

	quick_sort(&values, 0, nb - 1);

//	display(values);

	return (0);
}

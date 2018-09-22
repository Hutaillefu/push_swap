#include "libft.h"

t_list	*ft_lstgetindex(t_list **lst, int index)
{
	int i;
	t_list	*iterator;

	if (index < 0 || !lst || !(*lst))
		return (NULL);

	i = 0;
	iterator = *lst;
	while (i != index && iterator->next)
	{
		iterator = iterator->next;
		i++;
	}
	if (i == index)
		return (iterator);
	return (NULL);
}

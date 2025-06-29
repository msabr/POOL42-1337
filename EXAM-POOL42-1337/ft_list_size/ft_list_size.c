#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list *list = begin_list;
	int index = 0;

	while (list)
	{
		list = list->next;
		index++;
	}
	return (index);
}
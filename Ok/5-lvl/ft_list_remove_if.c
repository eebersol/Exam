#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*list;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	list = *begin_list;
	while (list)
	{
		if (!list->next)
			break ;
		if (cmp(list->next->data, data_ref) == 0)
		{
			tmp = list->next;
			list->next = tmp->next;
			free(tmp);
		}
		list = list->next;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:34:40 by msabr             #+#    #+#             */
/*   Updated: 2025/07/29 19:38:04 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem)
	{
		elem->data = data;
		elem->next = NULL;
	}
	return (elem);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new_elem;
	t_list	*curr;

	new_elem = ft_create_elem(data);
	if (!new_elem)
		return ;
	if (!*begin_list || (*cmp)(data, (*begin_list)->data) < 0)
	{
		new_elem->next = *begin_list;
		*begin_list = new_elem;
		return ;
	}
	curr = *begin_list;
	while (curr->next && (*cmp)(data, curr->next->data) >= 0)
		curr = curr->next;
	new_elem->next = curr->next;
	curr->next = new_elem;
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	t_list	*curr2;

	curr2 = begin_list2;
	while (curr2)
	{
		ft_sorted_list_insert(begin_list1, curr2->data, cmp);
		curr2 = curr2->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:37:08 by msabr             #+#    #+#             */
/*   Updated: 2025/07/29 19:44:17 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap_at_indices(t_list *begin_list, int i, int j)
{
	t_list	*first;
	t_list	*second;
	int		k;
	void	*tmp;

	first = begin_list;
	second = begin_list;
	k = 0;
	while (k < i)
	{
		first = first->next;
		k++;
	}
	k = 0;
	while (k < j)
	{
		second = second->next;
		k++;
	}
	tmp = first->data;
	first->data = second->data;
	second->data = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	t_list	*curr;

	size = 0;
	curr = begin_list;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	i = 0;
	while (i < size / 2)
	{
		swap_at_indices(begin_list, i, size - i - 1);
		i++;
	}
}

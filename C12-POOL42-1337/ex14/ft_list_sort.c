/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:37:01 by msabr             #+#    #+#             */
/*   Updated: 2025/07/29 19:37:04 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*curr;
	t_list	*next;
	void	*tmp;

	if (!begin_list || !*begin_list)
		return ;
	curr = *begin_list;
	while (curr)
	{
		next = curr->next;
		while (next)
		{
			if ((*cmp)(curr->data, next->data) > 0)
			{
				tmp = curr->data;
				curr->data = next->data;
				next->data = tmp;
			}
			next = next->next;
		}
		curr = curr->next;
	}
}

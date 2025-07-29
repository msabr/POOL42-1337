/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:34:15 by msabr             #+#    #+#             */
/*   Updated: 2025/07/29 19:36:55 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*prev;
	t_list	*tmp;

	curr = *begin_list;
	prev = 0;
	while (curr)
	{
		if ((*cmp)(curr->data, data_ref) == 0)
		{
			tmp = curr->next;
			if (free_fct)
				free_fct(curr->data);
			if (prev)
				prev->next = tmp;
			else
				*begin_list = tmp;
			curr = tmp;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

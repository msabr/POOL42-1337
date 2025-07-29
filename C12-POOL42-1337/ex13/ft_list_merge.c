/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:34:27 by msabr             #+#    #+#             */
/*   Updated: 2025/07/29 19:34:29 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*last;

	if (!*begin_list1)
		*begin_list1 = begin_list2;
	else
	{
		last = *begin_list1;
		while (last->next)
			last = last->next;
		last->next = begin_list2;
	}
}

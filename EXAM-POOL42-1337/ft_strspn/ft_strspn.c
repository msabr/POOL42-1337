/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:57:26 by msabr             #+#    #+#             */
/*   Updated: 2024/08/13 16:57:28 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

size_t			ft_strspn(const char *s, const char *accept)
{
    size_t i;
    size_t j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (s[j])
        {
            if (accept[j] == s[i])
                break;
            j++;
        }
        if (!s[j])
            break;
        i++;
    }
    return (i);
}
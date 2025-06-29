/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:19:47 by msabr             #+#    #+#             */
/*   Updated: 2025/06/15 16:07:24 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char cherstr(char *str, int firststr)
{
    while (*str)
    {
        if (*str == (char)firststr)
            return ((char *)str);
        str++;
    }
    if (*str == (char)firststr)
        return ((char *)str);
    return (NULL);
}


size_t  ft_strcspn(const char *s, const char *reject)
{
    size_t res;

    res = 0;
    while (*s)
    {
        if (cherstr(reject,*s))
            return (res);
        res++;
        s++;
    }
    return (res);
}
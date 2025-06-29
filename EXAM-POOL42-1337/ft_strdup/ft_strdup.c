/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:14:14 by msabr             #+#    #+#             */
/*   Updated: 2024/08/02 00:20:43 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i;
	int len;
	char *srcopy;

	len = 0;
	while (src[len])
		len++;
	srcopy = malloc(len + 1);
	if (srcopy != NULL)
	{
		i = 0;
		while (src[i])
		{
			srcopy[i] = src[i];
			i++;
		}
		srcopy[i] = '\0';
	}
	return (srcopy);
}

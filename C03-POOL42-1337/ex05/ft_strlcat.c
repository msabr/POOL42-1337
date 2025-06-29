/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:50:33 by msabr             #+#    #+#             */
/*   Updated: 2024/08/10 23:20:08 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

unsigned int	ft_strlen(char *src)
{
	unsigned int	l;

	l = 0;
	while (src[l] != '\0')
	{
		l++;
	}
	return (l);
}

char	*ft_strncat(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		len;

	i = 0;
	j = 0;
	len = ft_strlen(dest);
	while (dest[i])
	{
		i++;
	}
	while (src[j] && (j < size - 1 - len))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		lensrc;
	unsigned int		lendest;

	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	if (size <= lendest)
		return (lensrc + size);
	dest = ft_strncat(dest, src, size);
	return (lensrc + lendest);
}

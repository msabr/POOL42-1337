/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:14:51 by msabr             #+#    #+#             */
/*   Updated: 2024/08/12 19:14:56 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	t;
	int	count;

	i = 0;
	t = 1;
	count = 0;
	while (str[i] && is_charset(str[i], charset) == 1)
		i++;
	while (str[i])
	{
		if ((is_charset(str[i], charset) == 0) && (t == 1))
		{
			count++;
			t = 0;
		}
		else if (is_charset(str[i], charset) == 1)
		{
			t = 1;
		}
		i++;
	}
	return (count);
}

int	rempir_split(char *dest, char *src, int index, char *charset)
{
	int	i;

	i = 0;
	while (src[i] && (is_charset(src[index], charset) == 0))
	{
		dest[i] = src[index];
		i++;
		index++;
	}
	dest[i] = '\0';
	return (index);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		count;
	int		indice;
	char	**pnt;

	i = 0;
	indice = 0;
	count = count_words(str, charset);
	pnt = (char **)malloc(sizeof(char *) * (count + 1));
	if (pnt == NULL)
		return (NULL);
	while (indice < count)
	{
		while (is_charset(str[i], charset) == 1)
			i++;
		j = 0;
		while (str[i + j] && is_charset(str[i + j], charset) == 0)
			j++;
		pnt[indice] = (char *)malloc(sizeof(char) * (j + 1));
		i = rempir_split(pnt[indice], str, i, charset);
		indice++;
	}
	pnt[count] = NULL;
	return (pnt);
}

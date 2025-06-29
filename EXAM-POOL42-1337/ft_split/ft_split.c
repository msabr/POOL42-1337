/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:53:51 by msabr             #+#    #+#             */
/*   Updated: 2024/08/12 13:03:20 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int is_speace(char c)
{
    if (c == '\n' || c == '\t' || c == '\f' || c == '\v' || c == '\r' || c == ' ')
        return (1);
    else
        return (0);
}

int count_words(char *str)
{
    int i;
    int t;
    int count;

    i = 0;
    t = 1;
    count = 0;
    while (str[i] && is_speace(str[i]) == 1)
        i++;
    while (str[i])
    {
        if ((is_speace(str[i]) == 0) && (t == 1))
        {
            count++;
            t = 0;
        }
        else if (is_speace(str[i]) == 1)
        {
            t = 1;
        }
        i++;
    }
    return (count);
    
}

int rempir_split(char *dest, char *src, int index)
{
    int i;

    i = 0;
    while (src[index] && is_speace(src[index]) == 0)
    {
        dest[i] = src[index];
        i++;
        index++;
    }
    dest[i] = '\0';
    return (index);
}

char **ft_split(char *str)
{
    int i;
    int j;
    int count;
    int indice;
    char **pnt;

    i = 0;
    indice = 0;
    count = count_words(str);
    pnt = (char **)malloc(sizeof(char *) * (count + 1));
    while (indice < count)
    {
        while (is_speace(str[i]) == 1)
            i++;
        j = 0;
        while (str[i + j] && is_speace(str[i + j]) == 0)
            j++;
        pnt[indice] = (char *)malloc(sizeof(char) * (j + 1));
        i = rempir_split(pnt[indice],str,i);
        indice++;
    }
    pnt[indice] = 0;
    return (pnt);
}

int	main()
{
	int		index;
	char	**split;
	split = ft_split("sabir          is -+the best");
	index = 0;
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
}

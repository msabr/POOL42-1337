/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:39:08 by msabr             #+#    #+#             */
/*   Updated: 2024/08/08 10:39:10 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int        ft_abs(int x)
{
    if (x < 0)
        return (-x);
    return (x);
}

int     *ft_range(int start, int end)
{
    int *pnt;
    int size;
    int i;

    size = ft_abs(end - start);
    i = 0;
    pnt = (int *)malloc(size * sizeof(int));
    if (pnt == NULL)
        return (NULL);
    if (start < end)
    {
        while(i <= size)
        {
            pnt[i]= start + i;
            i++;
        }
    }
    else if (end < start)
    {
        while(i <= size)
        {
            pnt[i]= start - i;
            i++;
        }
    }
    
    return (pnt);
}

int	main(void)
{
	int	*arr;
	int	i;

	arr = ft_range(0, -3);
	i = 0;
	while (i <= 9)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
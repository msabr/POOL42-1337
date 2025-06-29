/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:30:21 by msabr             #+#    #+#             */
/*   Updated: 2024/08/14 17:30:23 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
    int i = 0;
    int j = 0;
    long nb;
    char *itoa;
    char c[11];

    nb = nbr;
    itoa = (char *)malloc(12 * sizeof(char));
    if (itoa == NULL)
        return (NULL);
    if (nb < 0)
    {
        nb *= -1;
        itoa[j++] = '-';
    }
    if (nb == 0)
    {
        itoa[j++] = '0';
    }
    while (nb > 0)
    {
        c[i++] = (nb % 10) + '0';
        nb = nb / 10;
    }
    while (i > 0)
    {
        itoa[j++] = c[--i];
        
    }
    itoa[j] = '\0';
    return (itoa);
}

int	main(void)
{
    int n = 1342345;
	printf("%s\n", ft_itoa(n));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:38:16 by msabr             #+#    #+#             */
/*   Updated: 2024/08/08 12:38:18 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int ft_strlen(char *str)
{
    int l = 0;
    while (str[l])
        l++;
    return (l);
}

char	*ft_strrev(char *str)
{
	int	j;
	int	len;
	char	temp;
    j = 0;
	len = ft_strlen(str);
    while(j < (len/2 ))
    {
        temp = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = temp;
        j++;
    }
    return (str);
}

#include <stdio.h>
int main()
{
    char p[] = "alaa";
    printf("%s\n",ft_strrev(p));
    return 0;
}
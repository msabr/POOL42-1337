/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:43:51 by msabr             #+#    #+#             */
/*   Updated: 2024/08/13 20:43:54 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


/*
int error(char *base)
{
    int i = 0;
    int j;

    if (base[0]=='\0' || base[1]=='\0')
        return (0);
    while (base[i])
    {
        if (base[i] == '+' || base[i] == '-')
            return (0);
        j = i + 1;
        while (base[j])
        {
            if (base[j] == base[i])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int check_index(char *base, char c)
{
    int i = 0;

    while (base[i])
    {
        if (base[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int res = 0;
    int signe = 1;
    int lenbase;

    lenbase = ft_strlen(str_base);
    if (error(str_base) == 1)
    {
        if (str[i] == '-')
        {
            signe = -1;
            i++;
        }
        while (str[i] && (check_index(str_base,str[i]) != -1))
        {
            res = res * lenbase + check_index(str_base,str[i]);
            i++;
        }
    }
    return (res * signe);
}*/

int	ft_strlen(char *str)
{
	int		l;

	l = 0;
	while (str[l] != '\0')
	{
		l++;
	}
	return (l);
}

int ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int check_index(char c,int str_base)
{
    char *base = "0123456789abcdef";
    char *base2 = "0123456789ABCDEF";
    int i = 0;

    while (i <= str_base)
    {
        if (base[i] == c || base2[i] == c)
            return (i);
        i++;
    }
    return (-1);
}


int		ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign = 1;
	int i = 0;

	result = 0;
	while (ft_isblank(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	while (check_index(str[i],str_base) != -1)
	{
		result = result * str_base + check_index(str[i],str_base);
		i++;
	}
	return (result * sign);
}


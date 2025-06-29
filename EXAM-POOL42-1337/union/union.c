/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:07:04 by msabr             #+#    #+#             */
/*   Updated: 2024/08/07 19:13:26 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int chek_double (char *str, char c, int pos)
{
    int  i = 0;
    while (i <pos)
    {
        if (str[i] == c)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int chek_double2 (char *str, char c)
{
    int  i = 0;
    while (str[i])
    {
        if (str[i] == c)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

void union_h (char *str1, char *str2)
{
    int i;
    int j;

    i= 0;
    while (str1[i])
    {
        if (chek_double(str1,str1[i],i))
        {
            write(1,&str1[i],1);
        }
        i++;
    }
    j= 0;
    while (str2[j])
    {
        if (chek_double2(str1,str2[j]) && chek_double(str2,str2[j],j))
        {
            write(1,&str2[j],1);
        }
        j++;
    }
}
int main (int ac, char **av)
{

    if (ac == 3)
    {
        union_h(av[1],av[2]);
    }
    write (1,"\n",1);
    return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:07:15 by msabr             #+#    #+#             */
/*   Updated: 2024/08/07 17:07:17 by msabr            ###   ########.fr       */
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

void inter (char *str1, char *str2)
{
    int i;
    int j;

    i= 0;
    j= 0;
    while (str1[i])
    {
        j = 0;
        while (str2[j])
        {
            if (str1[i] == str2[j])
            {
                if (chek_double(str1,str1[i],i))
                {
                    write(1,&str1[i],1);
                    break;
                }
            }
            j++;
        }
        i++;
    }
}

int main (int ac, char **av)
{

    if (ac == 3)
    {
        inter(av[1],av[2]);
    }
    write (1,"\n",1);
    return 0;
}

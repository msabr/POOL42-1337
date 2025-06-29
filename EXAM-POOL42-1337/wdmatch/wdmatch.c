/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:11:15 by msabr             #+#    #+#             */
/*   Updated: 2024/08/08 12:11:16 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int ft_strlen(char *str)
{
    int l = 0;
    while (str[l])
        l++;
    return (l);
}
int main (int argc,char **argv)
{
	int i = 0;
    int j = 0;
    

	if (argc != 3)
	{
		write(1,"\n",1);
		return 0;
	}
    char T[ft_strlen(argv[1])];
	while (argv[2][j])
	{
        if(argv[1][i] == argv[2][j])
        {
            T[i] = argv[1][i];
            i++;
            j++;
        }
        else
        {
            j++;
        }
	}
    j = 0;
    if (T[ft_strlen(argv[1]) - 1] == argv[1][ft_strlen(argv[1]) - 1])
    {
        while (argv[1][j])
        {
            write(1,&argv[1][j],1);
            j++;
        }
        
    }
	write (1,"\n",1);
	return 0;
}


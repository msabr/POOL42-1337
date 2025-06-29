/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:36:04 by msabr             #+#    #+#             */
/*   Updated: 2024/08/14 00:36:07 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

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

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int i = 0;
        int j = 0;
        while (av[2][j])
        {
            if (av[1][i] == av[2][j])
            {
                i++;
            }
            j++;
        }
        if (i == ft_strlen(av[1]))
            write(1,"1",1);
        else
            write(1,"0",1);
    }
    write(1,"\n",1);
    return 0;
}
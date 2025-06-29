/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:23:45 by msabr             #+#    #+#             */
/*   Updated: 2024/08/14 15:23:47 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_atoi (char *str)
{
	int i = 0;
	int res = 0;
	int signe = 1;

	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0') && (str[i]<='9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signe);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

void ft_putstr(char *str)
{
    int i = 0;

    while (str[i])
    {
        write(1,&str[i],1);
        i++;
    }
}

int main (int ac, char **av)
{
    if (ac == 2)
    {
        int nb = ft_atoi(av[1]);
        int i = 1;
        while (i < 10)
        {
            ft_putnbr(nb);
            ft_putstr(" x ");
            ft_putnbr(i);
            ft_putstr(" = ");
            ft_putnbr(nb * i);
            ft_putstr("\n");
            i++; 
        }

    }
    else
    {
        write(1,"\n",1);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:12:44 by msabr             #+#    #+#             */
/*   Updated: 2024/08/14 23:47:02 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int	ft_is_prime(int nb)
{
	int		n;

	n = 2;
	if (nb > 1)
	{
		while (n < (nb / 2))
		{
			if ((nb % n) == 0)
				return (0);
			n++;
		}
		return (1);
	}
	return (0);
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

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] && str[i] == ' ')
	{
		i++;
	}
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + (str[i] - '0');
		}
		else
		{
			break;
		}
		i++;
	}
	nb = nb * sign;
	return (nb);
}

int main (int ac, char **av)
{
    if (ac == 2)
    {
        int nb = ft_atoi(av[1]);
        int i = 2;

        while (nb != 1)
        {
            if (ft_is_prime(nb))
            {
                ft_putnbr(nb);
                break;
            }
            if ((nb % i == 0) && ft_is_prime(i))
            {
                ft_putnbr(i);
                nb = nb / i;
                if (nb != 1)
                    ft_putstr("*");
            }
                i++;
        }
    }
    else
        ft_putstr("\n");
    return (0);
}

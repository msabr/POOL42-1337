/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:21:51 by msabr             #+#    #+#             */
/*   Updated: 2024/08/04 00:39:31 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *src)
{
	int	l;

	l = 0;
	while (src[l] != '\0')
	{
		l++;
	}
	return (l);
}

int	error(char *base)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
	{
		return (0);
	}
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 13)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		lenbase;
	long	n;

	n = nbr;
	lenbase = ft_strlen(base);
	if (error(base) == 1)
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= lenbase)
		{
			ft_putnbr_base(n / lenbase, base);
			ft_putnbr_base(n % lenbase, base);
		}
		else
			ft_putchar(base[n]);
	}
	return ;
}

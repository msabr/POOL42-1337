/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 02:32:54 by msabr             #+#    #+#             */
/*   Updated: 2024/08/07 02:32:57 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int	check_index(char car, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == car)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_2(char *str, char *base1)
{
	int		lenbase;
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	lenbase = ft_strlen(base1);
	while ((str[i]) && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (check_index(str[i], base1) != -1))
	{
		nb = nb * lenbase + check_index(str[i], base1);
		i++;
	}
	return (nb * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int		nbr;

	nbr = 0;
	if (error(base) == 1)
	{
		nbr = ft_atoi_2(str, base);
	}
	return (nbr);
}

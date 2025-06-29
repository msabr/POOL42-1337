/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:58:14 by msabr             #+#    #+#             */
/*   Updated: 2025/06/29 06:06:43 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
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

int	ft_atoi2(char *str, char *base)
{
	int		lenbase;
	int		i;
	int		sign;
	int		nb;

	i = 0;
	sign = 1;
	nb = 0;
	lenbase = ft_strlen(base);
	while ((str[i]) && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (check_index(str[i], base) != -1))
	{
		nb = nb * lenbase + check_index(str[i], base);
		i++;
	}
	return (nb * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int		nbr;

	nbr = 0;
	if (error(base) == 1)
		nbr = ft_atoi2(str, base);
	return (nbr);
}

// int		main(void)
// {
// 	printf("%d\n", ft_atoi_base("-123456s4566", "0123456789"));
// 	fflush(stdout);
// 	printf("%d\n", ft_atoi_base("11119000100100000", "01"));
// 	fflush(stdout);
// 	printf("%d\n", ft_atoi_base("-1a240", "0123456789abcdef"));
// 	fflush(stdout);
// }

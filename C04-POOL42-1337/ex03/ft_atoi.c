/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:46:00 by msabr             #+#    #+#             */
/*   Updated: 2024/08/04 16:42:08 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\r')
		|| (str[i] == '\v') || (str[i] == ' ') || (str[i] == '\f'))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = nb * sign;
	return (nb);
}

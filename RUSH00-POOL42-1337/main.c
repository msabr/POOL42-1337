/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:36:15 by msabr             #+#    #+#             */
/*   Updated: 2024/07/28 20:11:19 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int colone, int line);

int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str >= 9 && 13 >= *str)
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign *= -1;
			str++;
		}
	}
	while (*str && *str >= '0' && '9' >= *str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	main(int ac, char **av)
{
	int	x;
	int	y;

	if (ac == 3)
	{
		x = ft_atoi(av[1]);
		y = ft_atoi(av[2]);
		if (x >= -2147483648 && x <= 2147483647)
		{
			if (y >= -2147483648 && y <= 2147483647)
			{
				rush (x, y);
			}
			else
			{
				return (0);
			}
		}
		else
		{
			return (0);
		}
	}
}

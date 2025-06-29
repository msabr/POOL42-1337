/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:51:19 by msabr             #+#    #+#             */
/*   Updated: 2024/08/01 16:51:41 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

int	ft_atoi(const char *str)
{
	int	i = 0;
	int	neg_flag = 0;
	int	result = 0;

	while (str[i])
	{
		result *= 10; 
		if (str[i] == '-' && !(neg_flag))
			neg_flag = 1;
		if (str[i] >= '0' && str[i] <= '9') 
            result += str[i] - '0';
		i++;
	}
	if (neg_flag)
		return (result * -1);
	return (result);
}
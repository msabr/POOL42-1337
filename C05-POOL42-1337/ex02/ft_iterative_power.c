/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 01:53:52 by msabr             #+#    #+#             */
/*   Updated: 2024/08/04 02:21:24 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int		i;
	int		pow;

	if (power < 0)
		return (0);
	i = 0;
	pow = 1;
	while (i < power)
	{
		pow = pow * nb;
		i++;
	}
	return (pow);
}

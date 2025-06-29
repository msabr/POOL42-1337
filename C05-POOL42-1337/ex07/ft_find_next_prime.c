/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:58:16 by msabr             #+#    #+#             */
/*   Updated: 2024/08/06 15:03:24 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:50:38 by msabr             #+#    #+#             */
/*   Updated: 2024/07/25 12:08:22 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int i, int j, int k)
{
	ft_putchar(i);
	ft_putchar(j);
	ft_putchar(k);
	if (i != '7' || j != '8' || k != '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;

	i = '0';
	j = '1';
	k = '2';
	while (i <= '7' )
	{
		while (j <= '8')
		{
			while (k <= '9')
			{
				if (i != j && j != k && i != k)
				{
					ft_print(i, j, k);
				}
				k++;
			}
			k = ++j + 1;
		}
		j = ++i ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:58:16 by msabr             #+#    #+#             */
/*   Updated: 2025/07/29 19:19:18 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_aid(char *bord, int nbr, int *total)
{
	int	i;
	int	j;

	if (nbr == 10)
	{
		nbr = 0;
		while (nbr < 10)
			ft_putchar(bord[nbr++] + '0');
		ft_putchar('\n');
		(*total)++;
		return ;
	}
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < nbr && i != bord[j] && ft_abs(bord[j] - i) != nbr - j)
			j++;
		if (j >= nbr)
		{
			bord[nbr] = i;
			ft_aid(bord, nbr + 1, total);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		nbr;
	char	bord[10];
	int		total;

	nbr = 0;
	total = 0;
	ft_aid(bord, nbr, &total);
	return (total);
}

// int	main(void)
// {
// 	int	total;

// 	total = ft_ten_queens_puzzle();
// 	write(1, "Total solutions: ", 17);
// 	if (total < 10)
// 		ft_putchar(total + '0');
// 	else
// 	{
// 		ft_putchar(total / 10 + '0');
// 		ft_putchar(total % 10 + '0');
// 	}
// 	ft_putchar('\n');
// 	return (0);
// }

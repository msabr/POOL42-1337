/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:08:24 by msabr             #+#    #+#             */
/*   Updated: 2025/06/29 06:15:57 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int colone, int line)
{
	int	l;
	int	c;

	l = 1;
	while (l <= line)
	{
		c = 1;
		while (c <= colone)
		{
			if ((l == 1 && c == 1) || (l == line && c == 1))
				ft_putchar('A');
			else if ((l == 1 && c == colone) || (l == line && c == colone))
				ft_putchar('C');
			else if (l == 1 || l == line || c == 1 || c == colone)
				ft_putchar('B');
			else
				ft_putchar(' ');
			c++;
		}
		l++;
		ft_putchar('\n');
	}
}

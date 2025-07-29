/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_print_combn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:39:42 by msabr             #+#    #+#             */
/*   Updated: 2025/07/29 18:51:14 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];
	int	i;
	int	j;

	if (n <= 0 || n >= 10)
		return ;
	i = -1;
	while (i++ < n)
		arr[i] = i;
	while (1)
	{
		print_number(arr, n);
		if (arr[0] == 10 - n)
			break ;
		ft_putchar(',');
		ft_putchar(' ');
		i = n - 1;
		while (i >= 0 && arr[i] == 9 - (n - 1 - i))
			i--;
		arr[i]++;
		j = i;
		while (j++ < n)
			arr[j] = arr[j - 1] + 1;
	}
}

// int main(void)
// {
// 	ft_print_combn(3);
// 	return (0);
// }

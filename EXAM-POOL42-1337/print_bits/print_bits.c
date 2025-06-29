/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:59:18 by msabr             #+#    #+#             */
/*   Updated: 2025/03/18 10:16:16 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int divide;
	int oct;

	oct = octet; 
	divide = 128;
	while (divide)
	{
		if (divide <= oct)
		{
			write(1, "1", 1);
			oct %= divide;
		}
		else
			write(1, "0", 1);
		divide /= 2;
	}
}
int	main(void)
{
	print_bits(15);
	write(1, "\n", 1);
	return (0);
}

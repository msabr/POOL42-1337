/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:59:52 by msabr             #+#    #+#             */
/*   Updated: 2024/08/05 21:59:57 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	to_hexa(unsigned char n)
{
	char	*p;

	p = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &p[n / 16], 1);
	write(1, &p[n % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			to_hexa(str[i]);
		i++;
	}
}

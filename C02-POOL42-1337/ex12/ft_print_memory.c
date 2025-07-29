/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:58:16 by msabr             #+#    #+#             */
/*   Updated: 2025/07/29 19:19:50 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_hex(unsigned long n, int digits)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (digits > 1)
		ft_putnbr_hex(n / 16, digits - 1);
	ft_putchar(hex[n % 16]);
}

void	ft_print_hex_content(unsigned char *ptr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			ft_putnbr_hex(ptr[i], 2);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void	ft_print_ascii(unsigned char *ptr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (ptr[i] >= 32 && ptr[i] <= 126)
			ft_putchar(ptr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;
	unsigned int	line_size;

	if (size == 0)
		return (addr);
	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ft_putnbr_hex((unsigned long)(ptr + i), 16);
		ft_putchar(':');
		ft_putchar(' ');
		if (size - i >= 16)
			line_size = 16;
		else
			line_size = size - i;
		ft_print_hex_content(ptr + i, line_size);
		ft_print_ascii(ptr + i, line_size);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}

// int	main(void)
// {
// 	char	str[] = "Bonjour les aminches\t\n\tc'est fou\ttout ce qu'on \
// peut faire avec.\n\tprint_memory\n\tlol.lol\n \0";
// 	ft_print_memory(str, sizeof(str));
// 	return (0);
// }

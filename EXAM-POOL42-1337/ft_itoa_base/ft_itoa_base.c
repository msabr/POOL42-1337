/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:07:29 by msabr             #+#    #+#             */
/*   Updated: 2024/08/14 21:07:31 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int		l;

	l = 0;
	while (str[l] != '\0')
	{
		l++;
	}
	return (l);
}

int	len(long nb, int base)
{
	int	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return(len);
}

int check_index (char c)
{
    char    *strbae1 = "0123456789abcdef";
    char    *strbae2 = "0123456789ABCDEF";
    int     i = 0;
    while (strbae1[i])
    {
        if (c == strbae1[i] || c == strbae2[i])
        {
            return (i);
        }
    }
    return (-1);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	long	n;
	int     i;
    

	n = value;
	i = len(n,base);
	if(!(str = (char *)malloc(i + 1)))
		return(0);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return(str);
	}
	if(n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
    while (check_index(n))
	{
		str[i] = 48 + (n % base);
		n /= base;
		i--;
	}
	return (str);
}

int	main(void)
{
    int n = 1342345;
    int base = 10;
	printf("%s\n",ft_itoa_base(n,10));
}
